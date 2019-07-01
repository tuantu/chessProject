import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

import org.example 1.0

ApplicationWindow {
    id: app
    title: qsTr("The simplest chess in the world")

    // Disable the maximum button
    minimumWidth: 710
    minimumHeight: 620
    maximumWidth: 710
    maximumHeight: 620
    visible: true

    ChessBoardModel {
        id: cbmChessBoard
    }

    MainForm {
        id: mainForm
        anchors.fill: parent

        property int lastDroppedIndex: -1

        btNewGame.onClicked: {
            cbmChessBoard.newGame();
            btSaveGame.visible = true;
            btStopGame.visible = true;
            btPrevStep.visible = false;
            btNextStep.visible = false;
        }

        btLoadGame.onClicked: {
            loadFileDialog.open();
        }

        btSaveGame.onClicked: {
            saveFileDialog.open();
        }

        btStopGame.onClicked: {
            cbmChessBoard.clearGame();
            btSaveGame.visible = false;
            btStopGame.visible = false;
            showHidePrevNext();
        }

        btPrevStep.onClicked: {
            cbmChessBoard.prevStep();
            showHidePrevNext();
        }

        btNextStep.onClicked: {
            cbmChessBoard.nextStep();
            showHidePrevNext();
        }

        maGridMovedItemCoords.onPressed: {
            gvChessBoard.draggedItemIndex = gvChessBoard.indexAt(
                        maGridMovedItemCoords.mouseX, maGridMovedItemCoords.mouseY);
            gvChessBoard.itemAt(maGridMovedItemCoords.mouseX, maGridMovedItemCoords.mouseY).state = "inDrag";
        }

        maGridMovedItemCoords.onReleased: {
            if (gvChessBoard.draggedItemIndex !== -1) {
                var draggedIndex = gvChessBoard.draggedItemIndex;
                gvChessBoard.draggedItemIndex = -1;
                lastDroppedIndex = gvChessBoard.indexAt(maGridMovedItemCoords.mouseX, maGridMovedItemCoords.mouseY)
                cbmChessBoard.move(draggedIndex, lastDroppedIndex);
                showHidePrevNext();

                if (cbmChessBoard.isGameOver()) {
                    messageDialog.show("The game is ended. King is dead.");
                } else if (cbmChessBoard.checkForPawnPromotion(lastDroppedIndex)) {
                    promotionDialog.open();
                }
            }
        }

    }

    MessageDialog {
        id: messageDialog
        title: qsTr("Attention, please")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

    FileDialog {
        id: saveFileDialog
        title: "Save current chess board to file"
        visible: false;
        selectExisting: false;
        nameFilters: [ "Chess files (*.mychess)", "All files (*)" ]

        onAccepted: {
            var str = cbmChessBoard.saveGame(saveFileDialog.fileUrl);
            if (str === "") {
                messageDialog.show("Game saved!");
            } else {
                messageDialog.show(str);
            }
        }
    }

    FileDialog {
        id: loadFileDialog
        title: "Load chess board from file"
        visible: false;
        selectExisting: true;
        nameFilters: [ "Chess files (*.mychess)", "All files (*)" ]

        onAccepted: {
            var str = cbmChessBoard.loadGame(loadFileDialog.fileUrl);
            if (str === "") {
                mainForm.btSaveGame.visible = true;
                mainForm.btStopGame.visible = true;
                showHidePrevNext();

                messageDialog.show("Game loaded! Enjoy!");
            } else {
                messageDialog.show(str);
            }
        }
    }

    PromotionDialog {
        id: promotionDialog
        width: 100
        height: 200

        btOkButton.onClicked: {
            cbmChessBoard.replacePawn(mainForm.lastDroppedIndex, tabPositionGroup.current.text);
            promotionDialog.close();
        }
    }

    function showHidePrevNext() {
        mainForm.btPrevStep.visible = cbmChessBoard.isPrevStepAvailable();
        mainForm.btNextStep.visible = cbmChessBoard.isNextStepAvailable();
    }
}
