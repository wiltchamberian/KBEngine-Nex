
#include "db_interface_mongodb.h"
#include "db_transaction.h"
#include "db_exception.h"
#include "db_interface/db_interface.h"
#include "helper/debug_helper.h"
#include "common/timestamp.h"

namespace KBEngine { 
namespace mongodb {
 


//-------------------------------------------------------------------------------------
DBTransaction::DBTransaction(DBInterface* pdbi, bool autostart):
	pdbi_(pdbi),
	committed_(false),
	autostart_(autostart)
{
	if(autostart)
		start();
}

//-------------------------------------------------------------------------------------
DBTransaction::~DBTransaction()
{
	if(autostart_)
		end();
}

//-------------------------------------------------------------------------------------
void DBTransaction::start()
{
	
}

//-------------------------------------------------------------------------------------
void DBTransaction::end()
{
	
}

//-------------------------------------------------------------------------------------
bool DBTransaction::shouldRetry() const
{
	return false;
}

//-------------------------------------------------------------------------------------
void DBTransaction::commit()
{
	KBE_ASSERT(!committed_);

}

}
}
