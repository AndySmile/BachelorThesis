/**
 * @version     1.0.0 04-Jan-15
 * @copyright   Copyright (c) 2014-2015 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */

void EntityAbstract::setPosition(const glm::vec3& position)
{
    this->_position = position;
}

glm::vec3 EntityAbstract::getPosition(void) const
{
    return this->_position;
}