namespace PhalconPlus\Base;
use PhalconPlus\Base\Pagable;
use PhalconPlus\Assert\Assertion as Assert;
use Phalcon\Db\AdapterInterface;
use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Db\AdapterInterface;
use Phalcon\Mvc\Model\Resultset;

// use Phalcon\Mvc\Model;
// use Phalcon\Mvc\ModelMessage;
// use Phalcon\Db\RawValue;

class Model extends \Phalcon\Mvc\Model
{
    // 记录创建时间
    public ctime;
    // 记录更新时间
    public mtime;

    protected __p_UK = [];

    public function initialize()
    {
        self::setUp([
            "notNullValidations" : false,
            "castOnHydrate" : true,
            "forceCasting" : true
        ]);
        this->useDynamicUpdate(true);
        this->keepSnapshots(true);
    }

    public function getMessage()
    {
        return this->getFirstMessage();
    }

    public function getFirstMessage()
    {
        if count(this->getMessages("")) {
            return (string) current(this->getMessages(""));
        }
        return false;
    }

    public function getLastMessage()
    {
        if count(this->getMessages("")) {
            return (string) end(this->getMessages(""));
        }
        return false;
    }

    public function createBuilder(string! alias = "") -> <\Phalcon\Mvc\Model\Query\BuilderInterface>
    {
        var source;
        if !empty alias {
            let source = [alias:get_called_class()];
        } else {
            let source  = get_called_class();
        }
        return this->getModelsManager()->createBuilder()->from(source);
    }

    /**
     * @deprecated 非单例，不建议用此方法名称，将在以后移除
     */
    public static function getInstance() -> <\Phalcon\Mvc\Model>
    {
        var className;
        let className = get_called_class();
        return new {className}();
    }

    public static function newInstance() -> <\Phalcon\Mvc\Model>
    {
        var className;
        let className = get_called_class();
        return new {className}();
    }

    public static function batchInsert(array columns, array rows)
    {
        var model, conn, e, row;
        var columnMap = [], newColumns = [];

        var className;
        let className = get_called_class();
        let model = new {className}();

        if method_exists(model, "columnMap") {
            let columnMap = array_flip(model->columnMap());
            var val;
            for val in columns {
                if isset(columnMap[val]) {
                    let newColumns[] = columnMap[val];
                }
            }
        } else {
            let newColumns = columns;
        }
        let conn = model->getWriteConnection();
        try {
            conn->begin();
            for row in rows {
                conn->insert(model->getSource(), row, newColumns);
            }
            conn->commit();
        } catch \Exception, e {
            conn->rollback();
            throw e;
        }

        return true;
    }

    public function beforeValidationOnCreate()
    {
        let this->ctime = date("Y-m-d H:i:s");
        let this->mtime = this->ctime;
    }

    public function afterFetch()
    {
        // nothing
    }

    public function beforeCreate()
    {
        let this->ctime = date("Y-m-d H:i:s");
        let this->mtime = this->ctime;
    }

    public function beforeSave()
    {
        let this->mtime = date("Y-m-d H:i:s");
        return true;
    }

    /**
     * find with paginator
     * @var array params
     *    - params["columns"]
     *    - params["conditions"]
     *    - params["bind"]
     *    - params["hydration"]: \Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS | HYDRATE_ARRAYS | HYDRATE_RECORDS
     *
     */
    public function findByPagable(<Pagable> pagable, array params = [])
    {
        Assert::notNull(pagable, __CLASS__."::".__METHOD__ .": Pagable can not be null");

        var builder;
        let builder = this->createBuilder();

        var val, orderBys = [];

        let orderBys = array_map("strval", pagable->getOrderBys());
        if !empty orderBys {
            // error_log(var_export(orderBys, true));
            builder->orderBy(implode(", ", orderBys));
        }

        if fetch val, params["columns"] {
            builder->columns(val);
        } else {
            builder->columns("*");
        }

        var bind = [];
        if fetch val, params["bind"] {
            let bind = val;
        }

        if fetch val, params["conditions"] {
            if empty bind {
                builder->where(val);
            } else {
                builder->where(val, bind);
            }
        }
        var queryBuilder, page;
        let queryBuilder = new \Phalcon\Paginator\Adapter\QueryBuilder([
            "builder":builder,
            "limit":pagable->getPageSize(),
            "page":pagable->getPageNo()
        ]);

        let page = queryBuilder->paginate();

        if typeof page->getItems() == "object" {
            var hydration;
            if fetch hydration, params["hydration"] {
                page->getItems()->setHydrateMode(hydration);
            }
        }

        return new Page(pagable, page->getTotalItems(), page->getItems());
    }

