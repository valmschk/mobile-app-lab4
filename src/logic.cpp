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

void printBestHorse(sqlite3* db) {
    const char* sql = "SELECT h.name, COUNT(r.id) as wins FROM HORSES h "
                      "JOIN RACES r ON h.id = r.HORSES_id "
                      "WHERE r.finish_position = 1 GROUP BY h.id "
                      "ORDER BY wins DESC LIMIT 1;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            std::cout << "\n>>> Лучшая лошадь: " << sqlite3_column_text(stmt, 0) 
                      << " (Побед: " << sqlite3_column_int(stmt, 1) << ")" << std::endl;
        } else {
            std::cout << "\nДанных о победителях пока нет." << std::endl;
        }
    }
    sqlite3_finalize(stmt);
}

void distributePrizes(sqlite3* db, int raceId, double totalFund) {
    double p1 = totalFund * 0.5;
    double p2 = totalFund * 0.3;
    double p3 = totalFund * 0.2;
    
    std::cout << "\nРаспределение фонда для забега #" << raceId << ":\n"
              << "1 место: " << p1 << " руб.\n"
              << "2 место: " << p2 << " руб.\n"
              << "3 место: " << p3 << " руб." << std::endl;
}

bool checkHorseExists(sqlite3* db, int horseId) {
    std::string query = "SELECT id FROM HORSES WHERE id = " + std::to_string(horseId) + ";";
    sqlite3_stmt* stmt;
    bool exists = false;
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) exists = true;
    }
    sqlite3_finalize(stmt);
    return exists;
}