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
    m_user.set_id("-1");
    m_user.set_name("");
}

Status DoctorConsoleBackend::GetSettings(grpc::ServerContext *, const Empty *request, Settings *response)
{
    *response = m_settings;
    return Status();
}

Status DoctorConsoleBackend::SetSettings(grpc::ServerContext *, const Settings *request, Empty *response)
{
    if (request->has_language())
        m_settings.set_language(request->language());
    if (request->has_theme())
        m_settings.set_theme(request->theme());
    if (request->has_eye_control_enabled())
        m_settings.set_eye_control_enabled(request->eye_control_enabled());
    return Status();
}

Status DoctorConsoleBackend::GetUser(grpc::ServerContext *, const Empty *request, User *response)
{
    *response = m_user;
    return Status();
}

Status DoctorConsoleBackend::EyeCalibration(grpc::ServerContext *, const Empty *request, Empty *response)
{
    std::cout << "Eye calibration called!" << std::endl;
    return Status();
}

Status DoctorConsoleBackend::Login(grpc::ServerContext *, const Credentials *request, User *response)
{
    if (request->username() == "admin" && request->password() == "admin")
    {
        m_user.set_id("0");
        m_user.set_name(request->username());
        m_user.set_authenticated(true);
        std::cout << "Admin logged in!" << std::endl;
    }
    return Status();
}

Status DoctorConsoleBackend::Logout(grpc::ServerContext *, const Empty *request, Empty *response)
{
    std::cout << "Logout called!" << std::endl;
    return Status();
}