import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
Rectangle {
    id:rect1
    width: parent.width / parent.columns - grid.spacing
    height: parent.height / parent.rows - grid.spacing
    color: "#f6f6f6"
    radius: 8
    border.color: "#fcb1b1"
    border.width: 4
    property bool isPlayed: false
    property int cellRow: index / grid.rows
    property int cellColumn:  index % grid.columns
    
    Connections {
        target: rectangle1
        onTrigger: {
            print("Componet");
            print(rect1.cellRow);
            print(rect1.cellColumn);
        }
    }
    
    MouseArea {
        hoverEnabled: true
        anchors.fill: parent
        onClicked: {
            if(!rect1.isPlayed){
                //console.log(repeater1.itemAt(index))
                image.source = "../../../../Downloads/circle-doodle-by-Vexels.svg";
                rect1.isPlayed=  true;
                rectangle1.trigger()
            }
            
        }
        
    }
    
    Item {
        
        anchors.fill: parent
        Image {
            id: image
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }
    }
    
    
}
