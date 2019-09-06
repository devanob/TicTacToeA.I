import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtGraphicalEffects 1.0

Window {
    id: window
    visible: true
    width: 800
    height: 800
    color: "#7ae6f3"
    opacity: 1
    title: qsTr("A.I Tic Tac Toe")
    Rectangle {
        id: rectangle1
        radius: 3
        rotation: 0
        scale: 0.8
        transformOrigin: Item.Center
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 80
        anchors.top: parent.top
        anchors.topMargin: -19
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.right: parent.right
        anchors.rightMargin: 50
        border.width: 0
        border.color: "#fc8888"
        //Signal
        signal trigger
        height: 500
        color: "#66ee5454"
        Grid {
            id: grid
            anchors.fill: parent
            flow: Grid.LeftToRight
            layoutDirection: Qt.LeftToRight

            rows: TicTacToaController.gridCount;
            columns: TicTacToaController.gridCount;
            spacing: 5

            Repeater {   model: grid.rows * grid.columns
                id:repeater1
                Rectangle {
                    id:rect1
                    width: parent.width / parent.columns - grid.spacing
                    height: parent.height / parent.rows - grid.spacing
                    color: "#efecec"
                    radius: 8
                    border.color: "#fcb1b1"
                    border.width: 4
                    property bool isPlayed: false
                    property int cellRow: index / grid.rows
                    property int cellColumn:  index % grid.columns

                    Connections {
                        target: rectangle1
                        onTrigger: {

                        }
                    }

                    MouseArea {
                        hoverEnabled: true
                        anchors.fill: parent
                        onClicked: {
                            if(!rect1.isPlayed && TicTacToaController.playLock){
                                //console.log(repeater1.itemAt(index))
                                if (TicTacToaController.playerSymbol ==='O'.charCodeAt(0)){

                                    image.source = "IMAGE/circle-doodle-by-Vexels.svg";
                                    //rect1.color = "blue";
                                }
                                else {
                                    image.source = "IMAGE/x-cross-scribble-by-Vexels.svg";
                                    //rect1.color= "red";
                                }
                                rect1.isPlayed=  true;
                                TicTacToaController.humanPlayerAt(rect1.cellRow, rect1.cellColumn);

                            }

                        }
                        Connections{
                            target: TicTacToaController
                            onAIplayer : {

                                if (rect1.cellRow == row && rect1.cellColumn == column && !rect1.isPlayed ){
                                    if (TicTacToaController.playerSymbol !=='O'.charCodeAt(0)){

                                        image.source = "IMAGE/circle-doodle-by-Vexels.svg";
                                        //rect1.color = "blue";
                                    }
                                    else {
                                        image.source = "IMAGE/x-cross-scribble-by-Vexels.svg";
                                        //rect1.color= "red";
                                    }
                                    rect1.isPlayed=  true;
                                }

                            }
                           onResetSignifier:{
                            rect1.isPlayed = false;
                            image.source ="";
                           }
                        }



                    }


                    Item {

                        anchors.fill: parent
                        Image {
                            id: image
                            anchors.fill: parent
                            fillMode: Image.PreserveAspectFit
                            asynchronous : false
                        }
                    }


                }
            }
        }
    }

    Menue {
        id: rectangle
    }









}













































































































































































































































































































/*##^## Designer {
    D{i:9;anchors_height:200;anchors_width:200;anchors_x:200;anchors_y:543}D{i:2;anchors_height:269;anchors_width:293;anchors_x:5;anchors_y:5}
D{i:1;anchors_height:500;anchors_width:500;anchors_x:0;anchors_y:0}D{i:10;anchors_width:428}
}
 ##^##*/
