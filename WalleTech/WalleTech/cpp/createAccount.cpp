#include "../Include/SQL.h"

bool SQLCreateAccount(string username, string password, string firstName, string lastName)
{
	try
	{
		con->setSchema("accounts"); // set database to accounts
		pstmt = con->prepareStatement("INSERT INTO Accounts (FirstName, LastName, Username, Password) VALUES(?,?,?,?)"); // prepare a insert into query with a columns list
		pstmt->setString(1, firstName); // set each value in the prepared statement above, with 1 indexing
		pstmt->setString(2, lastName);
		pstmt->setString(3, username);
		pstmt->setString(4, password);
		pstmt->executeUpdate(); // execute the query
	}
	catch (...)
	{
		return 0; // catch an sql exception if you enter a non-unique username and return 0 (invalid)
	}
	return 1; // return 1 if the query is executed successfully
}