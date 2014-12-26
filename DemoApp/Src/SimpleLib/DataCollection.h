/**
 * @version 	1.1.0 26-Dec-14
 * @copyright	Copyright (c) 2014 by Andy Liebke. All rights reserved. (http://andysmiles4games.com)
 */
#ifndef __SIMPLE_LIB_DATA_COLLECTION_H__
#define __SIMPLE_LIB_DATA_COLLECTION_H__

#include <string>
#include <map>

namespace SimpleLib
{
	class DataCollection
    {
    	public:
        	DataCollection(void);
        	virtual ~DataCollection(void);
     
        public:
        	enum ErrorCode
            {
                None = 0,
                Failure = 1,
                FileIsNotReadable = 2,
                InvalidParameter = 3,
                ReadFailure = 4
            };
        
        	DataCollection::ErrorCode loadFromFile(const std::string& path);
        	int getValue(const std::string& group, const std::string& key);
        
        private:
        	std::string _trimValue(const std::string value);
        
        private:
        	typedef std::map<std::string, int> DataMapItem;
        	typedef std::map<std::string, DataMapItem> DataMap;
        
        	DataMap _data;
    };
}

#endif