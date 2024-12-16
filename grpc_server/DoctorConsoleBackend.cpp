#include "DoctorConsoleBackend.hpp"

using namespace grpc;

DoctorConsoleBackend::DoctorConsoleBackend()
    : m_settings(Settings()),
      m_user(User())
{
    m_settings.set_language("English");
    m_settings.set_theme("Dark");
    m_settings.set_eye_control_enabled(false);

    m_user.set_authenticated(false);
    m_user.set_id_string("-1");
    m_user.set_name("");
}

Status DoctorConsoleBackend::getSettings(grpc::ServerContext *, const Empty *request, Settings *response)
{
    std::shared_lock<std::shared_mutex> lock(m_settingsMutex);
    std::cout << "get Settings" << std::endl;
    *response = m_settings;
    return Status();
}

Status DoctorConsoleBackend::setSettings(grpc::ServerContext *, const Settings *request, Empty *response)
{
    std::unique_lock<std::shared_mutex> lock(m_settingsMutex);
    std::cout << "set Settings" << std::endl;
    if (request->has_language())
        m_settings.set_language(request->language());
    if (request->has_theme())
        m_settings.set_theme(request->theme());
    if (request->has_eye_control_enabled())
        m_settings.set_eye_control_enabled(request->eye_control_enabled());
    return Status();
}

Status DoctorConsoleBackend::getUser(grpc::ServerContext *, const Empty *request, User *response)
{
    std::shared_lock<std::shared_mutex> lock(m_userMutex);
    std::cout << "get User" << std::endl;
    *response = m_user;
    return Status();
}

Status DoctorConsoleBackend::eyeCalibration(grpc::ServerContext *, const Empty *request, Empty *response)
{
    std::cout << "Eye calibration called!" << std::endl;
    return Status();
}

Status DoctorConsoleBackend::login(grpc::ServerContext *, const Credentials *request, User *response)
{
    std::unique_lock<std::shared_mutex> lock(m_userMutex);
    std::cout << "Login attempt: " << request->username() << " - " << request->password() << std::endl;
    if (request->username() == "admin" && request->password() == "admin")
    {
        m_user.set_id_string("0");
        m_user.set_name(request->username());
        m_user.set_authenticated(true);
        *response = m_user;
        std::cout << "Admin logged in!" << std::endl;
    }
    return Status();
}

Status DoctorConsoleBackend::logout(grpc::ServerContext *, const Empty *request, User *response)
{
    std::unique_lock<std::shared_mutex> lock(m_userMutex);
    std::cout << "Logout called!" << std::endl;
    m_user.set_authenticated(false);
    m_user.set_id_string("-1");
    m_user.set_name("");
    *response = m_user;
    return Status();
}