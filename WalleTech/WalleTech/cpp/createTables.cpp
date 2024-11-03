#include "../Include/SQL.h"

void SQLCreateTables()
{	
		con->setSchema("accounts"); // set database to accounts
		stmt = con->createStatement(); // create a statement

		stmt->execute("CREATE TABLE IF NOT EXISTS Accounts (ID INT PRIMARY KEY AUTO_INCREMENT, FirstName VARCHAR(10) NOT NULL,LastName VARCHAR(10) NOT NULL, Username VARCHAR(15) UNIQUE NOT NULL, Password VARCHAR(10) NOT NULL, Balance DOUBLE DEFAULT 0.00, LogInCount INT DEFAULT 0 );"); // create Accounts table		

		con->setSchema("finance");

		stmt->execute("CREATE TABLE IF NOT EXISTS IncomeLastThreeMonths(Username VARCHAR(15) PRIMARY KEY NOT NULL, FirstM VARCHAR(5) NOT NULL, SecondM VARCHAR(5) NOT NULL, ThirdM VARCHAR(5) NOT NULL)");
		stmt->execute("CREATE TABLE IF NOT EXISTS SpendingsLastThreeMonths(Username VARCHAR(15) PRIMARY KEY NOT NULL, FirstM VARCHAR(5) NOT NULL, SecondM VARCHAR(5) NOT NULL, ThirdM VARCHAR(5) NOT NULL)");	

		cout << "----------------------------" << endl;
		cout << "Tables created successfully!" << endl;
		cout << "----------------------------" << endl;
	
}

// DBs: accounts, finance
// Tables in finance: monthExpenses x 12, monthRevenues x 12, IncomeLastThreeMonths, SpendingsLastThreeMonths
// Tables in accounts: Accounts