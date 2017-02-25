import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
        spacing: 35

        CheckBox {
            id: cbGpsEnabled
            text: "GPS enabled"
        }
        Binding { target: gps; property: "gpsEnabled"; value: cbGpsEnabled.checked }

        CheckBox {
            id: cbToDetection
            text: "Takeoff detection"
        }
        Binding { target: gps; property: "takeOffDetection"; value: cbToDetection.checked }

        Button {
            text: "Log values"
            onClicked:  {
                console.log(JSON.stringify(gps));
            }
        }
    }
}
