namespace PhalconPlus\Assert;
use PhalconPlus\Enum\AssertionCode;
use PhalconPlus\Assert\InvalidArgumentException;

/**
 *
 * @ref https://github.com/beberlei/assert
 */
class Assertion
{
    protected static function createException(value, message, code, propertyPath, array constraints = [])
    {
        return new InvalidArgumentException(message, code, propertyPath, value, constraints);
    }

    public static function eq(var value1, var value2, var message = null, var propertyPath = null) -> boolean
    {
        if value1 != value2 {
            var v1, v2;
            let v1 = self::stringify(value1);
            let v2 = self::stringify(value2);

            if message === null {
                let message = "Value " . v1 . " does not equal expected value " . v2 . ".";
            }

            throw static::createException(value1, message, AssertionCode::INVALID_SAME, propertyPath, ["expected": value2]);
        }

        return true;
    }

    public static function notEq(var value1, var value2, var message = null, var propertyPath = null) -> boolean
    {
        if value1 == value2 {
            let message = sprintf(
                message ? message : "Value \"%s\" is equal to expected value \"%s\".",
                static::stringify(value1),
                static::stringify(value2)
            );

            throw static::createException(value1, message, AssertionCode::INVALID_NOT_EQ, propertyPath, ["expected": value2]);
        }

        return true;
    }

    public static function same(var value1, var value2, var message = null, var propertyPath = null) -> boolean
    {
        if value1 !== value2 {
            var v1, v2;
            let v1 = self::stringify(value1);
            let v2 = self::stringify(value2);

            if message === null {
                let message = "Value " . v1 . " does not equal expected value " . v2 . ".";
            }

            throw static::createException(value1, message, AssertionCode::INVALID_EQ, propertyPath
                                          , ["expected": value2]);
        }

        return true;
    }

    public static function notEmpty(var value, var message = null, var propertyPath = null) -> boolean
    {
        if empty value {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is empty, but non empty value was expected.";
            }
            throw static::createException(value, message, AssertionCode::VALUE_EMPTY, propertyPath);
        }

