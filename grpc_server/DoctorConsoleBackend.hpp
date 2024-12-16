#pragma once

#include <shared_mutex>

#include "DoctorConsoleService.grpc.pb.h"

using namespace doctor_console;

class DoctorConsoleBackend final : public DoctorConsoleService::Service
{
public:
    DoctorConsoleBackend();

private:
    grpc::Status getSettings(grpc::ServerContext *, const Empty *request, Settings *response) override;
    grpc::Status setSettings(grpc::ServerContext *, const Settings *request, Empty *response) override;
    grpc::Status getUser(grpc::ServerContext *, const Empty *request, User *response) override;
    grpc::Status eyeCalibration(grpc::ServerContext *, const Empty *request, Empty *response) override;
    grpc::Status login(grpc::ServerContext *, const Credentials *request, User *response) override;
    grpc::Status logout(grpc::ServerContext *, const Empty *request, User *response) override;

    Settings m_settings;
    User m_user;

    std::shared_mutex m_settingsMutex;
    std::shared_mutex m_userMutex;
};