
extern zend_class_entry *phalconplus_app_handler_srv_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Handler_Srv);

PHP_METHOD(PhalconPlus_App_Handler_Srv, getHandler);
PHP_METHOD(PhalconPlus_App_Handler_Srv, __construct);
PHP_METHOD(PhalconPlus_App_Handler_Srv, exec);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_handler_srv___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoHandle, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoHandle)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_handler_srv_exec, 0, 0, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_handler_srv_exec, 0, 0, IS_OBJECT, "NULL", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_handler_srv_method_entry) {
	PHP_ME(PhalconPlus_App_Handler_Srv, getHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Handler_Srv, __construct, arginfo_phalconplus_app_handler_srv___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Handler_Srv, exec, arginfo_phalconplus_app_handler_srv_exec, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
