#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <libgpsbip/GpsOptionsGroup.h>

#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    gpsbip::GpsOptionsGroup gpsGroup;

    QTimer t;
    t.connect(&t, &QTimer::timeout, [&] () { gpsGroup.setGpsEnabled(true); });
    t.start(3000);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("gps", &gpsGroup);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
