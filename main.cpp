#include <iostream>
#include <locale>
#include "Time.h"

int main() {
    system("chcp 65001 > nul");

    std::cout << "=== Демонстрация класса Time ===\n" << std::endl;

    // Конструктор по умолчанию
    std::cout << "--- Объект 1 (по умолчанию) ---" << std::endl;
    Time t1;
    std::cout << "Время: " << t1.getInfo() << std::endl << std::endl;

    // Сеттеры
    std::cout << "--- Изменение через сеттеры ---" << std::endl;
    t1.setHours(10);
    t1.setMinutes(30);
    t1.setSeconds(45);
    std::cout << "Время: " << t1.getInfo() << std::endl << std::endl;

    // Параметризованный конструктор
    std::cout << "--- Объект 2 (параметризованный) ---" << std::endl;
    Time t2(23, 59, 55);
    std::cout << "Время: " << t2.getInfo() << std::endl << std::endl;

    // Функция 1
    std::cout << "--- Количество секунд в объекте 2 ---" << std::endl;
    std::cout << "Всего секунд: " << t2.getTotalSeconds() << std::endl << std::endl;

    // Функция 2
    std::cout << "--- Увеличение времени объекта 2 на 5 секунд ---" << std::endl;
    t2.add5Seconds();
    std::cout << "Новое время: " << t2.getInfo() << std::endl << std::endl;

    // Копирование
    std::cout << "--- Объект 3 (копия объекта 2) ---" << std::endl;
    Time t3 = t2;
    std::cout << "Время: " << t3.getInfo() << std::endl << std::endl;

    // Проверка сеттеров
    std::cout << "--- Проверка некорректных данных ---" << std::endl;
    t1.setHours(25);
    t1.setMinutes(61);
    t1.setSeconds(-5);
    std::cout << "Время: " << t1.getInfo() << std::endl;

    std::cout << "\n=== Завершение программы ===" << std::endl;
    return 0;
}