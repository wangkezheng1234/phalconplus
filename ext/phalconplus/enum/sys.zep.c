
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Sys) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, Sys, phalconplus, enum_sys, phalconplus_enum_abstractenum_ce, phalconplus_enum_sys_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_string(phalconplus_enum_sys_ce, SL("rootDir"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_string(phalconplus_enum_sys_ce, SL("primaryModuleDir"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_bool(phalconplus_enum_sys_ce, SL("facadesLoaded"), 0, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("COMMON_NAME"), "common");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("CONF_NAME"), "config");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("LOAD_NAME"), "load");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("PUB_NAME"), "public");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("APP_NAME"), "app");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("DS"), "/");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("EXT"), ".php");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("ENV_NAME"), "phalconplus.env");

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_Sys, init) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDir_param = NULL, _0, _1, _2, _3, _6, _4$$4;
	zval moduleDir, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	if (UNEXPECTED(Z_TYPE_P(moduleDir_param) != IS_STRING && Z_TYPE_P(moduleDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleDir' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleDir_param) == IS_STRING)) {
		zephir_get_strval(&moduleDir, moduleDir_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleDir);
		ZVAL_EMPTY_STRING(&moduleDir);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("primaryModuleDir"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_trim(&_1, &moduleDir, &_2, ZEPHIR_TRIM_RIGHT);
	zephir_get_strval(&moduleDir, &_1);
	ZEPHIR_CALL_FUNCTION(&_3, "is_dir", NULL, 43, &moduleDir);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, "Module directory not exists or not a dir, file positon: ", &moduleDir);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 25, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalconplus/Enum/Sys.zep", 29);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalconplus_enum_sys_ce, ZEND_STRL("primaryModuleDir"), &moduleDir);
	ZEPHIR_CALL_FUNCTION(&_6, "dirname", NULL, 108, &moduleDir);
	zephir_check_call_status();
	zephir_update_static_property_ce(phalconplus_enum_sys_ce, ZEND_STRL("rootDir"), &_6);
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getPrimaryModuleDir) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("primaryModuleDir"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getRootDir) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getCommonDir) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "common");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalConfigDir) {

	zval _3;
	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "common");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SS(&_3, "config", ".php");
	zephir_array_fast_append(&_0, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalConfigPath) {

	zval _3;
	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "common");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "config");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SS(&_3, "config", ".php");
	zephir_array_fast_append(&_0, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalLoadDir) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "common");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "load");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleDirByName) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *moduleName_param = NULL, _1, _2;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(&moduleName, moduleName_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &moduleName);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleNameByDir) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDir_param = NULL, _0;
	zval moduleDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	zephir_get_strval(&moduleDir, moduleDir_param);


	ZVAL_LONG(&_0, 8);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 109, &moduleDir, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleClassPath) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDir_param = NULL, *runMode, runMode_sub, _1, _2;
	zval moduleDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&runMode_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &moduleDir_param, &runMode);

	zephir_get_strval(&moduleDir, moduleDir_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0);
	zephir_array_fast_append(&_0, &moduleDir);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "app");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_METHOD(&_2, runMode, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ".php");
	zephir_array_fast_append(&_0, &_1);
	zephir_fast_join_str(return_value, SL(""), &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleConfigPath) {

	zval _0, _3, _7$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *moduleDir_param = NULL, confPrefix, confPath, _1, _2, _4, _5, _9, _8$$3, _10$$4, _11$$4, _12$$4;
	zval moduleDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&confPrefix);
	ZVAL_UNDEF(&confPath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	zephir_get_strval(&moduleDir, moduleDir_param);


	ZEPHIR_INIT_VAR(&confPrefix);
	ZVAL_STRING(&confPrefix, "");
	ZEPHIR_INIT_VAR(&confPath);
	ZVAL_STRING(&confPath, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_trim(&_1, &moduleDir, &_2, ZEPHIR_TRIM_RIGHT);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "app");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "config");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_INIT_NVAR(&confPrefix);
	zephir_fast_join(&confPrefix, &_1, &_0);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0);
	zephir_array_fast_append(&_3, &confPrefix);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_GET_CONSTANT(&_4, "APP_RUN_ENV");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, ".php");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&confPath);
	zephir_fast_join_str(&confPath, SL(""), &_3);
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_6, 46, &confPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_create_array(&_7$$3, 3, 0);
		zephir_array_fast_append(&_7$$3, &confPrefix);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "config");
		zephir_array_fast_append(&_7$$3, &_8$$3);
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, ".php");
		zephir_array_fast_append(&_7$$3, &_8$$3);
		ZEPHIR_INIT_NVAR(&confPath);
		zephir_fast_join_str(&confPath, SL(""), &_7$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_9, "is_file", &_6, 46, &confPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_9))) {
		ZEPHIR_INIT_VAR(&_10$$4);
		object_init_ex(&_10$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_11$$4);
		ZEPHIR_GET_CONSTANT(&_11$$4, "APP_RUN_ENV");
		ZEPHIR_INIT_VAR(&_12$$4);
		ZEPHIR_CONCAT_SVSVS(&_12$$4, "Module Config file not exists: ", &confPath, " & ", &_11$$4, ".php");
		ZEPHIR_CALL_METHOD(NULL, &_10$$4, "__construct", NULL, 25, &_12$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$4, "phalconplus/Enum/Sys.zep", 144);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&confPath);

}

