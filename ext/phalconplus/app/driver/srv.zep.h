
extern zend_class_entry *phalconplus_app_driver_srv_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Driver_Srv);

PHP_METHOD(PhalconPlus_App_Driver_Srv, __construct);
PHP_METHOD(PhalconPlus_App_Driver_Srv, exec);
PHP_METHOD(PhalconPlus_App_Driver_Srv, setHandler);
PHP_METHOD(PhalconPlus_App_Driver_Srv, getHandler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_driver_srv___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
	ZEND_ARG_OBJ_INFO(0, handler, PhalconPlus\\App\\Driver\\BaseApplication, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_driver_srv_exec, 0, 0, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_driver_srv_exec, 0, 0, IS_OBJECT, "NULL", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_driver_srv_sethandler, 0, 1, PhalconPlus\\App\\Driver\\AppDriver, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_driver_srv_sethandler, 0, 1, IS_OBJECT, "PhalconPlus\\App\\Driver\\AppDriver", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_driver_srv_gethandler, 0, 0, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_driver_srv_gethandler, 0, 0, IS_OBJECT, "NULL", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_driver_srv_method_entry) {
	PHP_ME(PhalconPlus_App_Driver_Srv, __construct, arginfo_phalconplus_app_driver_srv___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Driver_Srv, exec, arginfo_phalconplus_app_driver_srv_exec, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Driver_Srv, setHandler, arginfo_phalconplus_app_driver_srv_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Driver_Srv, getHandler, arginfo_phalconplus_app_driver_srv_gethandler, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
