
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Formatter_LinePlus) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Formatter, LinePlus, phalconplus, logger_formatter_lineplus, zephir_get_internal_ce(SL("phalcon\\logger\\formatter\\line")), phalconplus_logger_formatter_lineplus_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_formatter_lineplus_ce, SL("processors"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(phalconplus_logger_formatter_lineplus_ce, SL("formatString"), "[%date%][%type%] %message%", ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_logger_formatter_lineplus_ce->create_object = zephir_init_properties_PhalconPlus_Logger_Formatter_LinePlus;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *formatString_param = NULL;
	zval formatString;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&formatString);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatString_param);

	if (UNEXPECTED(Z_TYPE_P(formatString_param) != IS_STRING && Z_TYPE_P(formatString_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'formatString' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(formatString_param) == IS_STRING)) {
		zephir_get_strval(&formatString, formatString_param);
	} else {
		ZEPHIR_INIT_VAR(&formatString);
		ZVAL_EMPTY_STRING(&formatString);
	}


	if (!(ZEPHIR_IS_EMPTY(&formatString))) {
		zephir_update_property_zval(this_ptr, SL("formatString"), &formatString);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, format) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *item, item_sub, message, type, timestamp, context, _0, _1, _2, _3, matches, result, _4, _5, _6, replace0, replace1, val1, val2, processors, *_10, _11, logStr, _19, _20, _7$$3, _8$$3, _9$$3, _12$$4, _13$$5, _15$$6, _16$$7, _17$$8, _18$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&timestamp);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&replace0);
	ZVAL_UNDEF(&replace1);
	ZVAL_UNDEF(&val1);
	ZVAL_UNDEF(&val2);
	ZVAL_UNDEF(&processors);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&logStr);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item);



	ZEPHIR_CALL_METHOD(&message, item, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&type, item, "gettype", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&timestamp, item, "gettime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&context, item, "getcontext", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "message");
	zephir_update_property_array(this_ptr, SL("processors"), &_0, &message);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_2, "date", NULL, 37, &_1, &timestamp);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "date");
	zephir_update_property_array(this_ptr, SL("processors"), &_1, &_2);
	ZEPHIR_CALL_METHOD(&_2, item, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "type");
	zephir_update_property_array(this_ptr, SL("processors"), &_3, &_2);
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	zephir_read_property(&_4, this_ptr, SL("formatString"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/%(\\w+)%/");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/%(\\w+)%/");
	ZEPHIR_INIT_VAR(&result);
	zephir_preg_match(&result, &_6, &_4, &matches, 1, 0 , 0  TSRMLS_CC);
	if (ZEPHIR_IS_FALSE(&result)) {
		ZEPHIR_INIT_VAR(&_7$$3);
		object_init_ex(&_7$$3, spl_ce_InvalidArgumentException);
		zephir_read_property(&_8$$3, this_ptr, SL("formatString"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZEPHIR_CONCAT_SV(&_9$$3, "Logger format is not valid: ", &_8$$3);
		ZEPHIR_CALL_METHOD(NULL, &_7$$3, "__construct", NULL, 15, &_9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "phalconplus/Logger/Formatter/LinePlus.zep", 37 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MAKE_REF(&matches);
	ZEPHIR_CALL_FUNCTION(&replace0, "reset", NULL, 50, &matches);
	ZEPHIR_UNREF(&matches);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&matches);
	ZEPHIR_CALL_FUNCTION(&replace1, "end", NULL, 35, &matches);
	ZEPHIR_UNREF(&matches);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&processors);
	array_init(&processors);
	zephir_is_iterable(&replace1, 0, "phalconplus/Logger/Formatter/LinePlus.zep", 54);
	if (Z_TYPE_P(&replace1) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&replace1), _10)
		{
			ZEPHIR_INIT_NVAR(&val1);
			ZVAL_COPY(&val1, _10);
			ZEPHIR_OBS_NVAR(&val2);
			zephir_read_property(&_12$$4, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset_fetch(&val2, &_12$$4, &val1, 0 TSRMLS_CC)) {
				ZEPHIR_CALL_FUNCTION(&_13$$5, "strval", &_14, 31, &val2);
				zephir_check_call_status();
				zephir_array_update_zval(&processors, &val1, &_13$$5, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_15$$6);
				ZVAL_STRING(&_15$$6, "undefined");
				zephir_array_update_zval(&processors, &val1, &_15$$6, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &replace1, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_11, &replace1, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&val1, &replace1, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&val2);
				zephir_read_property(&_16$$7, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset_fetch(&val2, &_16$$7, &val1, 0 TSRMLS_CC)) {
					ZEPHIR_CALL_FUNCTION(&_17$$8, "strval", &_14, 31, &val2);
					zephir_check_call_status();
					zephir_array_update_zval(&processors, &val1, &_17$$8, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_18$$9);
					ZVAL_STRING(&_18$$9, "undefined");
					zephir_array_update_zval(&processors, &val1, &_18$$9, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &replace1, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val1);
	ZEPHIR_CALL_FUNCTION(&_2, "array_values", NULL, 21, &processors);
	zephir_check_call_status();
	zephir_read_property(&_19, this_ptr, SL("formatString"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&logStr);
	zephir_fast_str_replace(&logStr, &replace0, &_2, &_19 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_20);
	ZEPHIR_MM_GET_CONSTANT(&_20, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, &logStr, &_20);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, addProcessor) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *processor, processor_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&processor_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &processor);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("processors"), &name, processor);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, getProcessor) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _3, _4, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Processor name is not valid: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 15, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Logger/Formatter/LinePlus.zep", 67 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/Logger/Formatter/LinePlus.zep", 69 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0, _1, _2;
	zval key, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &key))) {
		RETURN_MM_STRING("undefined");
	}
	zephir_read_property(&_1, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch(&_2, &_1, &key, PH_NOISY, "phalconplus/Logger/Formatter/LinePlus.zep", 77 TSRMLS_CC);
	zephir_get_strval(&_3, &_2);
	RETURN_CTOR(&_3);

}

zend_object *zephir_init_properties_PhalconPlus_Logger_Formatter_LinePlus(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("processors"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

