
#include "db_exception.h"
#include "db_interface_mongodb.h"
#include "db_interface/db_interface.h"

namespace KBEngine { 

//-------------------------------------------------------------------------------------
DBException::DBException(DBInterface* pdbi) :
	errStr_(static_cast<DBInterfaceMongodb*>(pdbi)->getstrerror()),
	errNum_(static_cast<DBInterfaceMongodb*>(pdbi)->getlasterror())
{
}

//-------------------------------------------------------------------------------------
DBException::~DBException() throw()
{
}

//-------------------------------------------------------------------------------------
bool DBException::shouldRetry() const
{
	return false;
}

//-------------------------------------------------------------------------------------
bool DBException::isLostConnection() const
{
	return false;
}

//-------------------------------------------------------------------------------------
}

// db_exception.cpp
