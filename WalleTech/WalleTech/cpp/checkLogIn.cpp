#include "../Include/SQL.h"

bool SQLCheckLoginInformation(string username, string password)
{
	con->setSchema("accounts"); // switch con to accounts database
	stmt = con->createStatement(); // create a statement

	res = stmt->executeQuery("SELECT Username,Password FROM Accounts"); // get a result set in res with all usernames and passwords

	while (res->next()) // check each username and password if they match with the parameters
	{
		if (res->getString("Username") == username && res->getString("Password") == password)
			return 1; // if matches return 1 else it will return 0 after the loop
	}
	return 0;
}