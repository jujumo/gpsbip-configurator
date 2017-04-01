import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("GpsBip - Configurator")
    color: "#A0A0A0"

    Column {
        spacing: 25

        // IDENTITY::PILOT
        TextInput {
            id: stringIdentityPilot
            text: identity.pilotName.label
            enabled: identity.pilotName.enabled
        }
        Binding { target: identity.pilotName; property: "value"; value: stringIdentityPilot.text }

        // IDENTITY::PILOT
        TextInput {
            id: stringIdentityAircraftName
            text: identity.aircraftName.label
            enabled: identity.aircraftName.enabled
        }
        Binding { target: identity.aircraftName; property: "value"; value: stringIdentityAircraftName.text }

        // IDENTITY::COMPETITOR
        TextInput {
            id: stringIdentityCompetitorId
            text: identity.competitorId.label
            enabled: identity.competitorId.enabled
        }
        Binding { target: identity.competitorId; property: "value"; value: stringIdentityCompetitorId.text }

        // IDENTITY::TRIGRAM
        TextInput {
            id: stringIdentityTrigram
            text: identity.trigram.label
            enabled: identity.trigram.enabled
        }
        Binding { target: identity.trigram; property: "value"; value: stringIdentityTrigram.text }

        // IDENTITY::TRIGRAM
        ComboBox {
            id: stringIdentityAircraftType
            //text: identity.aircraftType.label
            enabled: identity.aircraftType.enabled
            model: ["paraglider", "paramotor", "hang glider", "bike", "hike"]
        }
        Binding { target: identity.aircraftType; property: "value"; value: stringIdentityAircraftType.text }

        // GPS
        CheckBox {
            id: checkboxGpsEnabled
            text: gps.gpsEnabled.label
            enabled: gps.gpsEnabled.enabled
            checked: gps.gpsEnabled.value
        }
        Binding { target: gps.gpsEnabled; property: "value"; value: checkboxGpsEnabled.checked }

        // GPS::takeOffDetection
        CheckBox {
            id: checkboxTakeoffDetection
            text: gps.takeOffDetection.label
            enabled: gps.takeOffDetection.enabled
            checked: gps.takeOffDetection.value
        }
        Binding { target: gps.takeOffDetection; property: "value"; value: checkboxTakeoffDetection.checked }

        Button {
            text: "Log values"
            onClicked:  {
                console.log(JSON.stringify(identity));
            }
        }
    }
}
