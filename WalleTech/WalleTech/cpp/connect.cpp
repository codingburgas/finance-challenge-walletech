#include "../Include/SQL.h"

void SQLConnect()
{
	driver = sql::mysql::get_mysql_driver_instance(); // get MySQL driver instance

	string credentials[3];

	ifstream inputHandle("./credentials.txt"); // initializing a handle to the credentials .txt file
	string tempLine;

	int countLines = 0;
	while (countLines < 3 && getline(inputHandle, tempLine)) // get credentials in the array of strings
	{
		credentials[countLines++] = tempLine;
	}

	con = driver->connect(credentials[0], credentials[1], credentials[2]); // get a connection to the sql server

	cout << "-----------------------" << endl;
	cout << "Connected successfully!" << endl;
	cout << "-----------------------" << endl;
}