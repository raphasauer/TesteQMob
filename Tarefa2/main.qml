import QtQuick 2.15
import QtQuick.Window 2.12
import Qt.labs.qmlmodels 1.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15




Window
{
    id: background
    minimumWidth: 755
    maximumWidth: 755
    height: 600
    visible: true

    title: qsTr("Player")

    //Recebe a lista do C++ em myList
    property var variantList: myList

    function startupFunction() {




        tabela.appendRow(                {
                             type: "Type",
                             speed: "Speed",
                             ammunition: "Ammunition",
                             active: "Active",
                             coordinates: "#Coordinates"
                         })

        //Itera pela lista adicionando os valores na tabela
        for(var i = 0; i < variantList.length; i++)
        {
            tabela.appendRow(                {
                                 type: variantList[i].m_playerType,
                                 speed: variantList[i].m_speed,
                                 ammunition: variantList[i].m_ammunition,
                                 active: variantList[i].m_active,
                                 coordinates: variantList[i].m_numberOfCoordinates,
                             })

        }



    }

    Component.onCompleted: startupFunction();

    ScrollView
    {
        contentWidth: 755
        contentHeight: 600
        anchors.fill: parent

        TableView {
            id: tableView
            anchors.fill: parent
            columnSpacing: 1
            rowSpacing: 2
            //Deixa as colunas fixas para melhor visibilidade
            property var columnWidths: [150, 150, 150, 150, 150]
            columnWidthProvider: function (column) { return columnWidths[column] }


            model: TableModel {

                id: tabela
                TableModelColumn { display: "type" }
                TableModelColumn { display: "speed" }
                TableModelColumn { display: "ammunition" }
                TableModelColumn { display: "active" }
                TableModelColumn { display: "coordinates" }

            }
            //Escreve os valores da tabela na tela
            delegate: Text {
                text: model.display
                padding: 16
                horizontalAlignment: Text.AlignHCenter

                Rectangle {
                    anchors.fill: parent
                    color: "#efefef"
                    z: -1
                }
            }

        }


    }

}



