/**
 * @version 	1.0.0 26-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#include <SimpleLib/DataCollection.h>
#include <stdio.h>

#ifdef _DEBUG
	#include <iostream>
#endif

namespace SimpleLib
{
    DataCollection::DataCollection(void)
    {
        
    }

    DataCollection::~DataCollection(void)
    {
        
    }

    DataCollection::ErrorCode DataCollection::loadFromFile(const std::string& path)
    {
        DataCollection::ErrorCode errorCode = DataCollection::None;
        
        if (path.empty())
        {
            errorCode = InvalidParameter;
            
#ifdef _DEBUG
			std::cout << "[DEBUG] DataCollection::loadFromFile: path empty!" << std::endl;
#endif
        }
        else
        {
            FILE* fileHnd = fopen(path.c_str(), "r");
            
            if (fileHnd == NULL)
            {
                errorCode = FileIsNotReadable;
                
#ifdef _DEBUG
                std::cout << "[DEBUG] DataCollection::loadFromFile: file couldn't be opened!" << std::endl;
#endif
            }
            else
            {
            	std::map<std::string, int> currGroupItems;
            	char currLine[256] 		= "";
                std::string currGroup 	= "";
                
            	while (!feof(fileHnd))
                {
                    if (fgets(currLine, 256, fileHnd) == NULL)
                    {
                    	errorCode = ReadFailure;
#ifdef _DEBUG
                        std::cout << "[DEBUG] DataCollection::loadFromFile: error while reading the data from file!" << std::endl;
#endif
                        break;
                    }
                    else
                    {
                    	// ignore empty lines and comments
                        if ((unsigned int)strlen(currLine) > 0 && currLine[0] != '#')
                        {
                        	// is is a group
                            if (currLine[0] == '[')
                            {
                            	// in case there were already some group items loaded
                                // add them to the final data list
                                if (!currGroupItems.empty())
                                {
                                    this->_data[currGroup] = currGroupItems;
                                    
                                    currGroupItems.clear();
                                }
                                
                                currGroup.clear();
                                currGroup.assign(currLine);
                                
                                int position = currGroup.find(']');
                                
                                currGroup = currGroup.substr(1, position - 1);
                            }
                            else
                            {
                            	std::string currItem(currLine);
                            	unsigned int position = currItem.find('=');
                                
                                // items without an assignment operator will be ignored
                                if (position != std::string::npos)
                                {
                                	std::string key(this->_trimValue(currItem.substr(0, position)));
                                    std::string value(this->_trimValue(currItem.substr(position + 1)));
                                    
                                    currGroupItems[key] = atoi(value.c_str());
                                }
                            }
                        }
                    }
                    
                }
            
                fclose(fileHnd);
            }
        }
        
        return errorCode;
    }

	/**
     * Returns value of particular group and its key identifier.
     *
     * This method returns 0 in case of no item was found and also if an item was found
     * and its value is 0. So you cannot use this method to figure out if an option was 
     * defined!
     *
     * @param group string 	- group the value belongs to
     * @param key string 	- key identifier to select a particular value
     * @return integer 		- returns 0 in case of no item was found otherwise its value
     */
    int DataCollection::getValue(const std::string& group, const std::string& key)
    {
        return (this->_data.find(group) != this->_data.end() && this->_data[group].find(key) != this->_data[group].end()) ? this->_data[group].find(key)->second : 0;
    }
    
    std::string DataCollection::_trimValue(const std::string value)
    {
        std::string result(value);
    	bool isReady = false;
        
        if (result[result.length() - 1] == '\n') {
            result = result.substr(0, result.length() - 1);
        }
        
        while (result.length() > 0 && !isReady)
        {
            isReady = true;
            
            if (result[0] == ' ')
            {
                result = result.substr(1);
                
                isReady = false;
            }
            
            if (result[result.length() - 1] == ' ')
            {
                result = result.substr(0, result.length() - 1);
                
                isReady = false;
            }
        }
        
        return result;
	}
}