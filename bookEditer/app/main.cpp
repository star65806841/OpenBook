#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <ToolUnit/OpenBookLog/alogger.h>
#include <Config/config.h>

int main(int argc, char *argv[])
{
    PairIdea::ALogger logger;
    logger.installLogHandler(PairIdea::AppName);
    qInfo() << ".................Application Start .................";


    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Main", "Main");
    // const QUrl url(QStringLiteral("../view/Main.qml"));
    // engine.load(url);


    qInfo() << ".................Application End .................";

    logger.uninstallLogHandler();
    return app.exec();
}