    /**
     * Check if a reord is already exists?
     */
    public function exists() -> boolean
    {
        var metaData, readConnection, schema, source, table;
        let
            metaData = this->getModelsMetaData(),
            readConnection = this->getReadConnection();
        let
            schema = this->getSchema(),
            source = this->getSource();

        if schema {
            let table = [schema, source];
        } else {
            let table = source;
        }

        if !empty this->__p_UK {
            this->_p_buildUkCond(metaData, readConnection);
        }

        if this->_exists(metaData, readConnection, table) {
            return true;
        } else {
            return false;
        }
    }
   
    /**
     * @alias setUpdateCondition()
     * @deprecated
     */
    public function setUpdateCond(array params)
    {
        return this->setUpdateCondition(params);
    }

    /**
     * 如果想在更新某条记录的时候额外加入其他条件，可以使用此方法
     * where = [
         'id > ?',  // 占位符仅支持?形式，不支持:placeHolder这种形式
         'bind' => [
             14
         ]
     ];
     */
    public function setUpdateCondition(array params)
    {
        var metaData, writeConnection, columnMap, bindDataTypes, primaryKeys, attributeField;
        var pk, value, type;
        var whereUk = [], uniqueParams = [], uniqueTypes = [];

        let metaData = this->getModelsMetaData(),
            writeConnection = this->getWriteConnection(),
            columnMap = metaData->getColumnMap(this),
            bindDataTypes = metaData->getBindTypes(this);

        let primaryKeys = metaData->getPrimaryKeyAttributes(this);
        for pk in primaryKeys {
            /**
             * Check if the model has a column map
             */
            if typeof columnMap == "array" {
                if !fetch attributeField, columnMap[pk] {
                    throw new \PhalconPlus\Base\Exception("Model::setUpdateCond: Column '" . pk . "' isn't part of the column map");
                }
            } else {
                let attributeField = pk;
            }

            if !fetch type, bindDataTypes[pk] {
                throw new \PhalconPlus\Base\Exception("Model::setupdateCond: Column '" . pk . "' isn't part of the table columns");
            }

            if fetch value, this->{attributeField} {
                let uniqueParams[] = value;
            } else {
                let uniqueParams[] = null;
            }

            let whereUk[] = writeConnection->escapeIdentifier(pk) . " = ?";
            let uniqueTypes[] = type;
        }

        /**
         * Process conditions
         */
        var conditions, bind, bindTypes;
        if fetch conditions, params[0] {
        } else {
            if fetch conditions, params["conditions"] {
            }
        }

        if !empty this->uniqueKey {
            let this->uniqueKey = this->uniqueKey . " AND ";
        }
        if typeof conditions == "array" {
            merge_append(whereUk, conditions);
            let this->uniqueKey = this->uniqueKey . join(" AND ", whereUk);
        } elseif typeof conditions == "string" {
            let conditions = join(" AND ", whereUk) . " AND " . conditions;
            let this->uniqueKey = this->uniqueKey . conditions;
        }

        let this->uniqueKey = str_replace(array_values(columnMap), array_keys(columnMap), this->uniqueKey);

        var countKeys = substr_count(this->uniqueKey, "= ?");

        /**
         * Assign bind types
         */
        if fetch bind, params["bind"] {
            merge_append(uniqueParams, bind);
        }

        if this->uniqueParams == null {
            let this->uniqueParams = [];
        }
        merge_append(this->uniqueParams, uniqueParams);
        let this->uniqueParams = array_pad(this->uniqueParams, countKeys, null);

        if fetch bindTypes, params["bindTypes"] {
            merge_append(uniqueTypes, bindTypes);
        }

        if this->uniqueTypes == null {
            let this->uniqueTypes = [];
        }
        merge_append(this->uniqueTypes, uniqueTypes);
        let this->uniqueTypes = array_pad(this->uniqueTypes, countKeys, \Phalcon\Db\Column::BIND_SKIP);
        return true;
    }

