#include "../Include/SQL.h"

bool SQLInsertTransactionExpenses(string username, string amount, string description, string date)
{

    string monthTableName;
    try
    {
        con->setSchema("finance"); // set db to finance
        string month = date.substr(5, 2); // get month part from date

        // formulate appropriate table name 
        if (month == "01")
            monthTableName = "JanuaryExp" + username;
        else if (month == "02")
            monthTableName = "FebruaryExp" + username;
        else if (month == "03")
            monthTableName = "MarchExp" + username;
        else if (month == "04")
            monthTableName = "AprilExp" + username;
        else if (month == "05")
            monthTableName = "MayExp" + username;
        else if (month == "06")
            monthTableName = "JuneExp" + username;
        else if (month == "07")
            monthTableName = "JulyExp" + username;
        else if (month == "08")
            monthTableName = "AugustExp" + username;
        else if (month == "09")
            monthTableName = "SeptemberExp" + username;
        else if (month == "10")
            monthTableName = "OctoberExp" + username;
        else if (month == "11")
            monthTableName = "NovemberExp" + username;
        else if (month == "12")
            monthTableName = "DecemberExp" + username;

        string query = "INSERT INTO " + monthTableName + " (Amount, Date, Description) VALUES (?, ?, ?)";
        cout << endl << "Inserted exp " << endl;

        pstmt = con->prepareStatement(query); // preprare query with the formulated string
        pstmt->setString(1, amount); // set values
        pstmt->setString(2, date);
        pstmt->setString(3, description);

        pstmt->executeUpdate(); // execute
        return 1; // return true if valid
    }
    catch (...)
    {
        cout << endl << "Invalid exp " << endl;
        return 0; // return 0 if data is invalid
    }
}