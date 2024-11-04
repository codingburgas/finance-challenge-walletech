#include "../Include/SQL.h"

void SQLCreateAndSaveLastFourTransactions(string arr[4][3], string username)
{  
     con->setSchema("finance"); // Use the finance database

     for (int i = 0; i < 4; i++) 
     {
       pstmt = con->prepareStatement("INSERT INTO LastFourTransactions" + username + " (Amount, Date, Description) VALUES (?, ?, ?)"); // prepare the insert into statement
       pstmt->setString(1, arr[i][0]);  // set data 
       pstmt->setString(2, arr[i][1]);
       pstmt->setString(3, arr[i][2]);
       pstmt->executeUpdate(); // execute the query
     }
}
