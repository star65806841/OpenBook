// #include "editorengine.h"
// #include "editorengine_p.h"
// #include <QQmlApplicationEngine>
// #include <QQmlContext>

// #include <QApplication>
// #include <QMessageBox>
// #include <Labelife/config.h>
// #include <QSettings>
// #include <AimoKit/Kernel/AimoKernelInterface.h>
// #include "utils/qmlregisteralltype.h"
// #include "view/LabelItem.h"

// #include <QQuickWindow>
// #include "../usb/USBDeviceMonitor.h"
// #include "uisignalmanager.h"
// #include "font/fontmanager.h"
// #include <AimoKit/Kernel/PrinterCommon.h>
// #include <AimoKit/Common/Resolution.h>
// #include <AimoKit/Common/PathHelper.h>
// #include "./view/LabelText.h"
// #include <QClipboard>

// using namespace Aimo;

// void EditorEnginePrivate::initSettings()
// {
// 	QSettings setting;
// 	isMM = setting.value("isMM",true).toBool();
    
//     dateTimeHelper.initSettings();
// }

// void EditorEnginePrivate::saveIsMM()
// {
// 	QSettings setting;
// 	setting.setValue("isMM",isMM);
// }

// static EditorEngine* _engine_manager{nullptr};
// EditorEngine *Aimo::EditorEngine::Instance() noexcept
// {
//     if (_engine_manager == nullptr)
//     {
//         InitKernel();
//         _engine_manager = new EditorEngine();
//     }
// 	return _engine_manager;
// }

// void EditorEngine::Release()
// {
//     UnInitKernel();

// 	delete _engine_manager;
// }

// QObject *EditorEngine::qobject_singletontype_provider(QQmlEngine *engine,
// 													  QJSEngine *scriptEngine) noexcept
// {
// 	Q_UNUSED(engine)
// 	Q_UNUSED(scriptEngine)
	
// 	QQmlEngine::setObjectOwnership(_engine_manager,QQmlEngine::CppOwnership);
// 	return _engine_manager;
// }

// EditorEngine::EditorEngine(QObject *parent)
//     : QObject{*(new EditorEnginePrivate),parent}
// {
// 	Q_D(EditorEngine);
// 	connect(this,&EditorEngine::startInitEngineAsync,
// 			&d->loadingHelper,&LaunchLoadingHelper::onStartInitEngine);
//     connect(&PrinterCommon::Instance(), &PrinterCommon::newUsbDeviceAddConfirm,
//         this, &EditorEngine::newUsbDeviceAddConfirm);
// }

// ATranslator *EditorEngine::getTranslator() noexcept
// {
//     Q_D(EditorEngine);
// 	return &d->trans;
// }

// TemplateListModel *EditorEngine::templateListModel() noexcept
// {
// 	Q_D(EditorEngine);
// 	return &d->templateModel;
// }

// PaperListModel *EditorEngine::paperListModel() noexcept
// {
// 	Q_D(EditorEngine);
//     return &d->paperModel;
// }

// IconListModel* Aimo::EditorEngine::iconListModel() noexcept
// {
//     Q_D(EditorEngine);
//     return &d->iconModel;
// }

// FrameImgListModel* Aimo::EditorEngine::frameImgListModel() noexcept
// {
//     Q_D(EditorEngine);
//     return &d->frameImgModel;
// }

// SearchListModel *EditorEngine::searchListModel() noexcept
// {
//     Q_D(EditorEngine);
//     return &d->searchModel;
// }

// DateTimeHelper *EditorEngine::dateTimeHelper() noexcept
// {
//     Q_D(EditorEngine);
//     return &d->dateTimeHelper;
// }

// QObject *EditorEngine::windowFocusHelper() const noexcept
// {
//     Q_D(const EditorEngine);
//     return d->windowFocusHelper;
// }

// void EditorEngine::setWindowFocusHelper(QObject *newWindowFocusHelper) noexcept
// {
//     Q_D(EditorEngine);
//     if (d->windowFocusHelper == newWindowFocusHelper)
//         return;
//     d->windowFocusHelper = newWindowFocusHelper;
//     emit windowFocusHelperChanged();
// }

// int EditorEngine::exec() noexcept
// {
//     qInfo().noquote() << "Start EditorEngine Exec";

//     Q_D(EditorEngine);
    
//     QQmlApplicationEngine engine;
//     const QUrl url(QStringLiteral("qrc:/ui/qml/main.qml"));
//     QObject::connect(&engine,&QQmlApplicationEngine::objectCreated,
//         this, [url](QObject *obj, const QUrl &objUrl) {
//             if (!obj && url == objUrl){
//                 QMessageBox::warning(nullptr,
//                                      tr("启动失败"),
//                                      tr("组件加载失败,请联系管理员进行处理!"));
//                 QCoreApplication::exit(-1);
//             }
//         },
//         Qt::QueuedConnection);

//     //添加plugins导入路径
// #ifdef Q_OS_MACOS
    
// #ifdef QT_DEBUG
//     engine.addImportPath("../../../../");
// #else
//     engine.addImportPath("../");
//     engine.addImportPath("../Resources/qml");
// #endif

// #else  //Windows 和 Linux
    
// #ifdef QT_DEBUG
//     engine.addImportPath("../");
// #else
//     engine.addImportPath("../");
//     engine.addImportPath("./qml");
// #endif

// #endif
//     qDebug() << engine.importPathList();
    
//     //初始化翻译
//     d->trans.setFileName("aimo");
//     d->trans.loadSettings();
    
// 	connect(&d->trans,&ATranslator::tokenChanged,
// 			this,&EditorEngine::onlanguageChanged);