        return true;
    }

    public static function notNull(var value, var message = null, var propertyPath = null) -> boolean
    {
        if value === null {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is null, but non null value was expected.";
            }
            throw static::createException(value, message, AssertionCode::VALUE_NULL, propertyPath);
        }
        return true;
    }

    public static function notBlank(var value, var message = null, var propertyPath = null) -> boolean | null
    {
        if false === value || (empty(value) && "0" != value) || (is_string(value) && "" === trim(value)) {
            let message = sprintf(
                message ? message : "Value \"%s\" is blank, but was expected to contain a value.",
                static::stringify(value)
            );
            throw static::createException(value, message, AssertionCode::INVALID_NOT_BLANK, propertyPath);
        }
        return true;
    }

    public static function integer(var value, var message = null, var propertyPath = null) -> boolean
    {
        if !\is_int(value) {
            if message === null {
                let message = \sprintf(
                    message ? message : "Value \"%s\" is not an integer.", 
                    static::stringify(value)
                );
            }
            throw static::createException(value, message, AssertionCode::INVALID_INTEGER, propertyPath);
        }
        return true;
    }

    public static function numeric(var value, var message = null, var propertyPath = null) -> boolean
    {
        if !is_numeric(value) {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is not numeric.";
            }
            throw static::createException(value, message, AssertionCode::INVALID_NUMERIC, propertyPath);
        }

        return true;
    }

    public static function range(var value, int minValue, int maxValue, var message = null, var propertyPath = null) -> boolean
    {
        static::numeric(value, message, propertyPath);
        if value < minValue || value > maxValue {
            let message = sprintf(
                message ? message : "Number \"%s\" was expected to be at least \"%d\" and at most \"%d\".",
                static::stringify(value),
                minValue,
                maxValue
            );
            throw static::createException(value, message, AssertionCode::INVALID_RANGE, propertyPath
                                          , ["min": minValue, "max": maxValue]);
        }

        return true;
    }

    public static function minLength(var value, int minLength, var message = null, var propertyPath = null, string encodeing = "utf8") -> boolean | null
    {
        static::isString(value, message, propertyPath);
        if mb_strlen(value, encodeing) < minLength {
            let message = sprintf(
                message ? message : "Value \"%s\" is too short, it should at least %d characters, but only has %d characters.",
                static::stringify(value),
                minLength,
                mb_strlen(value, encodeing)
            );
            throw static::createException(value, message, AssertionCode::INVALID_MIN_LENGTH, propertyPath
                                          , ["min_length": minLength, "encoding": encodeing]);
        }
        return true;
    }
    
    public static function maxLength(var value, int maxLength, var message = null, var propertyPath = null, string encodeing = "utf8") -> boolean | null
    {
        static::isString(value, message, propertyPath);
        if mb_strlen(value, encodeing) > maxLength {
            let message = sprintf(
                message ? message : "Value \"%s\" is too long, it should no more than %d characters, but has %d characters.",
                static::stringify(value),
                maxLength,
                mb_strlen(value, encodeing)
            );
            throw static::createException(value, message, AssertionCode::INVALID_MAX_LENGTH, propertyPath
                                          , ["max_length": maxLength, "encoding": encodeing]);
        }
        return true;
    }

    public static function betweenLength(var value, int minLength, int maxLength, var message = null, var propertyPath = null, string encodeing = "utf8") -> boolean | null
    {
        static::isString(value, message, propertyPath);
        static::minLength(value, minLength, message, propertyPath, encodeing);
        static::maxLength(value, maxLength, message, propertyPath, encodeing);
        return true;
    }

    public static function min(var value, int minValue, var message = null, var propertyPath = null) -> boolean
    {
        static::numeric(value, message, propertyPath);

        if value < minValue {
            let message = sprintf(
                message ? message : "Number \"%s\" was expected to be at least \"%s\".",
                static::stringify(value),
                static::stringify(minValue)
            );
            throw static::createException(value, message, AssertionCode::INVALID_MIN, propertyPath
                                          , ["min": minValue]);
        }

        return true;
    }

    public static function max(var value, int maxValue, var message = null, var propertyPath = null) -> boolean
    {
        static::numeric(value, message, propertyPath);

        if value > maxValue {
            let message = sprintf(
                message ? message : "Number \"%s\" was expected to be at most \"%s\".",
                static::stringify(value),
                static::stringify(maxValue)
            );
            throw static::createException(value, message, AssertionCode::INVALID_MAX, propertyPath
                                          , ["max": maxValue]);
        }

        return true;
    }

    public static function contains(var value, var needle, var message = null, var propertyPath = null, string encodeing = "utf8") -> boolean | null
    {
        static::isString(value, message, propertyPath);
        if false === mb_strpos(value, needle, null, encodeing) {
            let message = sprintf(
                message ? message : "Value \"%s\" does not contain \"%s\".",
                static::stringify(value),
                static::stringify(needle)
            );
            throw static::createException(value, message, AssertionCode::INVALID_STRING_CONTAINS, propertyPath
                                          , ["needle": needle, "encoding" : encodeing]);
        }
        return true;
    }

    public static function notContains(var value, var needle, var message = null, var propertyPath = null, string encodeing = "utf8") -> boolean | null
    {
        static::isString(value, message, propertyPath);
        if false !== mb_strpos(value, needle, null, encodeing) {
            let message = sprintf(
                message ? message : "Value \"%s\" contain \"%s\".",
                static::stringify(value),
                static::stringify(needle)
            );
            throw static::createException(value, message, AssertionCode::INVALID_STRING_NOT_CONTAINS, propertyPath
                                          , ["needle": needle, "encoding" : encodeing]);
        }
        return true;
    }

    public static function inArray(var value, array choices, var message = null, var propertyPath = null)
    {
        if !in_array(value, choices, true) {
            let message = sprintf(
                message ? message : "Value \"%s\" is not an element of the valid values: %s",
                static::stringify(value),
                implode(", ", array_map([get_called_class(), "stringify"], choices))
            );
            throw static::createException(value, message, AssertionCode::INVALID_CHOICE, propertyPath
                                          , ["choices" : choices]);
        }
        return true;
    }

    public static function keyExists(var value, var key, var message = null, var propertyPath = null) -> boolean | null
    {
        static::isArray(value, message, propertyPath);
        if !array_key_exists(key, value) {
            let message = sprintf(
                message ? message : "Array does not contain an element with key \"%s\"",
                static::stringify(key)
            );
            throw static::createException(value, message, AssertionCode::INVALID_KEY_EXISTS, propertyPath
                                          , ["key" : key]);
        }
        return true;
    }

    public static function isResource(var value, var message = null, var propertyPath = null) -> boolean | null
    {
        if !is_resource(value) {
            let message = sprintf(
                message ? message : "Value \"%s\" is not a resource",
                static::stringify(value)
            );
            throw static::createException(value, message, AssertionCode::INVALID_RESOURCE, propertyPath);
        }
        return true;
    }

    public static function isString(var value, var message = null, var propertyPath = null) -> boolean
    {
        if !is_string(value) {
            let message = sprintf(
                message ? message : "Value \"%s\" expected to be string, type %s given.",
                static::stringify(value),
                gettype(value)
            );
            throw static::createException(value, message, AssertionCode::INVALID_STRING, propertyPath);
        }

        return true;
    }

    public static function isArray(var value, var message = null, var propertyPath = null) -> boolean
    {
        if !is_array(value) {
            let message = sprintf(
                message ? message : "Value \"%s\" is not an array.",
                static::stringify(value)
            );
            throw static::createException(value, message, AssertionCode::INVALID_ARRAY, propertyPath);
        }
        return true;
    }

     public static function isTraversable(value, var message = null, string propertyPath = null) -> boolean
     {
         if !is_array(value) && !is_object(value) && !(value instanceof \Traversable) {
             let message = sprintf(
                 message ? message : "Value \"%s\" is not an array and does not implement Traversable.",
                 static::stringify(value)
             );
             throw static::createException(value, message, AssertionCode::INVALID_TRAVERSABLE, propertyPath);
         }
         return true;
     }
 
     public static function isArrayAccessible(value, var message = null, string propertyPath = null) -> boolean
     {
         if !is_array(value) && !is_object(value) && !(value instanceof \ArrayAccess) {
             let message = sprintf(
                 message ? message : "Value \"%s\" is not an array and does not implement ArrayAccess.",
                 static::stringify(value)
             );
             throw static::createException(value, message, AssertionCode::INVALID_ARRAY_ACCESSIBLE, propertyPath);
         }
         return true;
     }
 
     public static function isCountable(value, var message = null, string propertyPath = null) -> boolean
     {
         var assert;
         if (function_exists("is_countable")) {
             let assert = is_countable(value);
         } else {
             let assert = is_array(value) || (is_object(value) && (value instanceof \Countable || value instanceof \ResourceBundle || value instanceof \SimpleXMLElement));
         }
         if !assert {
             let message = sprintf(
                 message ? message : "Value \"%s\" is not an array and does not implement Countable.",
                 static::stringify(value)
             );
             throw static::createException(value, message, AssertionCode::INVALID_COUNTABLE, propertyPath);
         }
         return true;
     }

    public static function isInstanceOf(object value, var classNames, var message = null, var propertyPath = null) -> bool
    {
        string classItem;
        bool result = false;
        if is_string(classNames) {
            let classItem = classNames;
            if value instanceof classItem { 
                let result = true;
            }
        } elseif is_array(classNames) { // instance of anyone of classNames
            var tmp;
            for tmp in classNames {
                let classItem = tmp;
                if value instanceof classItem {
                    let result = true;
                    break;
                }
            }
        }
        if result === false {
            let message = sprintf(
                message ? message : "Class \"%s\" was expected to be instanceof of \"%s\" but is not.",
                static::stringify(value),
                classItem
            );
            throw static::createException(value, message, AssertionCode::INVALID_INSTANCE_OF, propertyPath, ["class" : classItem]);
        }
        return true;
    }

    public static function isJsonString(var value, var message = null, var propertyPath = null, <\ArrayObject> obj = null) -> boolean
    {
        static::isString(value, message, propertyPath);
        var data = json_decode(value, true);
        if null == data && JSON_ERROR_NONE != json_last_error() {
            let message = sprintf(
                message ? message : "Value \"%s\" is not a valid JSON string.",
                static::stringify(value)
            );

            throw static::createException(value, message, AssertionCode::INVALID_JSON_STRING, propertyPath);
        }
        if is_object(obj) {
            obj->exchangeArray(data);
        }
        return true;
    }

    private static function stringify(value)
    {
        if is_bool(value) {
            return value == true ? "TRUE" : "FALSE";
        }

        if value === NULL { return "NULL"; }

        var val;
        if is_scalar(value) {
            let val = (string) value;
            if strlen(val) > 100 {
                let val = substr(val, 0, 96) . " ...";
            }
            return val;
        }

        if is_array(value) || is_object(value) || is_resource(value) {
            let val = print_r(value, true);
            let val = preg_replace("/\s+/", " ", val);
            if strlen(val) > 160 {
                return substr(val, 0, 156) . " ...";
            }
            return val;
        }

        return "unknown";
    }
}
