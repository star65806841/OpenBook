#ifndef ALOGGER_H
#define ALOGGER_H

#include "pairlogglobal.h"
#include <QObject>
#include <QLocale>

namespace PairIdea {

/*!
 * \brief 日志模块，内部通过qInstallMessageHandler重定向输出
 * \note 初始化时，执行installLogHandler，取消时执行uninstallLogHandler
 * \attention debug模式下不会生效
 */
class PAIRLOG_EXPORT ALogger
{
public:
    ALogger() = default;
    
    ~ALogger() = default;
    
    /*!
     * \brief 安装日志处理函数
     */
    void installLogHandler(const char* applicationName) noexcept;
    
    /*!
     * \brief 取消安装日志函数
     */
    void uninstallLogHandler() noexcept;
};

} // namespace

#endif // ALOGGER_H
