#include "ServerRunner.hpp"

#include "DoctorConsoleBackend.hpp"

#include <QThread>
#include <QDebug>

#include <grpc++/grpc++.h>
#include <memory>

using grpc::Server;
using grpc::ServerBuilder;

void ExampleServer::run()
{
    std::string serverUri("0.0.0.0:50051");
    DoctorConsoleBackend service;

    ServerBuilder builder;
    builder.AddListeningPort(serverUri, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    if (!server)
    {
        qDebug() << "Creating grpc::Server failed.";
        return;
    }

    qDebug() << "Server listening on " << serverUri;
    server->Wait();
}
