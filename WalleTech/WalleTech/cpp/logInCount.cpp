#include "../Include/SQL.h"

int SQLIncreaseAndReturnLogInCount(string username) 
{
	con->setSchema("accounts"); // set database to accounts
	pstmt = con->prepareStatement("SELECT LogInCount FROM Accounts WHERE Username = ?"); // prepare a select statement
	pstmt->setString(1, username); // set username value
	res = pstmt->executeQuery(); // get result set

	int logInCount = 0;
	if (res->next())  // if there's a login count assign it, else it will stay 0
	{
		logInCount = res->getInt("LogInCount");
	}
	
	pstmt = con->prepareStatement("UPDATE Accounts SET LogInCount = ? WHERE Username = ?"); // prepare statement for update the login count 
	pstmt->setInt(1, logInCount + 1); // set new login count
	pstmt->setString(2, username); //  set username
	pstmt->executeUpdate(); // execute the query

	return logInCount + 1; // return new login count
}