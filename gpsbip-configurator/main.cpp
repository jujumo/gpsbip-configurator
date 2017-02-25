#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <libgpsbip/GpsOptionsGroup.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    gpsbip::GpsOptionsGroup gpsGroup;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("gps", &gpsGroup);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
