#include "alogger.h"
#include <QDebug>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QDir>
#include <iostream>
#ifdef QT_DEBUG
#include <QDateTime>
#include <QThread>
#else
#include <iomanip>
#include <glog/logging.h>
#endif

namespace PAIRIDEA {

#ifdef QT_DEBUG
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString& log)
{
    auto txtMessage = QStringLiteral("[%1][%2][%3]: %4 [%5:%6:%7]\n");
    const auto &dateTime = QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd HH:mm:ss.zzz"));
    const auto &filename = QFileInfo(context.file).fileName();
    const auto& threadId = QString("%1").arg(quintptr(QThread::currentThreadId()), 6, 10, QChar('0'));
    const auto &line = QString::number(context.line);
    
    QString level;
    switch (type)
    {
    case QtInfoMsg:		//普通信息
        level = QStringLiteral("INF");
        break;
    case QtDebugMsg:    //调试信息提示
        level = QStringLiteral("DEB");
        break;
    case QtWarningMsg:    //一般的warning提示
        level = QStringLiteral("WAR");
        break;
    case QtCriticalMsg:    //严重错误提示
        level = QStringLiteral("ERR");
        break;
    case QtFatalMsg:    //致命错误提示
        level = QStringLiteral("FAT");
        break;
    }
    QString func = context.function;
    auto funcStart = func.lastIndexOf("::") + 2;
    auto funcEnd = func.lastIndexOf("(");
    func = func.mid(funcStart, funcEnd - funcStart);
    txtMessage = txtMessage.arg(dateTime,level,threadId, log, filename,line, func);
    fprintf(stdout,"%s",txtMessage.toLocal8Bit().constData());
    fflush(stdout);
    
    if(type == QtFatalMsg){
        abort();
    }
}
#else
void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString & str)
{
    //代码文件和行数在qt内部，所以需要提前写入
    QString txtMessage = QStringLiteral("%1:%2:%3] %4");
    txtMessage = txtMessage.arg(QFileInfo(context.file).fileName(),
                                QString::number(context.line),
                                context.function,
                                str);
    
    switch (type)
    {
    case QtDebugMsg:    //调试信息提示
//        fprintf(stdout,"%s\n", txtMessage.toUtf8().constData());
//        fflush(stdout);
//        break;
    case QtInfoMsg:		//普通信息
        LOG(INFO) << txtMessage.toUtf8().constData();
        break;
    case QtWarningMsg:    //一般的warning提示
        LOG(WARNING) << txtMessage.toUtf8().constData();
        break;
    case QtCriticalMsg:    //严重错误提示
        LOG(ERROR) << txtMessage.toUtf8().constData();
        break;
    case QtFatalMsg:    //致命错误提示
        LOG(FATAL) << txtMessage.toUtf8().constData();
        //        abort();
        break;
    }
}

void MyPrefixFormatter(std::ostream& s, const google::LogMessage& m, void* /*data*/) {
    s << std::setw(4) << 1900 + m.time().year()
      << std::setw(2) << 1 + m.time().month()
      << std::setw(2) << m.time().day()
      << ' '
      << std::setw(2) << m.time().hour() << ':'
      << std::setw(2) << m.time().min()  << ':'
      << std::setw(2) << m.time().sec() << "."
      << std::setw(6) << m.time().usec()
      << " ["
      << google::GetLogSeverityName(m.severity())[0]
      << "] "
      << std::setfill(' ') << std::setw(5)
      << m.thread_id();
}
#endif

void ALogger::installLogHandler(const char* applicationName) noexcept
{
#ifndef QT_DEBUG
    qInfo().noquote() << "Start install Custom Log Handler";
    auto path = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    QDir dir(path);
    if(!dir.exists(path)){
        dir.mkpath(path);
    }
    dir.mkdir(applicationName);
    dir.cd(applicationName);
    //多加一层log文件夹
    dir.mkdir(QStringLiteral("log"));
    dir.cd(QStringLiteral("log"));
    qInfo().noquote() << "Log Path:" << dir.absolutePath();
    //将日志重定向到TEMP/ApplicationName
    FLAGS_log_dir = dir.absolutePath().toStdString().c_str();
    // log信息区分颜色
    FLAGS_colorlogtostderr = true;
    // 允许log信息打印到屏幕
//    FLAGS_logtostderr = 1; 
    google::SetLogFilenameExtension(".log");
    //设置最大文件大小为4G(最大也只能是4G)
    FLAGS_max_log_size = 4095;
    //清理老旧的日志文件
    static constexpr auto LogSaveTime = 60u * 24u * 7u;
    google::EnableLogCleaner(std::chrono::minutes(LogSaveTime));
    google::InstallPrefixFormatter(&MyPrefixFormatter);
    //下面这里有bug
//    google::InstallFailureWriter();
    google::InitGoogleLogging(applicationName);
#endif
    qInstallMessageHandler(customMessageHandler);
}

void ALogger::uninstallLogHandler() noexcept
{
    qInstallMessageHandler(nullptr);
#ifndef QT_DEBUG
    google::ShutdownGoogleLogging();
#endif
}

}
