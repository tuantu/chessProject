import QtQuick 2.0

Item {
    width: 75
    height: 75

    property alias itemImage: itemImage

//    Text {
//        anchors.centerIn: parent
//        id: cellContentStr
//        color: "#b8e293"
//        text: qsTr("")
//        font.pointSize: 15

//    }

    Image {
        id: itemImage
        source: image
        smooth: true
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectCrop
    }


    states: [
        State {
            name: "inDrag"
            when: index === parent.draggedItemIndex
            PropertyChanges { target: itemImage; parent: chessContainer }
            PropertyChanges { target: itemImage; anchors.centerIn: undefined }
            PropertyChanges { target: itemImage; x: maGridMovedItemCoords.mouseX - itemImage.width / 2 }
            PropertyChanges { target: itemImage; y: maGridMovedItemCoords.mouseY - itemImage.height / 2 }
        }
    ]

}

