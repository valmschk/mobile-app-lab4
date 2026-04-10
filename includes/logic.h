#ifndef LOGIC_H
#define LOGIC_H

#include <string>
#include <sqlite3.h>
#include <vector>

int add(int a, int b);
int multiply(int a, int b);

struct UserInfo {
    std::string username;
    std::string role;
    bool isAuthenticated;
};

UserInfo loginUser(sqlite3* db, std::string user, std::string pass);
void printBestHorse(sqlite3* db);
void distributePrizes(sqlite3* db, int raceId, double totalFund);
bool checkHorseExists(sqlite3* db, int horseId);

#endif