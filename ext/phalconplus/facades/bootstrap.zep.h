
extern zend_class_entry *phalconplus_facades_bootstrap_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Facades_Bootstrap);

PHP_METHOD(PhalconPlus_Facades_Bootstrap, getName);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_bootstrap_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_bootstrap_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_facades_bootstrap_method_entry) {
	PHP_ME(PhalconPlus_Facades_Bootstrap, getName, arginfo_phalconplus_facades_bootstrap_getname, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
