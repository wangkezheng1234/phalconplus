namespace PhalconPlus\Rpc\Client\Adapter;
use PhalconPlus\Rpc\Client\AbstractClient;
use PhalconPlus\Base\ProtoBuffer;
use PhalconPlus\Base\Exception as BaseException;

class Local extends AbstractClient
{
    private config;

    private di;

    public function __construct(<\Phalcon\DI> di)
    {
        let this->di = di;
        let this->config = di->get("config");
    }

    private function callByParams(string! service, string! method, <ProtoBuffer> request) -> <ProtoBuffer>
    {
        var serviceClass, serviceObj, response;

        let serviceClass = service->upperfirst() . "Service";

        if !class_exists(serviceClass) {
            throw new BaseException("Service class not exists: " . serviceClass);
        }

        let serviceObj = new {serviceClass}(this->di);

        if is_callable([serviceObj, method]) {
            error_log("ServerClass: " . serviceClass);
            error_log("InvokeMethod: " . method);
            error_log("InputParam: " . var_export(request, true));
            // We expect only Array or Object
            if !is_object(request) && !is_array(request) {
                throw new BaseException("Your input is not allowed. Request: " . json_encode(request));
            }
            // If get an object, must be instance of <ProtoBuffer> or it's subclasses
            if is_object(request) && !(request instanceof ProtoBuffer) {
                throw new BaseException("Your input is not allowed. Request: ". get_class(request));
            } elseif is_array(request) {
                var tmp = [], param, paramClass;
                let tmp = request;
                let param = new \ReflectionParameter([serviceClass, method], 0);
                if param->getClass() {
                    let paramClass = param->getClass()->getName();
                    let request = new {paramClass}();
                    request->softClone(tmp);
                } else {
                    throw new BaseException("Service class:method definition is invalid. Detail: " . service . " : " . method . ". Request: " . json_encode(request));
                }
            }

            error_log("Finally InputParam: ". var_export(request, true));

            let response = call_user_func_array([serviceObj, method], [request]);

            return response;

        } else {
            throw new BaseException("No service found: " . serviceClass . "::" . method);
        }
    }

    public function callByObject(array rawData)
    {
        var service, method, request;
        
        error_log("Local callByObject: " . var_export(rawData, true));

        if !fetch service, rawData["service"] {
            throw new BaseException("service " . service . " not exists");
        }

        if !fetch method, rawData["method"] {
            throw new BaseException("method " . method . " not exists");
        }

        if !fetch request, rawData["args"] {
            throw new BaseException("args not exists");
        }

        let service = this->namePrefix . trim(service);

        let method = trim(method);

        if empty service || empty method {
            throw new BaseException("service:method(args) must exists. All of them!!!");
        }

        error_log("Invoke callByParams with (" . service . ", " . method . ")");
		
        return this->callByParams(service, method, request);
    }
}

