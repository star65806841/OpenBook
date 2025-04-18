#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>

#include <ToolUnit/OpenBookLog/alogger.h>


#include <QtQuick/QQuickWindow>
#include <Config/config.h>

int main(int argc, char *argv[])
{
    PairIdea::ALogger logger;
    logger.installLogHandler(PairIdea::AppName);
    qInfo() << ".................Application Start .................";

    // qputenv("QT_WIN_DEBUG_CONSOLE", "attach");
    // qDebug()<<"QT_WIN_DEBUG_CONSOLE";
    // qputenv("QSG_INFO", "1");
    // qputenv("QT_QUICK_CONTROLS_STYLE", "Default");
    // qputenv("QT_QUICK_CONTROLS_STYLE", "Basic");
    // #if 0
    // qputenv("QSG_RHI_BACKEND", "opengl");
    //qputenv("QSG_RHI_HDR", "scrgb");
    //qputenv("QT_QPA_DISABLE_REDIRECTION_SURFACE", "1");
    QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    // #endif
    QQuickWindow::setDefaultAlphaBuffer(true);

    // Setting Format is ini
    QSettings::setDefaultFormat(QSettings::IniFormat);

    QGuiApplication app(argc, argv);
    app.setApplicationName(PairIdea::AppName);
    app.setOrganizationName(PairIdea::CompanyName);
    app.setApplicationVersion(PairIdea::AppVersion);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    // QWK::registerTypes(&engine);
    engine.loadFromModule("Main", "Main");
    // const QUrl url(QStringLiteral("../view/Main.qml"));
    // engine.load(url);
    auto ret = app.exec();
    qInfo() << ".................Application End .................";
    logger.uninstallLogHandler();
    return ret;
}
