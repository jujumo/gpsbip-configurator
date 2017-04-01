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

        // IDENTITY::AIRCRAFT_TYPE
        ComboBox {
            id: stringIdentityAircraftType
            //text: identity.aircraftType.label
            enabled: identity.aircraftType.enabled
            model: ["paraglider", "paramotor", "hang glider", "bike", "hike"]
        }
        Binding { target: identity.aircraftType; property: "value"; value: stringIdentityAircraftType.currentIndex }

        // GPS
        CheckBox {
            id: checkboxGpsEnabled
            text: gps.isGpsEnabled.label
            enabled: gps.isGpsEnabled.enabled
            checked: gps.isGpsEnabled.value
        }
        Binding { target: gps.isGpsEnabled; property: "value"; value: checkboxGpsEnabled.checked }

        // GPS::isTakeoffDetected
        CheckBox {
            id: checkboxTakeoffDetection
            text: gps.isTakeoffDetected.label
            enabled: gps.isTakeoffDetected.enabled
            checked: gps.isTakeoffDetected.value
        }
        Binding { target: gps.isTakeoffDetected; property: "value"; value: checkboxTakeoffDetection.checked }

        // GPS::isIgcRecorded
        CheckBox {
            id: checkboxIgcRecord
            text: gps.isIgcRecorded.label
            enabled: gps.isIgcRecorded.enabled
            checked: gps.isIgcRecorded.value
        }
        Binding { target: gps.isIgcRecorded; property: "value"; value: checkboxIgcRecord.checked }

        // GPS::isKmlRecorded
        CheckBox {
            id: checkboxKmlRecord
            text: gps.isKmlRecorded.label
            enabled: gps.isKmlRecorded.enabled
            checked: gps.isKmlRecorded.value
        }
        Binding { target: gps.isKmlRecorded; property: "value"; value: checkboxKmlRecord.checked }

        // GPS::isKmlGrounded
        CheckBox {
            id: checkboxKmlGrounded
            text: gps.isKmlGrounded.label
            enabled: gps.isKmlGrounded.enabled
            checked: gps.isKmlGrounded.value
        }
        Binding { target: gps.isKmlGrounded; property: "value"; value: checkboxKmlGrounded.checked }

        // GPS::isGpsPerformant
        CheckBox {
            id: checkboxGpsHighPerf
            text: gps.isGpsPerformant.label
            enabled: gps.isGpsPerformant.enabled
            checked: gps.isGpsPerformant.value
        }
        Binding { target: gps.isGpsPerformant; property: "value"; value: checkboxGpsHighPerf.checked }

        // GPS::gpsPeriod
        ComboBox {
            id: integerGpsPeriod
            //text: identity.aircraftType.label
            enabled: gps.gpsPeriod.enabled
            model: ["1 point : 60 secondes", "1 point : 10 secondes", "1 point : 5 secondes", "1 point : 1 seconde"]
        }
        Binding { target: gps.gpsPeriod; property: "value"; value: integerGpsPeriod.currentIndex }


    }
}
