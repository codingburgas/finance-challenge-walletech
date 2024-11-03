#include "../Include/SQL.h"

string SQLGetFirstName(string username)
{
	con->setSchema("accounts"); // set database to accounts
	pstmt = con->prepareStatement("SELECT FirstName FROM Accounts WHERE Username = ?"); // get First Name with a select query by mathcing our username parameter
	pstmt->setString(1, username); // set the string in the prepared statement
	res = pstmt->executeQuery(); // execute the query

	if (res->next())
		return res->getString("FirstName");
	
		return "NULL"; //if not found return null, else it will return the name
          
}