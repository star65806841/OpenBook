// Copyright (C) 2023-2024 Stdware Collections (https://www.github.com/stdware)
// Copyright (C) 2021-2023 wangwenx190 (Yuhang Zhao)
// SPDX-License-Identifier: Apache-2.0

#include <QtCore/QCoreApplication>
#include <OpenBookLog/alogger.h>
#include <QDebug>

int main(int argc, char *argv[]) {
    QCoreApplication application(argc, argv);
    PairIdea::ALogger logger;
    logger.installLogHandler("OpenBookLogTest");
    
    for(qint64 i = 0; i < 50; ++i){
        qDebug() << "debugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebug"
                    "debugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebug"
                    "debugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebug"
                    "debugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebug"
                    "debugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebugdebug";
        qWarning() << "testtesttesttesttesttesttesttesttesttesttesttesttesttest"
                      "testtesttesttesttesttesttesttesttesttesttesttesttesttest"
                      "testtesttesttesttesttesttesttesttesttesttesttesttesttest"
                      "testtesttesttesttesttesttesttesttesttesttesttesttesttest"
                      "testtesttesttesttesttesttesttesttesttesttesttesttesttest"
                      "testtesttesttesttesttesttesttesttesttesttesttesttesttest"
                      "testtesttesttesttesttesttesttesttesttesttesttesttesttest";
        qInfo() << "infoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfo"
                   "infoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfo"
                   "infoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfo"
                   "infoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfo"
                   "infoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfo"
                   "infoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfoinfo";
    }
    qCritical() << "ajdlkajda";
    //    qFatal("zxnc,zxnc,z");
    
    return 0;
}
