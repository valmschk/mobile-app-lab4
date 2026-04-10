#include <iostream>
#include <sqlite3.h>
#include "../includes/logic.h"

int main() {
    sqlite3* db;
    sqlite3_open("Hippodrome.db", &db);

    std::string u, p;
    std::cout << "Логин: "; std::cin >> u;
    std::cout << "Пароль: "; std::cin >> p;

    UserInfo user = loginUser(db, u, p);

    if (user.isAuthenticated) {
        int choice = 0;
        while (choice != 4) {
            std::cout << "\n1. Лучшая лошадь\n2. Расчет призов\n3. Проверить лошадь\n4. Выход\nВыбор: ";
            std::cin >> choice;
            if (choice == 1) printBestHorse(db);
            if (choice == 2) distributePrizes(db, 1, 1000.0);
            if (choice == 3) {
                int id; std::cout << "ID: "; std::cin >> id;
                std::cout << (checkHorseExists(db, id) ? "Есть" : "Нет") << std::endl;
            }
        }
    }
    sqlite3_close(db);
    return 0;
}