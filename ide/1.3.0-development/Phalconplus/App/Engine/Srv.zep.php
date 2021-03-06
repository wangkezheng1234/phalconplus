<?php

namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Rpc\Server\SimpleServer;
use PhalconPlus\Rpc\Yar as YarServerPlus;
use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Http\ResponseInterface as HttpResponse;
use Yar_Server;

class Srv extends Injectable implements \PhalconPlus\App\Engine\AppEngine
{

    protected $appModule = null;


    protected $handler = null;


    /**
     * @param \PhalconPlus\App\Module\AbstractModule $appModule
     * @param BaseApplication $handler
     */
    public function __construct(\PhalconPlus\App\Module\AbstractModule $appModule, BaseApplication $handler = null)
    {
    }

    /**
     * @return HttpResponse
     */
    public function exec(): HttpResponse
    {
    }

    /**
     * @param object $handler
     * @return AppEngine
     */
    public function setHandler($handler): AppEngine
    {
    }

    /**
     * @return object
     */
    public function handler()
    {
    }

    /**
     * @return object
     */
    public function getHandler()
    {
    }

}
