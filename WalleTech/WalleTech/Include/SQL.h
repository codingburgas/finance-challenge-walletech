#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/exception.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include "pch.h"
 // libraries to connect and send queries to our mysql server from cpp
extern sql::mysql::MySQL_Driver* driver; // used to get a driver instance to our mysql server
extern sql::Connection* con; // used to prepare and create statements and set database
extern sql::Statement* stmt; // used to execure queries
extern sql::ResultSet* res; // used to get result sets from select queries
extern sql::PreparedStatement* pstmt; // used to execute queries with prepared statements and following values if needed

void SQLConnect();// connect to the server
void SQLCreateDBs(); // create the databases we need
void SQLCreateTables(); // create neededed tables in the databases

bool SQLCheckLoginInformation(string username,string password); // check log in credentials

void SQLDelete(); // delete all pointers associated with sql connector

bool SQLCreateAccount(string username, string password, string firstName, string lastName); // insert a new account data

void SQLSetBalance(string username,string balance); // set balance of our account (question 2 of the questionaire)

int SQLIncreaseAndReturnLogInCount(string username); // increase and return how many times we have logged in our accounts

void SQLInsertIncomeLastThreeMonths(string username, string subquestion1, string subquestion2, string subquestion3); // insert our income for last three months (question 3 of the questionaire)

void SQLInsertSpendingsLastThreeMonths(string username, string subquestion1, string subquestion2, string subquestion3); // insert our spendings for last three months (question 4 of the questionaire)

string SQLGetBalance(string username); // get the balance of our account

string SQLGetFirstName(string username); // get the first name of our account

string SQLGetLastName(string username); // get the last name of our account

bool SQLInsertTransactionRevenues(string username, string amount, string description, string date); // insert a revenue query with a positive balance effect

void SQLCreateFinanceTables(string username); // create tables in finance database

void SQLUpdateBalanceAfterRevenue(string username, string date, string amount); // increase and update our balance after a revenue after a query

bool SQLInsertTransactionExpenses(string username, string amount, string description, string date); // insert a expense query with a negative balance effect

void SQLUpdateBalanceAfterExpense(string username, string date, string amount); // decrease and update balance after a expense query

void SQLCreateAndSaveLastFourTransactions(string arr[4][3],string username); //insert our last four transactions' data

void SQLGetLastFourTransactions(string arr[4][3], string username); //  create a table in finance to hold our last 4 transactions if it hasn't been created already and give values to the lastFourTransactions array 

int SQLGetAverageIncomeLastThreeMonths(string username); // get avg value for question 3 of our questionaire

int SQLGetAverageSpendingsLastThreeMonths(string username); // get average value for question 4 of our questionaire

