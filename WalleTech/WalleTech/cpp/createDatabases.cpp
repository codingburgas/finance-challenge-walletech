#include "../Include/SQL.h"

void SQLCreateDBs()
{
	stmt = con->createStatement(); // create a statement with con

	stmt->execute("CREATE DATABASE IF NOT EXISTS accounts"); // create accounts and finance databases
	stmt->execute("CREATE DATABASE IF NOT EXISTS finance");

	cout << "-------------------------" << endl;
	cout << "DBs created successfully!" << endl;
	cout << "-------------------------" << endl;
}