//     connect(&USBDeviceMonitor::getInstance(), &USBDeviceMonitor::device_add, this, &EditorEngine::on_device_add, Qt::QueuedConnection);
//     connect(&USBDeviceMonitor::getInstance(), &USBDeviceMonitor::device_removed, this, &EditorEngine::on_device_removed, Qt::QueuedConnection);

//     connect(UISignalManager::Instance(), &UISignalManager::mainWindowInitCompleted, this, [&](QWindow* mainWindow) {
//         if (mainWindow)
//         {
//             // LogDebug << "mainWindow InitCompleted...";
// #ifdef Q_OS_WIN
//             if (WId winId = mainWindow->winId(); winId > 0)
//             {
//                 USBDeviceMonitor::getInstance().registerSystemMessage(reinterpret_cast<HWND>(winId));
//                 _winId = winId;
//             }
// #endif
//         }
//         });

// 	//初始化配置信息
// 	d->initSettings();
    
//     //加载到qml全局变量
//     //设置动态翻译模块
//     auto rootContext = engine.rootContext();
//     rootContext->setContextProperty("$trans", &d->trans);
// 	//BUG: 直接使用指针会造成析构问题
// 	QString copyright{Copyright};
// 	rootContext->setContextProperty("$copyright",copyright);
//     // QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
//     // rootContext->setContextProperty("$defaultConfigPath",configPath);
    
//     //注册qml类型
//     qmlregisteralltype();
    
//     //加载阿里巴巴普惠体
//     FontManager::Instance()->loadAlibabaPuHuiTi();
    
//     engine.load(url);

// #ifdef Q_OS_MAC
//     USBDeviceMonitor::getInstance().startMonitoring();
// #endif
//     auto code = qApp->exec();

// #ifdef Q_OS_MAC
//     USBDeviceMonitor::getInstance().stopMonitoring();
// #endif

//     // qInfo().noquote() << "Exit EditorEngine Exec";
// 	return code;
// }

// bool EditorEngine::isMM() const
// {
// 	Q_D(const EditorEngine);
// 	return d->isMM;
// }

// void EditorEngine::setIsMM(bool newIsMM)
// {
// 	Q_D(EditorEngine);
// 	if (d->isMM == newIsMM)
// 		return;
	
// 	d->isMM = newIsMM;
// 	d->saveIsMM();
//     emit isMMChanged();
// }

// QString EditorEngine::makeNewLabelName(const QString &baseName) noexcept
// {
//     QSettings settings;
//     settings.beginGroup(QStringLiteral("NewLabelArguments"));
//     qint64 latestJulianDay = settings.value("julianDay").toLongLong();
//     int num = settings.value("currentNum").toInt();
//     auto currentDate = QDate::currentDate();
//     auto currentJulianDay = currentDate.toJulianDay();
//     if(latestJulianDay == currentJulianDay){
//         num = num + 1;
//     } else {
//         num = 1;
//         settings.setValue("julianDay",currentJulianDay);
//     }
//     settings.setValue("currentNum",num);
//     settings.endGroup();
    
//     return baseName + currentDate.toString("MMdd%1").arg(num,2,10,QLatin1Char('0'));
// }

// QString EditorEngine::getClipboardText() noexcept
// {
//     QClipboard *clipboard = QGuiApplication::clipboard();
//     if (clipboard) {
//         QString originalText = clipboard->text();
//         return originalText;
//     }
//     return QString();
// }

// void EditorEngine::resetIsMM()
// {
// 	Q_D(EditorEngine);
// 	auto locale = d->trans.currentLanguage();
// 	if(locale.language() == QLocale::Language::English){
// 		setIsMM(false);
// 	} else {
// 		setIsMM(true);
//     }
// }

// void EditorEngine::installLabelItemCustomCursor(const QVariantList& dataList)
// {
//     QVector<QCursor> vector;
//     vector.reserve(dataList.size());
//     for(const auto& i : dataList){
//         vector.push_back(i.value<QCursor>());
//     }
//     LabelItem::InstallCustomCursor(vector);
// }

// void EditorEngine::onlanguageChanged()
// {
//     Q_D(EditorEngine);
//     // 更改语言时替换英制
//     resetIsMM();
//     // 更改语言时替换日期的默认格式
//     d->dateTimeHelper.resetDefaultDateFormatModelAndDefaultTimeFormatModel();
//     //更新文本的默认文本
//     LabelText::updateInitText();
// }

// void EditorEngine::on_device_add(const QString& usb_path, const QString& devId, const QString& pid, const QString& vid)
// {
//     PrinterCommon::Instance().device_add(usb_path, devId, pid, vid);
// }

// void EditorEngine::on_device_removed(const QString& usb_path, const QString& devId, const QString& pid, const QString& vid)
// {
//     PrinterCommon::Instance().device_removed(usb_path, devId, pid, vid);
// }

// void Aimo::EditorEngine::on_newUsbDeviceAddConfirm(bool useNew, const QVariant& usbDevInfo)
// {
//     PrinterCommon::Instance().onNewUsbDeviceAddConfirm(useNew, usbDevInfo);
// }

// float EditorEngine::DPI() const
// {
//     return ResolutionDefault.DPI;
// }

// void Aimo::EditorEngine::setLogDumpDir(const QString& dir)
// {
//     Q_D(EditorEngine);
//     d->logDir = dir;
// }

// QString Aimo::EditorEngine::logDir()
// {
//     Q_D(EditorEngine);
//     return d->logDir;
// }

// QString Aimo::EditorEngine::cfgDir()
// {
//     return LocalDataConfigDir();
// }
