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
            checked: gps.gpsEnabled.value
        }
        Binding { target: gps.gpsEnabled; property: "value"; value: cbGpsEnabled.checked }

        CheckBox {
            id: cbToDetection
            text: "Takeoff detection"
            checked: gps.takeOffDetection.value
        }
        Binding { target: gps.takeOffDetection; property: "value"; value: cbToDetection.checked }

        Button {
            text: "Log values"
            onClicked:  {
                console.log(JSON.stringify(gps));
            }
        }
    }
}
