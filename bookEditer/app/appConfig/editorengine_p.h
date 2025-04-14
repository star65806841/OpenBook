// #ifndef EDITORENGINE_P_H
// #define EDITORENGINE_P_H

// //
// //  W A R N I N G !!!
// //  -----------------
// //
// // This file is not part of the Private API. It is used purely as an
// // implementation detail. This header file may change from version to
// // version without notice, or may even be removed.
// //

// #include "editorengine.h"
// #include <AimoKit/TranslateCore/atranslator.h>
// #include <QtCore/private/qobject_p.h>
// #include "private/launchloadinghelper_p.h"
// #include "model/templatelistmodel.h"
// #include "model/paperlistmodel.h"
// #include "model/searchlistmodel.h"
// #include "model/IconListModel.h"
// #include "model/FrameImgListModel.h"
// #include "helper/datetimehelper.h"

// namespace Aimo {

// class EditorEnginePrivate : public QObjectPrivate
// {
// public:
//     Q_DECLARE_PUBLIC(EditorEngine)
    
//     ATranslator trans;
// 	LaunchLoadingHelper loadingHelper;
// 	TemplateListModel templateModel;
// 	PaperListModel paperModel;
// 	IconListModel iconModel;
// 	FrameImgListModel frameImgModel;
//     SearchListModel searchModel;
//     DateTimeHelper dateTimeHelper;
//     QObject *windowFocusHelper{nullptr};
// 	bool isMM{false};
// 	QString logDir;

// 	void initSettings();
// 	void saveIsMM();
// };

// } // namespace Aimo

// #endif // EDITORENGINE_P_H
