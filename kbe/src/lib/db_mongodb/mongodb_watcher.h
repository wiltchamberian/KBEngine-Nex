// Copyright 2008-2018 Yolo Technologies, Inc. All Rights Reserved. https://www.comblockengine.com

#ifndef KBE_MONGODB_WATCHER_H
#define KBE_MONGODB_WATCHER_H

#include "db_interface_mongodb.h"

namespace KBEngine{ 

class MongodbWatcher
{
public:
	static void querystatistics(const char* strCommand, uint32 size);
	static void initializeWatcher();
};

}
#endif // KBE_MONGODB_WATCHER_H
