import QtQuick 2.4

Item {
    width: 400
    height: 400
    property alias listView: listView

    ListView {
        id: listView
        x: 8
        y: 18
        width: 384
        height: 368
        model: myModel
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
                spacing: 10
            }
        }
    }
}
