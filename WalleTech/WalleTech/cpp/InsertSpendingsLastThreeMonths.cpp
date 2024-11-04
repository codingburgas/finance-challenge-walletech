#include "../Include/SQL.h"

void SQLInsertSpendingsLastThreeMonths(string username, string subquestion1, string subquestion2, string subquestion3)
{
    con->setSchema("finance");
    pstmt = con->prepareStatement("INSERT INTO SpendingsLastThreeMonths(Username,FirstM,SecondM,ThirdM) VALUES (?,?,?,?)"); // prepare the insert into statement

    string subQ1Answer, subQ2Answer, subQ3Answer;
    if (subquestion1 == "2-1-1") // find an appropriate value for each answer that will be inserted into the table
    {
        subQ1Answer = "5K>";
    }
    else if (subquestion1 == "2-1-2")
    {
        subQ1Answer = "10K>";
    }
    else if (subquestion1 == "2-1-3")
    {
        subQ1Answer = "50K>";
    }

    if (subquestion2 == "2-2-1")
    {
        subQ2Answer = "5K>";
    }
    else if (subquestion2 == "2-2-2")
    {
        subQ2Answer = "10K>";
    }
    else if (subquestion2 == "2-2-3")
    {
        subQ2Answer = "50K>";
    }

    if (subquestion3 == "2-3-1")
    {
        subQ3Answer = "5K>";
    }
    else if (subquestion3 == "2-3-2")
    {
        subQ3Answer = "10K>";
    }
    else if (subquestion3 == "2-3-3")
    {
        subQ3Answer = "50K>";
    }
    // SpendigsLastThreeMonths

    pstmt->setString(1, username); // set each value for the prepared query above
    pstmt->setString(2, subQ1Answer);
    pstmt->setString(3, subQ2Answer);
    pstmt->setString(4, subQ3Answer);
    pstmt->executeUpdate(); // execute the query (update for the table)
}
/*

                subQ1 = "2-1-1"; 
           
                subQ1 = "2-1-2";          
           
                subQ1 = "2-1-3";
           

                subQ2 = "2-2-1";
           
                subQ2 = "2-2-2";
           
                subQ2 = "2-2-3";
           

                subQ3 = "2-3-1";
           
                subQ3 = "2-3-2";
           
                subQ3 = "2-3-3";
            


*/