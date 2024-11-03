#include "../Include/SQL.h"

void SQLDelete()
{
	delete stmt;
	delete res;
	delete con;
	delete pstmt;
}