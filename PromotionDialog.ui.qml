import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

Dialog {
    visible: false
    title: "Pawn Promotion"

    property alias tabPositionGroup: tabPositionGroup
    property alias btOkButton: btOkButton

    contentItem:  ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        ExclusiveGroup { id: tabPositionGroup }
        RadioButton {
            text: "Queen"
            checked: true
            exclusiveGroup: tabPositionGroup
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        }
        RadioButton {
            text: "Bishop"
            exclusiveGroup: tabPositionGroup
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        }
        RadioButton {
            text: "Knight"
            exclusiveGroup: tabPositionGroup
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        }
        RadioButton {
            text: "Rook"
            exclusiveGroup: tabPositionGroup
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        }

        Button {
            text: "Ok"
            id: btOkButton
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        }
    }
}
