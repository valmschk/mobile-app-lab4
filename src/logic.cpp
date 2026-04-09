#include "../includes/logic.h"
#include <iostream>

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

UserInfo loginUser(sqlite3* db, std::string user, std::string pass) {
    UserInfo info = {"", "", false};
    std::string query = "SELECT role FROM APP_USERS WHERE username = '" + user + "' AND password_hash = '" + pass + "';";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            info.username = user;
            info.role = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
            info.isAuthenticated = true;
        }
    }
    sqlite3_finalize(stmt);
    return info;
}