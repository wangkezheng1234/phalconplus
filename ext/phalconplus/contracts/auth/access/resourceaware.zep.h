
extern zend_class_entry *phalconplus_contracts_auth_access_resourceaware_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_Access_ResourceAware);

ZEPHIR_INIT_FUNCS(phalconplus_contracts_auth_access_resourceaware_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_ResourceAware, register, NULL)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_ResourceAware, control, NULL)
	PHP_FE_END
};
