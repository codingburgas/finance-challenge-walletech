#include "../Include/SQL.h"

void SQLGetLastFourTransactions(string arr[4][3],string username) 
{
   
        con->setSchema("finance"); // Use the finance database
        stmt = con->createStatement();

        string tableName = "LastFourTransactions" + username;
        string query = "CREATE TABLE IF NOT EXISTS " + tableName + " (ID INT PRIMARY KEY AUTO_INCREMENT, Amount TEXT, Date TEXT, Description TEXT)";
        stmt->execute(query); // Execute the query

         query = "SELECT * FROM " + tableName + " ORDER BY ID DESC LIMIT 4";
        res = stmt->executeQuery(query); // Execute the query

        int i = 0;
        while (res->next() && i < 4)
        {
            arr[i][0] = res->getString("Amount"); // Assign amount of each row
            arr[i][1] = res->getString("Date");   // Assign date of each row
            arr[i][2] = res->getString("Description"); // Assign description of each row
            i++;
        }
  
}
//  LastFourTransactions (Amount TEXT NOT NULL, Date TEXT NOT NULL, Description TEXT NOT NULL)");