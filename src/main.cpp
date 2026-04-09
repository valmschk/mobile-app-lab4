#include <iostream>
#include <sqlite3.h>
#include "../includes/logic.h"

int main() {
    sqlite3* db;
    if (sqlite3_open("Hippodrome.db", &db)) {
        std::cerr << "Не удалось открыть базу данных\n";
        return 1;
    }

    std::string u, p;
    std::cout << "--- Добро пожаловать на Ипподром ---\n";
    std::cout << "Введите логин: "; std::cin >> u;
    std::cout << "Введите пароль: "; std::cin >> p;

    UserInfo user = loginUser(db, u, p);

    if (user.isAuthenticated) {
        std::cout << "Привет, " << user.username << "! Твоя роль: " << user.role << "\n";
    } else {
        std::cout << "Ошибка: неверный логин или пароль.\n";
    }

    sqlite3_close(db);
    return 0;
}