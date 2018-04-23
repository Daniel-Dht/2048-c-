import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    id: window
    visible: true
    width: 800
    height: 500
    color: "#FAF6F1"
    title: "2048"

    Grid{
        id: grid
        y: 10
        x: 10
        columns : 2
        spacing : 30

        Grid {
            y: 10
            x: 10
            rows: 4
            columns: 4
            spacing: 10


            Repeater {
                model: vueObjetCpp.readNb
                delegate: Rectangle {
                    radius: 10
                    width: 110
                    height: 110
                    color: vueObjetCpp.changement_couleur[index]
                    objectName: "case%1".arg(index)

                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        text: vueObjetCpp.changement_valeur[index]
                        font.pointSize: 50
                    }

                    // gestionnaire d'evenement en fonction des touches
                    Keys.onPressed: {
                        switch(event.key){
                        case Qt.Key_Up:
                            vueObjetCpp.changement("haut");
                            break;
                        case Qt.Key_Down:
                            vueObjetCpp.changement("bas");
                            break;
                        case Qt.Key_Left:
                            vueObjetCpp.changement("gauche");
                            break;
                        case Qt.Key_Right:
                            vueObjetCpp.changement("droite");
                            break;
                        case Qt.Key_R:
                            vueObjetCpp.changement("undo");
                            break;
                        case Qt.Key_N:
                            vueObjetCpp.changement("new");
                            break;
                        }
                    }

                    // permet d'autoriser les modifs
                    focus:true
                }
            }
        }

        Text {
            width: 100
            height: 20
            text: vueObjetCpp.readName + " your score is : " + vueObjetCpp.changement_score
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: -595
            font.pointSize: 20

        }

        Rectangle {
            id: rectangleUndo
            width: 120
            height: 30
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: 490
            color : "#A27065"
            radius : 10

            Text{
                text : "Press R to Undo"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle {
            id: rectanglenewgame
            width: 145
            height: 30
            color: "#a27065"
            radius: 10
            Text {
                text: "Press N to New game"
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.leftMargin: 490
            anchors.topMargin: 100
        }
    }

    Rectangle {
        id: rectangle_defaite
        x: 124
        y: 150
        width: 567
        height: 200
        opacity: 0
        color: "#ffffff"
        radius: 20
        border.color: "#A27065"
        border.width: 5
        Text{
            text : "☹ You loose ☹"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 60
        }
    }
}
