// #ifndef EDITORENGINE_H
// #define EDITORENGINE_H

// #include <QJSEngine>
// #include <QObject>
// #include <QQmlEngine>

// namespace Aimo {

// class EditorEnginePrivate;
// class ATranslator;
// class PrinterListModel;
// class TemplateListModel;
// class PaperListModel;
// class SearchListModel;
// class PrinterSearchModel;
// class DateTimeHelper;
// class IconListModel;
// class FrameImgListModel;

// /*!
//  * \brief 编辑器引擎
//  * \qmlproperty templateListModel 模板列表模型,主页的模板
//  * \qmlproperty paperListModel 标签列表模型，主页的标签
//  * \qmlproperty windowFocusHelper 全局的应用窗口最底层的焦点辅助器
//  * \qmlabstract isMM 全局显示的单位制，true则是显示毫米，false则是英寸
//  *                   设置该值会保存到配置文件，下次启动时恢复
//  *                   更换语言也会重置该值，英语为英制，其他为公制
//  */
// class EditorEngine : public QObject
// {
//     Q_OBJECT
// 	Q_PROPERTY(Aimo::TemplateListModel* templateListModel READ templateListModel CONSTANT FINAL)
// 	Q_PROPERTY(Aimo::PaperListModel* paperListModel READ paperListModel CONSTANT FINAL)
//     Q_PROPERTY(Aimo::IconListModel* iconListModel READ iconListModel CONSTANT FINAL)
//     Q_PROPERTY(Aimo::FrameImgListModel* frameImgListModel READ frameImgListModel CONSTANT FINAL)
//     Q_PROPERTY(Aimo::SearchListModel* searchListModel READ searchListModel CONSTANT FINAL)
//     Q_PROPERTY(Aimo::DateTimeHelper* dateTimeHelper READ dateTimeHelper CONSTANT FINAL)
//     Q_PROPERTY(QObject* windowFocusHelper READ windowFocusHelper WRITE setWindowFocusHelper NOTIFY windowFocusHelperChanged FINAL)
// 	Q_PROPERTY(bool isMM READ isMM WRITE setIsMM RESET resetIsMM NOTIFY isMMChanged FINAL)
//     Q_PROPERTY(float DPI READ DPI CONSTANT FINAL)
//     Q_PROPERTY(QString logDir READ logDir CONSTANT FINAL)
//     Q_PROPERTY(QString cfgDir READ cfgDir CONSTANT FINAL)
// public:
//     explicit EditorEngine(QObject *parent = nullptr);
	
// 	/*!
//      * \brief 单例
//      */
// 	static EditorEngine* Instance() noexcept;
	
// 	/*!
// 	 * \brief 删除实例
// 	 */
// 	static void Release();
	
// 	/*!
//      * \brief 用于提供给qml注册单例类
//      * \param engine                qml引擎
//      * \param scriptEngine            js引擎
//      */
// 	static QObject* qobject_singletontype_provider(QQmlEngine *engine,
// 												   QJSEngine *scriptEngine) noexcept;
    
//     /*!
//      * \brief 获取翻译器对象
//      * \qmlmodule 在执行exec后会将该对象直接注册到全局对象中
//      *            通过$trans直接访问对象
//      */
//     ATranslator* getTranslator() noexcept;
	
// 	/*!
// 	 * \brief 打印模板列表模型
// 	 */
// 	TemplateListModel* templateListModel() noexcept;
	
// 	/*!
// 	 * \brief 打印标签列表模型
// 	 */
// 	PaperListModel* paperListModel() noexcept;

//     IconListModel* iconListModel() noexcept;

//     FrameImgListModel* frameImgListModel() noexcept;
//     /*!
//      * \brief 搜索筛选模型
//      */
//     SearchListModel* searchListModel() noexcept;
    
//     /*!
//      * \brief 日期辅助类
//      */
//     DateTimeHelper* dateTimeHelper() noexcept;
    
//     /*!
//      * \brief 获取窗口焦点辅助器
//      */
//     QObject *windowFocusHelper() const noexcept;
    
//     /*!
//      * \brief 设置新的窗口焦点辅助器
//      * \note 只需要设置一次即可
//      */
//     void setWindowFocusHelper(QObject *newWindowFocusHelper) noexcept;
    
//     /*!
//      * \brief 初始化并进入事件循环
//      */
// 	int exec() noexcept;
	
// 	/*!
// 	 * \brief 如果当前为毫米单位则返回true,英寸则返回false
// 	 */
// 	bool isMM() const;
	
// 	/*!
// 	 * \brief 更改当前单位
// 	 */
// 	void setIsMM(bool newIsMM);
    
//     /*!
//      * \brief 构建新标签名字
//      * \note 默认名称:标签+当天日期+流水号。
//      *       当天日期格式为MMdd，流水号指当天创建标
//      *       签的序号，当天首次创建标签的序号为01，点击确定后再次创建标签，序号为02，依次类推
//      * \param baseName 基础名字
//      */
//     Q_INVOKABLE QString makeNewLabelName(const QString& baseName) noexcept;
    
//     /*!
//      * \brief 获取剪贴板的纯文本信息
//      */
//     Q_INVOKABLE QString getClipboardText() noexcept;

// #ifdef Q_OS_WIN
//     const WId& winId() { return _winId; }
// #endif

//     float DPI() const;
    
//     void setLogDumpDir(const QString& dir);

//     QString logDir();

//     QString cfgDir();

// signals:
// 	/*!
// 	 * \brief 开始初始化引擎
// 	 *        启动后会在其他线程进行初始化操作
// 	 * \attention 非线程安全，执行期间不允许操作EditorEngine
// 	 * \note 目前在等待页面进行加载
// 	 */
// 	void startInitEngineAsync();
	
// 	/*!
// 	 * \brief 引擎初始化完毕后会发出该信号
// 	 * \attention 该接口为私有信号，不允许外部发出
// 	 * \note 目前主窗口初始化在该信号发出后进行
// 	 */
// 	void initCompleted();
	
// 	/*!
// 	 * \brief 毫米单位更换时发出
// 	 */
//     void isMMChanged();
    
//     /*!
//      * \brief 更改窗口焦点辅助器后会发出该信号
//      */
//     void windowFocusHelperChanged();

//     void newUsbDeviceAddConfirm(const QString& printer, const QVariant& usbDevInfo = {});
    
// public slots:
// 	/*!
// 	 * \brief 重置公英制单位
// 	 * \note 根据当前设置的语言重置单位
// 	 *       只有英语默认为英制，其他为公制
// 	 */
// 	void resetIsMM();
    
//     /*!
//      * \brief 安装编辑组件的鼠标自定义样式数据
//      */
//     void installLabelItemCustomCursor(const QVariantList& dataList);
    
//     /*!
//      * \brief 语言更改时的回调，更新所有跟语言相关的业务
//      */
//     void onlanguageChanged();

// 	void on_device_add(const QString& usb_path, const QString& devId, const QString& pid, const QString& vid);
// 	void on_device_removed(const QString& usb_path, const QString& devId, const QString& pid, const QString& vid);
//     void on_newUsbDeviceAddConfirm(bool useNew, const QVariant& usbDevInfo = {});

// private:
//     Q_DISABLE_COPY(EditorEngine)
//     Q_DECLARE_PRIVATE(EditorEngine)

// #ifdef Q_OS_WIN
//     WId _winId = 0;
// #endif
// };

// }


// #endif // EDITORENGINE_H
