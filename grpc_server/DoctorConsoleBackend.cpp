#include "DoctorConsoleBackend.hpp"

using namespace grpc;

DoctorConsoleBackend::DoctorConsoleBackend()
    : m_settings(dc::Settings()),
      m_user(dc::User()),
      m_status(dc::Status())
{
    m_settings.set_language("English");
    m_settings.set_theme("Dark");
    m_settings.set_eye_control_enabled(false);

    m_user.set_authenticated(false);
    m_user.set_id_string("-1");
    m_user.set_name("");

    m_status.set_state(dc::Status_State::Status_State_NORMAL);
}

Status DoctorConsoleBackend::registerMe(ServerContext *, const dc::Empty *request, dc::ClientToken *response)
{
    static int counter = 0;
    const std::string uuid = std::to_string(counter++);
    std::cout << "client registered: " << uuid << std::endl;
    m_clientIds.insert(uuid);
    response->set_uuid(uuid);
    return Status();
}

Status DoctorConsoleBackend::getSettings(ServerContext *, const dc::Empty *request, dc::Settings *response)
{
    std::cout << "get Settings" << std::endl;
    std::shared_lock<std::shared_mutex> lock(m_settingsMutex);
    *response = m_settings;
    return Status();
}

Status DoctorConsoleBackend::setSettings(ServerContext *, const dc::Settings *request, dc::Empty *response)
{
    if (!request->has_token())
        return Status(StatusCode::INVALID_ARGUMENT, "Set settings requires ClientToken");
    if (m_clientIds.count(request->token().uuid()) < 1)
        return Status(StatusCode::PERMISSION_DENIED, "Invalid ClientToken, use the token obtained from registerMe()");
    std::cout << "set Settings from: " << request->token().uuid() << std::endl;
    std::unique_lock<std::shared_mutex> lock(m_settingsMutex);
    if (request->has_language())
        m_settings.set_language(request->language());
    if (request->has_theme())
        m_settings.set_theme(request->theme());
    if (request->has_eye_control_enabled())
        m_settings.set_eye_control_enabled(request->eye_control_enabled());

    dc::Changes changes;
    changes.set_allocated_settings(new dc::Settings(*request));
    pushChanges(request->token().uuid(), changes);
    return Status();
}

Status DoctorConsoleBackend::getUser(ServerContext *, const dc::Empty *request, dc::User *response)
{
    std::cout << "get User" << std::endl;
    std::shared_lock<std::shared_mutex> lock(m_userMutex);
    *response = m_user;
    return Status();
}

Status DoctorConsoleBackend::getStatus(ServerContext *, const dc::Empty *request, dc::Status *response)
{
    std::cout << "get User" << std::endl;
    std::shared_lock<std::shared_mutex> lock(m_statusMutex);
    *response = m_status;
    return Status();
}

Status DoctorConsoleBackend::setStatus(ServerContext *, const dc::Status *request, dc::Empty *response)
{
    if (!request->has_token())
        return Status(StatusCode::INVALID_ARGUMENT, "Set status requires ClientToken");
    if (m_clientIds.count(request->token().uuid()) < 1)
        return Status(StatusCode::PERMISSION_DENIED, "Invalid ClientToken, use the token obtained from registerMe()");

    std::cout << "State set from: " << request->token().uuid() << std::endl;
    m_status.set_state(request->state());

    dc::Changes changes;
    changes.set_allocated_status(new dc::Status(*request));
    pushChanges(request->token().uuid(), changes);
    return Status();
}

Status DoctorConsoleBackend::login(ServerContext *, const dc::Credentials *request, dc::User *response)
{
    if (m_clientIds.count(request->token().uuid()) < 1)
        return Status(StatusCode::PERMISSION_DENIED, "Invalid ClientToken, use the token obtained from registerMe()");

    std::cout << "Login attempt: " << request->username() << " - " << request->password() << " from: " << request->token().uuid() << std::endl;
    std::unique_lock<std::shared_mutex> lock(m_userMutex);
    if (request->username() == "admin" && request->password() == "admin")
    {
        m_user.set_id_string("0");
        m_user.set_name(request->username());
        m_user.set_authenticated(true);
        *response = m_user;
        std::cout << "Admin logged in!" << std::endl;
    }

    dc::Changes changes;
    changes.set_allocated_user(new dc::User(*response));
    pushChanges(request->token().uuid(), changes);
    return Status();
}

Status DoctorConsoleBackend::logout(ServerContext *, const dc::ClientToken *request, dc::User *response)
{
    if (m_clientIds.count(request->uuid()) < 1)
        return Status(StatusCode::PERMISSION_DENIED, "Invalid ClientToken, use the token obtained from registerMe()");

    std::cout << "Logout called from: " << request->uuid() << std::endl;
    std::unique_lock<std::shared_mutex> lock(m_userMutex);
    m_user.set_authenticated(false);
    m_user.set_id_string("-1");
    m_user.set_name("");
    *response = m_user;

    dc::Changes changes;
    changes.set_allocated_user(new dc::User(*response));
    pushChanges(request->uuid(), changes);
    return Status();
}

Status DoctorConsoleBackend::subscribe(ServerContext *context, const dc::ClientToken *request, ServerWriter<dc::Changes> *writer)
{
    if (m_clientIds.count(request->uuid()) < 1)
        return Status(StatusCode::PERMISSION_DENIED, "Invalid ClientToken, use the token obtained from registerMe()");
    if (m_subscriptions.count(request->uuid()))
        return Status(StatusCode::ALREADY_EXISTS, "ClientToken already has an existing connection");

    std::cout << "new subscription: " << request->uuid() << std::endl;
    m_subscriptions[request->uuid()] = writer;

    while (!context->IsCancelled())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "looping for " << request->uuid() << std::endl;
    }

    m_subscriptions.erase(request->uuid());
    return Status();
}

void DoctorConsoleBackend::pushChanges(const std::string &uuid, const dc::Changes &changes)
{
    for (auto [id, writer] : m_subscriptions)
    {
        if (id == uuid)
            continue;
        writer->Write(changes);
    }
}
