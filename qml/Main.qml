import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Material
import QtGrpc

import GrpcUi

ApplicationWindow {
    id: root
    width: 665
    height: width

    minimumWidth: width
    minimumHeight: height

    visible: true
    title: qsTr("Grpc Client")
    Material.theme: Material.Light

    GrpcHttp2Channel {
        id: grpcChannel
        hostUri: "http://localhost:50051"
        options: GrpcChannelOptions {}
    }
}
