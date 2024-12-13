#include "ServerRunner.hpp"

#include <QCoreApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto server = std::make_unique<ExampleServer>();
    server->run();
    return a.exec();
}
