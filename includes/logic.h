#ifndef LOGIC_H
#define LOGIC_H

#include <string>
#include <sqlite3.h>

int add(int a, int b);
int multiply(int a, int b);

struct UserInfo {
    std::string username;
    std::string role;
    bool isAuthenticated;
};

UserInfo loginUser(sqlite3* db, std::string user, std::string pass);

#endif