#include "../Include/SQL.h"

void SQLCreateFinanceTables(string username)
{
		con->setSchema("finance"); // set database to finance
		stmt = con->createStatement(); // create a statement with con

		string months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" }; // month array

		for (int i = 0; i < 12; i++)
		{
			string tableName = months[i] + "Rev" + username; // formulate month parth of table name
			string query = "CREATE TABLE IF NOT EXISTS " + tableName + " (Amount DOUBLE NOT NULL, Date DATE NOT NULL, Description VARCHAR(10) NOT NULL);"; // formulate the query
			stmt->execute(query); // execute the query
		}
		for (int i = 0; i < 12; i++)
		{
			string tableName = months[i] + "Exp" + username;
			string query = "CREATE TABLE IF NOT EXISTS " + tableName + " (Amount DOUBLE NOT NULL, Date DATE NOT NULL, Description VARCHAR(10) NOT NULL);";
			stmt->execute(query);
		}

}