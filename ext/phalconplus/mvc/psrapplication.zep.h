
extern zend_class_entry *phalconplus_mvc_psrapplication_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Mvc_PsrApplication);

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, setPsrRequest);
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, getPsrRequest);
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, getNativeRequest);
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, __construct);
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, __destruct);
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_mvc_psrapplication_setpsrrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, psrRequest)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_mvc_psrapplication___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, psrRequest, Psr\\Http\\Message\\ServerRequestInterface, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_mvc_psrapplication_handle, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_mvc_psrapplication_handle, 0, 0, IS_OBJECT, "Phalcon\\Http\\ResponseInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_mvc_psrapplication_method_entry) {
	PHP_ME(PhalconPlus_Mvc_PsrApplication, setPsrRequest, arginfo_phalconplus_mvc_psrapplication_setpsrrequest, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Mvc_PsrApplication, getPsrRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Mvc_PsrApplication, getNativeRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Mvc_PsrApplication, __construct, arginfo_phalconplus_mvc_psrapplication___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Mvc_PsrApplication, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(PhalconPlus_Mvc_PsrApplication, handle, arginfo_phalconplus_mvc_psrapplication_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
