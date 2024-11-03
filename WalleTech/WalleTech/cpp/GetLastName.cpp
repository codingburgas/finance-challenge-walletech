#include "../Include/SQL.h"

string SQLGetLastName(string username)
{
	con->setSchema("accounts"); // set database to accounts
	pstmt = con->prepareStatement("SELECT LastName FROM Accounts WHERE Username = ?"); // get Last Name with a select query by mathcing our username parameter
	pstmt->setString(1, username); // set the string in the prepared statement
	res = pstmt->executeQuery(); // execute the query

	if (res->next())
		return res->getString("LastName");

	return "NULL"; // if not found return null, else it will return the name

}