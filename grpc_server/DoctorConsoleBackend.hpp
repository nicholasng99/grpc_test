#pragma once

#include <shared_mutex>

#include "DoctorConsoleService.grpc.pb.h"

namespace dc = doctor_console;

class DoctorConsoleBackend final : public dc::DoctorConsoleService::Service
{
public:
    DoctorConsoleBackend();

private:
    grpc::Status registerMe(grpc::ServerContext *, const dc::Empty *request, dc::ClientToken *response) override;
    grpc::Status getSettings(grpc::ServerContext *, const dc::Empty *request, dc::Settings *response) override;
    grpc::Status setSettings(grpc::ServerContext *, const dc::Settings *request, dc::Empty *response) override;
    grpc::Status getUser(grpc::ServerContext *, const dc::Empty *request, dc::User *response) override;
    grpc::Status getStatus(grpc::ServerContext *, const dc::Empty *request, dc::Status *response) override;
    grpc::Status setStatus(grpc::ServerContext *, const dc::Status *request, dc::Empty *response) override;
    grpc::Status login(grpc::ServerContext *, const dc::Credentials *request, dc::User *response) override;
    grpc::Status logout(grpc::ServerContext *, const dc::ClientToken *request, dc::User *response) override;
    grpc::Status subscribe(grpc::ServerContext *, const dc::ClientToken *request, grpc::ServerWriter<dc::Changes> *writer) override;

    void pushChanges(const std::string &uuid, const dc::Changes &changes);

    dc::Settings m_settings;
    dc::User m_user;
    dc::Status m_status;

    std::shared_mutex m_settingsMutex;
    std::shared_mutex m_userMutex;
    std::shared_mutex m_statusMutex;
    std::unordered_set<std::string> m_clientIds;
    std::map<std::string, grpc::ServerWriter<dc::Changes> *> m_subscriptions;
};