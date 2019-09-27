namespace PhalconPlus\Logger\Adapter;
use PhalconPlus\Assert\Assertion as Assert;
use Phalcon\Logger\Adapter\AbstractAdapter;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Item;

class FilePlus extends Stream
{
    private type2Handler = [];
    private type2Ext = [];

    private mode; // file open mode

    private _path;
    private _options;
    private _fileHandler;

    public function __construct(string! filePath, array options = [])
    {
        Assert::notEmpty(filePath);

        var mode;
        if fetch mode, options["mode"] {
            if strpos(mode, "r") === false {
                let this->mode = mode;
            } else {
                throw new \InvalidArgumentException("Logger must be opened in append or write mode");
            }
        } else {
            let this->mode = "ab";
        }

        let this->_fileHandler = this->open(filePath);
        let this->_path = filePath;
        let this->_options = options;

        // store default file handler with index -1
        let this->type2Handler[-1] = this->_fileHandler;
        let this->type2Ext[-1] = "";

        let this->handler = this->_fileHandler;
    }

    private function open(string! filePath)
    {
        var handler = null;
        let handler = fopen(filePath, this->mode);
        if handler == false {
            throw new \Exception("Cannot open log file " . filePath);
        }
        return handler;
    }
    
    public function process(<Item> item) -> void
    {
        var handler, formatter, formattedMessage;

        if fetch handler, this->type2Handler[item->getType()] {
            // nothing
        } else {
            let handler = this->type2Handler[-1];
        }

        let formatter        = this->getFormatter(),
            formattedMessage = formatter->format(item);

        fwrite(handler, formattedMessage);
    }

    public function registerExtension(string! ext, array types)
    {
        Assert::notEmpty(ext);
        Assert::notEmpty(types);

        var filePath, type, fileHandler;
        let filePath  = this->_path . ext;
        let fileHandler = this->open(filePath);
        for type in types {
            let this->type2Handler[type] = fileHandler;
            let this->type2Ext[type] = ext;
        }
    }

    public function close() -> boolean
    {
        var type, handler ,result;
        let result = true;
        for type, handler in this->type2Handler {
            if fclose(handler) == false {
                let result = false;
                break;
            }
            unset(this->type2Handler[type]);
        }
        return result;
    }

    public function getProcessorVar(string! key) -> string
    {
        var processor;
        try {
            let processor = this->getFormatter()->getProcessor(key);
            return (string) processor;
        } catch \Exception {
        }
        return "undefined";
    }

    public function __get(string! property)
    {
        return this->getProcessorVar(property);
    }

    public function __destruct()
    {
        this->close();
    }

    public function __wakeup()
    {
        var type, ext, handler, ext2Handler = [];
        for type, ext in this->type2Ext {
            if fetch handler, ext2Handler["ext"] {
                // do nothing
            } else {
                let handler = this->open(this->_path . ext);
                let ext2Handler[ext] = handler;
            }
            let this->type2Handler[type] = handler;
        }
        let this->_fileHandler = this->type2Handler[-1];
    }
}
