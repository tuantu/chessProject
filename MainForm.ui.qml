import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 700
    height: 630

    property alias gbActions: gbActions
    property alias btNewGame: btNewGame
    property alias btLoadGame: btLoadGame
    property alias btSaveGame: btSaveGame
    property alias btStopGame: btStopGame
    property alias btPrevStep: btPrevStep
    property alias btNextStep: btNextStep
    property alias gvChessBoard: gvChessBoard
    property alias maGridMovedItemCoords: maGridMovedItemCoords
    property alias chessContainer: chessContainer

    GroupBox {
        id: gbActions
        width: 90
        height: 620
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 5
        title: qsTr("Actions")

        ColumnLayout {
            id: clActions
            transformOrigin: Item.Center
            anchors.top: parent.top
            anchors.topMargin: 20
            spacing: 10

            Button {
                id: btNewGame
                text: qsTr("New Game")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            Button {
                id: btLoadGame
                text: qsTr("Load Game")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            }

            Button {
                id: btSaveGame
                text: qsTr("Save Game")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                visible: false;
            }

            Button {
                id: btStopGame
                text: qsTr("Stop Game")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                visible: false;
            }
        }

        ColumnLayout {
            id: clSubActions
            transformOrigin: Item.Center
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            height: 55

            Button {
                id: btPrevStep
                text: qsTr("Previous")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                visible: false;
            }

            Button {
                id: btNextStep
                text: qsTr("Next")
                Layout.alignment: Qt.AlignHCenter | Qt.AlignBottom
                visible: false;
            }
        }
    }

    Image {
        id: imgChessBoard
        y: 10
        width: 600
        height: 600
        anchors.left: gbActions.right
        anchors.leftMargin: 5
        source: "images/Chess_Board.png"

        GridView {
            property int draggedItemIndex: -1

            id: gvChessBoard
            anchors.fill: parent
            interactive: false

            cellWidth: 75
            cellHeight: 75

            model: cbmChessBoard

            delegate: ChessCellElement {
            }

            Item {
                id: chessContainer
                anchors.fill: parent
            }

            MouseArea {
                id: maGridMovedItemCoords
                anchors.fill: parent
            }
        }
    }

}
