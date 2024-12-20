import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Controls.Material
import QtGrpc

import doctor_console

ApplicationWindow {
    id: root
    width: 350
    height: 950

    minimumWidth: width
    minimumHeight: height

    visible: true
    title: qsTr("Grpc Client")
    Material.theme: Material.Light

    property empty _empty
    property clientToken _clientToken
    property settings _settings
    property user _user
    property credentials _credentials
    property changes _changes

    property var clientTokenResponse: function (value) {
        console.timeEnd("getCT")
        _clientToken = value
        console.log("registered: ", _clientToken)
    }

    property var settingResponse: function (value) {
        console.timeEnd("getS")
        _settings = value
        language.text = _settings.language
        theme.text = _settings.theme
        eyeControl.checked = _settings.eyeControlEnabled
    }

    property var userResponse: function (value) {
        console.timeEnd("getU")
        _user = value
        authenticated.checked = _user.authenticated
        userId.text = _user.idString
        name.text = _user.name
    }

    property var changeResponse: function (value) {
        _changes = value
        console.log(_changes.settings)
    }

    property var finishResponse: function (value) {
        console.log("finished: ", value)
    }

    property var errorCallback: function (e) {
        console.log("Error: ", e);
    }

    ColumnLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10

        Text {
            text: qsTr("UUID: ") + _clientToken.uuid
            font.bold: true
        }

        Text {
            text: qsTr("Settings")
            font.bold: true
        }

        TextField {
            id: language
            placeholderText: "Language"
        }

        TextField {
            id: theme
            placeholderText: "Theme"
        }

        CheckBox {
            id: eyeControl
            text: "Eye Control"
        }

        Button{
            text: qsTr("Get")
            onClicked: root.getSettings()
        }

        Button{
            text: qsTr("Set")
            onClicked: root.setSettings()
        }

        Text {
            text: qsTr("User")
            font.bold: true
        }

        CheckBox {
            id: authenticated
            enabled: false
        }

        Text {
            id: userId
            text: "User Id"
        }

        Text {
            id: name
            text: "Name"
        }

        Button{
            text: qsTr("Get")
            onClicked: root.getUser()
        }

        TextField {
            id: username
            placeholderText: "Username"
            onTextEdited: {
                root._credentials.username = text
            }
        }

        TextField {
            id: password
            placeholderText: "Password"
            onTextEdited: {
                root._credentials.password = text
            }
        }

        Button{
            text: qsTr("Login")
            onClicked: root.login()
        }

        Button{
            text: qsTr("Logout")
            onClicked: root.logout()
        }

        Button{
            text: qsTr("Start Eye Calibration")
            onClicked: root.startEyeCalibration()
        }

        Button{
            text: qsTr("Stop Eye Calibration")
            onClicked: root.stopEyeCalibration()
        }

        Button{
            text: qsTr("Subscribe")
            onClicked: root.subscribe()
        }

    }

    function setSettings() {
        console.log("Set")
        _settings.token = _clientToken
        _settings.theme = theme.text
        _settings.language = language.text
        _settings.eyeControlEnabled = eyeControl.checked
        grpcClient.setSettings(_settings, _empty, errorCallback)
    }

    function getSettings() {
        console.log("Get")
        console.time("getS")
        grpcClient.getSettings(_empty, settingResponse, errorCallback)
    }

    function getUser() {
        console.log("Get")
        console.time("getU")
        grpcClient.getUser(_empty, userResponse, errorCallback)
    }

    function login() {
        console.time("getU")
        _credentials.token = _clientToken
        grpcClient.login(_credentials, userResponse, errorCallback)
    }

    function logout() {
        console.time("getU")
        grpcClient.logout(_clientToken, userResponse, errorCallback)
    }

    function startEyeCalibration() {
        grpcClient.startEyeCalibration(_clientToken, _empty, errorCallback)
    }

    function stopEyeCalibration() {
        grpcClient.stopEyeCalibration(_clientToken, _empty, errorCallback)
    }

    function subscribe() {
        grpcClient.subscribe(_clientToken, changeResponse, finishResponse, errorCallback)
    }

    DoctorConsoleServiceClient {
        id: grpcClient
        channel: grpcChannel.channel
    }

    GrpcHttp2Channel {
        id: grpcChannel
        hostUri: "http://localhost:50051"
        options: GrpcChannelOptions {}
    }

    Component.onCompleted: {
        console.time("getCT")
        grpcClient.registerMe(_empty, clientTokenResponse, errorCallback)
    }
}
