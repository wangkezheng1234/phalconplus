namespace PhalconPlus\Db\UnitOfWork;
use \PhalconPlus\Db\UnitOfWork;

class Field extends AbstractValue
{
    protected model = null;
    protected attr = "";

    public function __construct(<\Phalcon\Mvc\Model> model, string! attr)
    {
        let this->model = model;
        let this->attr = attr;
    }

    public function getValue(<UnitOfWork> unitwork)
    {
        var className = get_class(this->model);
        var hash = spl_object_hash(this->model);
        var objs = unitwork->getObjects();

        if objs->contains(this->model) {
            var attr = this->attr;
            if property_exists(this->model, attr) {
                return this->model->{attr};
            }
            return null;
        }

        throw new \PhalconPlus\Base\Exception("Object(".hash.") instance of ".className." not in SplObjectStorage");
    }

    public function getField(<UnitOfWork> unitwork)
    {
        return this->getValue(unitwork);
    }

    public function __toString()
    {
        return "Field: " . this->attr . ", Hash: " . spl_object_hash(this->model);
    }
}
