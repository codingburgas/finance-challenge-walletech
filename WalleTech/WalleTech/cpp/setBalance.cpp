#include "../Include/SQL.h"
void SQLSetBalance(string username, string balance)
{
    stringstream conv; // convert the string balance to a double using sstream object
    conv << balance; // load the string into conv
    double resultConv;
    conv >> resultConv; // give resultConv the transformed value
    con->setSchema("accounts"); // set database to accounts
    pstmt = con->prepareStatement("UPDATE Accounts SET Balance = ? WHERE Username = ?");  // prepare a update set where statement 
    pstmt->setDouble(1, resultConv); // set balance to our account (using username to orientate which balance to change)
    pstmt->setString(2, username);
    pstmt->executeUpdate(); // execute the query
}