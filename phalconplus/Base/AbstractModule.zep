//<?php
namespace PhalconPlus\Base;
// implement \Phalcon\Mvc\ModuleDefinitionInterface

abstract class AbstractModule 
{
    // <\Phalcon\DI>
    protected di = null;

    // <\PhalconPlus\Base\ModuleDef>
    protected def = null;

    public function __construct(<\Phalcon\DI> di, <\PhalconPlus\Base\ModuleDef> def = null)
    {
        let this->di = di;
        let this->def = def; // Module should have it's definition.
    }

    public function getDef() -> <\PhalconPlus\Base\ModuleDef>
    {
        return this->def;
    }

    public function getDi() -> <\Phalcon\Di>
    {
        return this->di;
    }

    public function isPrimary()
    {
        return this->def->getIsPrimary() == true; // Report is primary or not
    }

    public function getBootstrap()
    {
        return this->def->getBootstrap();
    }

    abstract public function registerAutoloaders();
    abstract public function registerServices();
}