PHP_METHOD(PhalconPlus_Enum_Sys, getComposerAutoloadPath) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "vendor");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "autoload.php");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, aliasFacades) {

	zval facades;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *prefix_param = NULL, __$true, _0, _1, alias, *_2, _3, _4$$4, _5$$4, _6$$5, _7$$5;
	zval prefix, className, classAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&classAlias);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&facades);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	zephir_get_strval(&prefix, prefix_param);


	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("facadesLoaded"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE(&_0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&facades);
	zephir_create_array(&facades, 26, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Annotations");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Assets");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Bootstrap");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Config");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Cookies");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Crypt");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Dispatcher");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Escaper");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "EventsManager");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Filter");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Flash");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "FlashSession");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Log");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ModelsCache");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ModelsManager");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "ModelsMetadata");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Request");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Response");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Router");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Security");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Service");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Session");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "SessionBag");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Tag");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "TransactionManager");
	zephir_array_fast_append(&facades, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Url");
	zephir_array_fast_append(&facades, &_1);
	zephir_is_iterable(&facades, 0, "phalconplus/Enum/Sys.zep", 184);
	if (Z_TYPE_P(&facades) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&facades), _2)
		{
			ZEPHIR_INIT_NVAR(&alias);
			ZVAL_COPY(&alias, _2);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZEPHIR_CONCAT_SV(&_4$$4, "\\PhalconPlus\\Facades\\", &alias);
			zephir_get_strval(&className, &_4$$4);
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZEPHIR_CONCAT_VV(&_5$$4, &prefix, &alias);
			zephir_get_strval(&classAlias, &_5$$4);
			
                zend_class_entry *ce;
                ce = zephir_fetch_class(&className TSRMLS_CC);
                zend_register_class_alias_ex(Z_STRVAL(classAlias), Z_STRLEN(classAlias), ce);
            
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &facades, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_3, &facades, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_3)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&alias, &facades, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZEPHIR_CONCAT_SV(&_6$$5, "\\PhalconPlus\\Facades\\", &alias);
				zephir_get_strval(&className, &_6$$5);
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZEPHIR_CONCAT_VV(&_7$$5, &prefix, &alias);
				zephir_get_strval(&classAlias, &_7$$5);
				
                zend_class_entry *ce;
                ce = zephir_fetch_class(&className TSRMLS_CC);
                zend_register_class_alias_ex(Z_STRVAL(classAlias), Z_STRLEN(classAlias), ce);
            
			ZEPHIR_CALL_METHOD(NULL, &facades, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&alias);
	zephir_update_static_property_ce(phalconplus_enum_sys_ce, ZEND_STRL("facadesLoaded"), &__$true);
	RETURN_MM_BOOL(1);

}

