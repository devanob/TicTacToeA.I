import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0




Rectangle {
    id: rectangle
    height: 56
    color: "#ffffff"
    anchors.top: rectangle1.bottom
    anchors.topMargin: -50
    anchors.right: parent.right
    anchors.rightMargin: 0
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 0


    Row {
        id: row
        width: 250
        height: 56
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.top: parent.top
        spacing: 5

        Button {
            id: button
            text: qsTr("Reset")
            font.weight: Font.ExtraBold
            focusPolicy: Qt.NoFocus
            autoRepeat: false
            display: AbstractButton.TextBesideIcon
            checkable: false
            font.capitalization: Font.AllUppercase
            font.bold: false
            font.underline: false
            font.family: "Tahoma"
            spacing: 0
            clip: true
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                TicTacToaController.reset();
            }
        }

        Label {
            id: label_row
            text: qsTr("BoardSize:")
            anchors.verticalCenter: parent.verticalCenter
        }

        ColumnLayout {
            id: columnLayout
            width: 100
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0


            SpinBox {
                id: spinBox
                from: 3
                value: TicTacToaController.gridCount
                spacing: -6
                to: 10
                onValueChanged: {
                    TicTacToaController.gridCount = parseInt(value)


                }
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBaseline
                Layout.fillWidth: true
            }
        }




    }




}

































/*##^## Designer {
    D{i:0;width:640}D{i:5;anchors_x:250}D{i:4;anchors_x:250}
}
 ##^##*/
