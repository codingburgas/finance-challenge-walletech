#include "../Include/SQL.h"

int SQLGetAverageSpendingsLastThreeMonths(string username)
{
	con->setSchema("finance"); // set database to finance
	pstmt = con->prepareStatement("SELECT FirstM,SecondM,ThirdM FROM SpendingsLastThreeMonths WHERE Username = ?"); // prepaer a select statement to get income values for alst three months
	pstmt->setString(1, username); // set username in the query
	res = pstmt->executeQuery(); // get a result set
	string first, second, third;
	if (res->next()) // if there's such a username
	{
		first = res->getString("FirstM"); // get firstM, secondM, ThirdM values in three string
		second = res->getString("SecondM");
		third = res->getString("ThirdM");
	}

	int firstI, secondI, thirdI;

	if (first == "5K>")
		firstI = 5;
	else if (first == "10K>")
		firstI = 10;
	else
		firstI = 50;

	if (second == "5K>")
		secondI = 5;
	else if (second == "10K>")
		secondI = 10;
	else
		secondI = 50;

	if (third == "5K>")
		thirdI = 5;
	else if (third == "10K>")
		thirdI = 10;
	else
		thirdI = 50;
	return (firstI + secondI + thirdI) / 3;

}