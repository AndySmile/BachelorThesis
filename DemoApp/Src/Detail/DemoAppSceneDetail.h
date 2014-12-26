/**
 * @version 	1.2.0 26-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

void DemoAppScene::setImagePath(const std::string path)
{
    this->_imagePath = path;
}

void DemoAppScene::setConfigFilePath(const std::string path)
{
    this->_configFilePath = path;
}

void DemoAppScene::enableLight(const bool isEnabled)
{
    this->_isLightEnabled = isEnabled;
}

void DemoAppScene::setAppConfig(AppConfig* config)
{
    this->_config = config;
}