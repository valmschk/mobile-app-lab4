#include "../includes/logic.h"
#include <iostream>

void printBestHorse(sqlite3* db) {
    const char* sql = "SELECT h.name, COUNT(r.id) as wins FROM HORSES h "
                      "JOIN RACES r ON h.id = r.horse_id "
                      "WHERE r.finish_position = 1 GROUP BY h.id "
                      "ORDER BY wins DESC LIMIT 1;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            std::cout << "Лучшая лошадь: " << sqlite3_column_text(stmt, 0) 
                      << " (Побед: " << sqlite3_column_int(stmt, 1) << ")" << std::endl;
        } else {
            std::cout << "Данных о победителях пока нет." << std::endl;
        }
    }
    sqlite3_finalize(stmt);
}

void distributePrizes(sqlite3* db, int raceId, double totalFund) {
    double p1 = totalFund * 0.5; // 50%
    double p2 = totalFund * 0.3; // 30%
    double p3 = totalFund * 0.2; // 20%
    
    std::cout << "Распределение для забега #" << raceId << ":\n"
              << "1 место: " << p1 << "\n2 место: " << p2 << "\n3 место: " << p3 << std::endl;
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