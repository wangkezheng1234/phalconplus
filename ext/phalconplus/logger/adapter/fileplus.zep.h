
extern zend_class_entry *phalconplus_logger_adapter_fileplus_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Adapter_FilePlus);

PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __construct);
PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, open);
PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, process);
PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, registerExtension);
PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, close);
PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, getProcessorVar);
PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __get);
PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __destruct);
PHP_METHOD(PhalconPlus_Logger_Adapter_FilePlus, __wakeup);
zend_object *zephir_init_properties_PhalconPlus_Logger_Adapter_FilePlus(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filePath)
#endif
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_open, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filePath)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_process, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_process, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_process, 0, 0, 1)
#define arginfo_phalconplus_logger_adapter_fileplus_process NULL
#endif

	ZEND_ARG_OBJ_INFO(0, item, Phalcon\\Logger\\Item, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_registerextension, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ext, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ext)
#endif
	ZEND_ARG_ARRAY_INFO(0, types, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_close, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_close, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_getprocessorvar, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus_getprocessorvar, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, key)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_adapter_fileplus___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_adapter_fileplus_method_entry) {
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, __construct, arginfo_phalconplus_logger_adapter_fileplus___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, open, arginfo_phalconplus_logger_adapter_fileplus_open, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, process, arginfo_phalconplus_logger_adapter_fileplus_process, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, registerExtension, arginfo_phalconplus_logger_adapter_fileplus_registerextension, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, close, arginfo_phalconplus_logger_adapter_fileplus_close, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, getProcessorVar, arginfo_phalconplus_logger_adapter_fileplus_getprocessorvar, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, __get, arginfo_phalconplus_logger_adapter_fileplus___get, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(PhalconPlus_Logger_Adapter_FilePlus, __wakeup, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
