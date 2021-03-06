import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 810
    height: 610
    color: "#000000"
    property alias score_finalText: score_final.text
    property alias elementText: phrase_accroche.text
    property alias score2Text: score2.text
    property alias text1Text: text1.text
    property alias text2Text: text2.text
    property alias text3Text: text3.text
    property alias text4Text: text4.text
    property alias text5Text: text5.text
    property alias text6Text: text6.text
    property alias text7Text: text7.text
    property alias text8Text: text8.text
    property alias text9Text: text9.text
    property alias text10Text: text10.text
    property alias text11Text: text11.text
    property alias text12Text: text12.text
    property alias text13Text: text13.text
    property alias text14Text: text14.text
    property alias text15Text: text15.text
    property alias text16Text: text16.text
    property alias rect1Color: rect1.color
    property alias rect2Color: rect2.color
    property alias rect3Color: rect3.color
    property alias rect4Color: rect4.color
    property alias rect5Color: rect5.color
    property alias rect6Color: rect6.color
    property alias rect7Color: rect7.color
    property alias rect8Color: rect8.color
    property alias rect9Color: rect9.color
    property alias rect10Color: rect10.color
    property alias rect11Color: rect11.color
    property alias rect12Color: rect12.color
    property alias rect13Color: rect13.color
    property alias rect14Color: rect14.color
    property alias rect15Color: rect15.color
    property alias rect16Color: rect16.color
    title: qsTr("2048")

    Rectangle {
        id: rect1
        width: 140
        height: 140
        color: mondamier.damier1colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10

        Text {
            id: text1
            focus: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 22
            text: mondamier.damier1QML //mondamier=vueObjetcpt
            Keys.onPressed: {
                switch (event.key) {
                    case Qt.Key_Left:
                        mondamier.gotoleft();
                        break;
                    case Qt.Key_Up:
                        mondamier.gotoup();
                        break;
                    case Qt.Key_Down:
                        mondamier.gotodown();
                        break;
                    case Qt.Key_Right:
                        mondamier.gotoright();
                        break;
                }
            }
        }
    }

    Rectangle {
        id: rect2
        x: -9
        y: -8
        width: 140
        height: 140
        color: mondamier.damier2colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 160
        anchors.top: parent.top
        Text {
            id: text2
            text: mondamier.damier2QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 10
    }

    Rectangle {
        id: rect3
        x: 2
        y: 7
        width: 140
        height: 140
        color: mondamier.damier3colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 310
        anchors.top: parent.top
        Text {
            id: text3
            text: mondamier.damier3QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 10
    }

    Rectangle {
        id: rect4
        x: 0
        y: -2
        width: 140
        height: 140
        color: mondamier.damier4colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 460
        anchors.top: parent.top
        Text {
            id: text4
            text: mondamier.damier4QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 10
    }

    Rectangle {
        id: rect5
        x: -4
        y: 4
        width: 140
        height: 140
        color: mondamier.damier5colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        Text {
            id: text5
            text: mondamier.damier5QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 160
    }

    Rectangle {
        id: rect6
        x: -8
        y: 1
        width: 140
        height: 140
        color: mondamier.damier6colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 160
        anchors.top: parent.top
        Text {
            id: text6
            text: mondamier.damier6QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 160
    }

    Rectangle {
        id: rect7
        x: 1
        y: 6
        width: 140
        height: 140
        color: mondamier.damier7colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 310
        anchors.top: parent.top
        Text {
            id: text7
            text: mondamier.damier7QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 160
    }

    Rectangle {
        id: rect8
        x: 1
        y: 0
        width: 140
        height: 140
        color: mondamier.damier8colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 460
        anchors.top: parent.top
        Text {
            id: text8
            text: mondamier.damier8QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 160
    }

    Rectangle {
        id: rect9
        x: 7
        y: 9
        width: 140
        height: 140
        color: mondamier.damier9colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        Text {
            id: text9
            text: mondamier.damier9QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 310
    }

    Rectangle {
        id: rect10
        x: 4
        y: 9
        width: 140
        height: 140
        color: mondamier.damier10colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 160
        anchors.top: parent.top
        Text {
            id: text10
            text: mondamier.damier10QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 310
    }

    Rectangle {
        id: rect11
        x: -4
        y: -1
        width: 140
        height: 140
        color: mondamier.damier11colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 310
        anchors.top: parent.top
        Text {
            id: text11
            text:mondamier.damier11QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 310
    }

    Rectangle {
        id: rect12
        x: 7
        y: 3
        width: 140
        height: 140
        color: mondamier.damier12colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 460
        anchors.top: parent.top
        Text {
            id: text12
            text: mondamier.damier12QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 310
    }

    Rectangle {
        id: rect13
        x: 8
        y: 9
        width: 140
        height: 140
        color: mondamier.damier13colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        Text {
            id: text13
            text: mondamier.damier13QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 460
    }

    Rectangle {
        id: rect14
        x: -6
        y: 7
        width: 140
        height: 140
        color: mondamier.damier14colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 160
        anchors.top: parent.top
        Text {
            id: text14
            text: mondamier.damier14QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 460
    }

    Rectangle {
        id: rect15
        x: 8
        y: -4
        width: 140
        height: 140
        color: mondamier.damier15colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 310
        anchors.top: parent.top
        Text {
            id: text15
            text: mondamier.damier15QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 460
    }

    Rectangle {
        id: rect16
        x: 8
        y: -1
        width: 140
        height: 140
        color: mondamier.damier16colQML
        radius: 10
        anchors.left: parent.left
        anchors.leftMargin: 460
        anchors.top: parent.top
        Text {
            id: text16
            text: mondamier.damier16QML
            font.pixelSize: 22
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }
        anchors.topMargin: 460
    }

    Rectangle {
        id: score
        x: 614
        width: 180
        height: 140
        color: "#ffffff"
        radius: 30
        border.width: 1
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 16

        Text {
            id: score1
            text: qsTr("Score :")
            anchors.horizontalCenterOffset: 1
            anchors.top: parent.top
            anchors.topMargin: 17
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.pixelSize: 25
        }

        Text {
            id: score2
            text: mondamier.scoreQML
            anchors.horizontalCenterOffset: 1
            anchors.top: parent.top
            anchors.topMargin: 79
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.pixelSize: 25
        }
    }

    Rectangle {
        id: tour
        x: 614
        width: 180
        height: 140
        color: "#ffffff"
        radius: 30
        border.width: 1
        anchors.top: parent.top
        anchors.topMargin: 160
        anchors.right: parent.right
        anchors.rightMargin: 16

        Text {
            id: tour1
            text: qsTr("Tour :")
            anchors.horizontalCenterOffset: 1
            anchors.top: parent.top
            anchors.topMargin: 16
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.pixelSize: 25
        }

        Text {
            id: tour2
            text: mondamier.tourQML
            anchors.horizontalCenterOffset: 1
            anchors.top: parent.top
            anchors.topMargin: 82
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.pixelSize: 25
        }
    }

    Rectangle {
        id: nouvelle_partie
        x: 614
        width: 180
        height: 80
        color: "#ffffff"
        radius: 18
        focus: true
        anchors.top: parent.top
        anchors.topMargin: 490
        anchors.right: parent.right
        anchors.rightMargin: 16

        Text {
            id: new_partie
            text: qsTr("Nouvelle Partie")
            font.family: "Tahoma"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 23
        }

        MouseArea {
            id: mouseArea
            width: 180
            height: 80
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            acceptedButtons: Qt.LeftButton
            onClicked: {
                if (mouse.button == Qt.LeftButton){
                    mondamier.nouvellepartie();
                }
            }
        }
    }

    Rectangle {
        id: annuler
        x: 614
        width: 180
        height: 80
        color: "#ffffff"
        radius: 18
        focus: true
        anchors.top: parent.top
        anchors.topMargin: 340
        anchors.right: parent.right
        anchors.rightMargin: 16

        Text {
            id: annuler_txt
            text: qsTr("Annuler")
            font.family: "Tahoma"
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 23
        }

        MouseArea {
            id: mouseArea2
            width: 180
            height: 80
            anchors.verticalCenterOffset: 0
            anchors.horizontalCenterOffset: 0
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            acceptedButtons: Qt.LeftButton
            onClicked: {
                if (mouse.button == Qt.LeftButton){
                    mondamier.annule();
                }
            }
        }
    }

    Rectangle {
        id: fin_de_partie
        width: 680
        height: 480
        color: "#d48ee4"
        radius: 80
        opacity: mondamier.opacityQML
        border.color: "#4a0168"
        border.width: 18
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Text {
            id: phrase_accroche
            text: mondamier.resultatQML
            font.family: "Tahoma"
            anchors.top: parent.top
            anchors.topMargin: 80
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 55
        }

        Text {
            id: ton_score
            text: qsTr("Ton score est de : ")
            anchors.top: parent.top
            anchors.topMargin: 150
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.pixelSize: 55
        }

        Text {
            id: score_final
            text: mondamier.scoreQML
            anchors.top: parent.top
            anchors.topMargin: 220
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Tahoma"
            font.pixelSize: 55
        }

        Rectangle {
            id: rect_recommencer
            x: 60
            y: 285
            width: 560
            height: 140
            color: "#cf7878"
            radius: 36
            anchors.top: parent.top
            anchors.topMargin: 300
            anchors.horizontalCenter: parent.horizontalCenter
            border.width: 0

            Text {
                id: recommencer
                text: qsTr("Recommencer")
                font.family: "Tahoma"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                font.pixelSize: 55
            }

            MouseArea {
                id: mouseArea1
                x: 0
                y: -125
                width: 560
                height: 140
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                acceptedButtons: Qt.LeftButton
                onClicked: {
                    if (mouse.button == Qt.LeftButton && (mondamier.possible_jouer()===false)){
                        mondamier.nouvellepartie();
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:42;invisible:true}
}
##^##*/
