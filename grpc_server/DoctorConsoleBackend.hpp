#pragma once

#include "DoctorConsoleService.grpc.pb.h"

using namespace doctor_console;

class DoctorConsoleBackend final : public DoctorConsoleService::Service
{
public:
    DoctorConsoleBackend();

private:
    grpc::Status GetSettings(grpc::ServerContext *, const Empty *request, Settings *response) override;
    grpc::Status SetSettings(grpc::ServerContext *, const Settings *request, Empty *response) override;
    grpc::Status GetUser(grpc::ServerContext *, const Empty *request, User *response) override;
    grpc::Status EyeCalibration(grpc::ServerContext *, const Empty *request, Empty *response) override;
    grpc::Status Login(grpc::ServerContext *, const Credentials *request, User *response) override;
    grpc::Status Logout(grpc::ServerContext *, const Empty *request, Empty *response) override;

    Settings m_settings;
    User m_user;
};