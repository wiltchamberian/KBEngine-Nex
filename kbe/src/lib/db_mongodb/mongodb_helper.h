// Copyright 2008-2018 Yolo Technologies, Inc. All Rights Reserved. https://www.comblockengine.com

#ifndef KBE_MONGODB_HELPER_H
#define KBE_MONGODB_HELPER_H

#include "common.h"
#include "common/common.h"
#include "common/stringconv.h"
#include "common/memorystream.h"
#include "helper/debug_helper.h"
#include "db_interface_mongodb.h"

namespace KBEngine{ 

class MongodbHelper
{
public:
	MongodbHelper()
	{
	}

	virtual ~MongodbHelper()
	{
	}

	static bool expireKey(DBInterfaceMongodb* pdbi, const std::string& key, int secs, bool printlog = true)
	{
		return false;
	}
	
	static bool check_array_results()
	{
	
		return true;
	}
	
	static bool hasTable(DBInterfaceMongodb* pdbi, const std::string& name, bool printlog = true)
	{
		
		
		return true;
	}
	
	static bool dropTable(DBInterfaceMongodb* pdbi, const std::string& tableName, bool printlog = true)
	{
		uint64 index = 0;
		
		return true;
	}
	
	static bool dropTableItem(DBInterfaceMongodb* pdbi, const std::string& tableName, 
		const std::string& itemName, bool printlog = true)
	{
		
		
		return true;
	}
};

}
#endif // KBE_MONGODB_HELPER_H
