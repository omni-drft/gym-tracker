#include "MyApp.h"

bool MyApp::OnInit()
{
    // Create main frame and show it
    MyFrame* frame = new MyFrame();
    frame->Show(true);

    try 
    {
        // Open (or create) a database
        SQLite::Database db("Users.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        // Create a new table
        db.exec("CREATE TABLE IF NOT EXISTS Users (user_id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)");

        // Check if the table is empty
        SQLite::Statement query(db, "SELECT COUNT(*) FROM Users");
        query.executeStep();

        // If the table is empty, insert the initial record
        if (query.getColumn(0).getInt() == 0)
            db.exec("INSERT INTO Users (name) VALUES ('Default')");
    }
    catch (const std::exception& e) 
    {
        std::cerr << "SQLite exception: " << e.what() << std::endl;
    }

    return true;
}