    /**
     * @alias setUniqueKeys
     * @deprecated
     */
    public function setUqKeys(array whereUk)
    {
        return $this->setUniqueKeys(whereUk);
    }

    /**
     * columnMap field
     */
    public function setUniqueKeys(array whereUk)
    {
        /**
         * field 数据库字段
         * attributeField columnMap之后的字段
         */
        var field, attributeField, type, metaData, columnMap, bindDataTypes;

        let metaData = this->getModelsMetaData();
        let columnMap = metaData->getColumnMap(this);
        let bindDataTypes = metaData->getBindTypes(this);

        for attributeField in whereUk {
            if typeof columnMap == "array" {
                var tmp;
                let tmp = array_flip(columnMap);
                if !fetch field, tmp[attributeField] {
                    throw new \PhalconPlus\Base\Exception("Model::setUqKeys: Column '" . attributeField . "' isn't part of the column map");
                }
            } else {
                let field = attributeField;
            }

            let this->__p_UK[attributeField]["field"] = field;

            if !fetch type, bindDataTypes[field] {
                throw new \PhalconPlus\Base\Exception("Model::setUqKeys: Column '" . field . "' isn't part of the table columns");
            }
            let this->__p_UK[attributeField]["type"] = type;
            let this->__p_UK[attributeField]["op"] = "=";
        }
        return this;
    }

    protected function _p_buildUkCond(<MetaDataInterface> metaData, <AdapterInterface> connection)
    {
        var value, type, info, field, whereUk, uniqueParams, uniqueTypes, attributeField;

        let whereUk = [],
        uniqueParams = [],
        uniqueTypes = [];

        for attributeField, info in this->__p_UK {
            let type = info["type"],
            field = info["field"],
            value = null;
            if fetch value, this->{attributeField} {
                var selfVal;
                if fetch selfVal, info["value"] {
                    let uniqueParams[] = selfVal;
                } else {
                    let uniqueParams[] = value;
                }
            } else {
                let uniqueParams[] = null;
            }
            let uniqueTypes[] = type,
                whereUk[] = connection->escapeIdentifier(field) . " ".info["op"]." ?";
        }

        var usefulParams = [];
        let usefulParams = array_filter(uniqueParams, function(elem){
            return !empty elem; // in zephir, empty means `null`, `empty string` and `empty array` 
        });

        if empty usefulParams {  // if no ukField is defined
            return false;
        }

        let this->uniqueKey = join(" AND ", whereUk),
        this->uniqueParams = uniqueParams,
        this->uniqueTypes = uniqueTypes;
        return true;
    }

    public function getUniqueFields()
    {
        return [
            "key" : this->uniqueKey,
            "params" : this->uniqueParams,
            "types" : this->uniqueTypes
        ];
    }

    public function toProtoBuffer(columns = null) -> <ProtoBuffer>
    {
        var proto, toArray, key, val;
        let toArray = this->toArray(columns);
        let proto = new ProtoBuffer();
        for key, val in toArray {
            let proto->{key} = is_scalar(val)?val:strval(val);
        }
        var modelName, manager, relations, referenceModel, referencedEntity, options, alias, lowerAlias;

		let modelName = get_class(this), manager = this->getModelsManager();
        let relations = manager->getRelations(modelName);
        for val in relations {
            let referenceModel = val->getReferencedModel();
            let referencedEntity = strtolower(referenceModel);
            let options = val->getOptions();
            if fetch alias, options["alias"] {
                if typeof alias != "string" {
                    throw new \Exception("Relation alias must be a string");
                }
                let lowerAlias = strtolower(alias);
            } else {
                let lowerAlias = referencedEntity;
            }
            var method, property;
            let method = "get".alias;
            let property = lcfirst(alias);
            let proto->{property} = this->{method}()->toArray();
        }
        return proto;
    }
}
