#include "../Include/SQL.h"

bool SQLInsertTransactionRevenues(string username, string amount, string description, string date)
{
    string monthTableName;
    try
    {
        con->setSchema("finance");
        string month = date.substr(5, 2);

        
        if (month == "01")
            monthTableName = "JanuaryRev" + username;
        else if (month == "02")
            monthTableName = "FebruaryRev" + username;
        else if (month == "03")
            monthTableName = "MarchRev" + username;
        else if (month == "04")
            monthTableName = "AprilRev" + username;
        else if (month == "05")
            monthTableName = "MayRev" + username;
        else if (month == "06")
            monthTableName = "JuneRev" + username;
        else if (month == "07")
            monthTableName = "JulyRev" + username;
        else if (month == "08")
            monthTableName = "AugustRev" + username;
        else if (month == "09")
            monthTableName = "SeptemberRev" + username;
        else if (month == "10")
            monthTableName = "OctoberRev" + username;
        else if (month == "11")
            monthTableName = "NovemberRev" + username;
        else if (month == "12")
            monthTableName = "DecemberRev" + username;

        string query = "INSERT INTO " + monthTableName + " (Amount, Date, Description) VALUES (?, ?, ?)";
        cout << endl << "Inserted rev "<< endl;

        pstmt = con->prepareStatement(query);
        pstmt->setString(1, amount);
        pstmt->setString(2, date);
        pstmt->setString(3, description);

        pstmt->executeUpdate();
        return 1; // return true if valid
    }
    catch (...)
    {
        cout << endl << "Invalid rev "<< endl;
        return 0; // return 0 if data is invalid
    }

}
// query.insert(11," March");