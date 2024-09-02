#include "MyApp.h"

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);

    try {
        // 1. Open (or create) a database
        SQLite::Database db("test.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        // 2. Create a new table
        db.exec("CREATE TABLE IF NOT EXISTS Users (user_id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, type TEXT)");

        // 3. Insert a new user
        SQLite::Statement insert(db, "INSERT INTO Users (name, type) VALUES (?, ?)");
        insert.bind(1, "John Doe");
        insert.bind(2, "client");
        insert.exec();

        std::cout << "Inserted a user into the Users table." << std::endl;

        // 4. Query the user data
        SQLite::Statement query(db, "SELECT user_id, name, type FROM Users");

        while (query.executeStep()) {
            int userId = query.getColumn(0);
            std::string name = query.getColumn(1);
            std::string type = query.getColumn(2);

            std::cout << "User ID: " << userId << ", Name: " << name << ", Type: " << type << std::endl;
        }

    }
    catch (const std::exception& e) {
        std::cerr << "SQLite exception: " << e.what() << std::endl;
    }

    return true;
}