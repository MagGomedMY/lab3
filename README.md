# Лабораторная работа №3: Классы и объекты в C++

**Студент:** Арчаков Магомед Адамович  
**Группа:** ПИЖ-б-о-25-2  
**Вариант:** 4  
**Задание:** 2 (Средний уровень)  
**Технология:** C++17

---

## Цель работы

Научиться создавать классы, определять поля и методы, реализовывать конструкторы (по умолчанию, параметризованный, копирования) и деструктор. Освоить спецификаторы доступа `private` и `public` для инкапсуляции данных, а также создавать геттеры и сеттеры для работы с закрытыми полями.

---

## Постановка задачи (Вариант 4)

Создать класс `Time` со следующими полями:
- `часы` (int)
- `минуты` (int)
- `секунды` (int)

Реализовать в классе:
1. Конструктор по умолчанию.
2. Параметризованный конструктор.
3. Конструктор копирования.
4. Деструктор (с сообщением об уничтожении объекта).
5. Геттеры и сеттеры для всех полей (с проверкой корректности).
6. Функцию-метод 1: вычислить количество секунд.
7. Функцию-метод 2: увеличить время на 5 секунд.
8. Функцию формирования строки информации об объекте.

Создать проект для демонстрации работы: сформировать объекты с константными значениями и с введёнными с клавиатуры значениями. Выводить результаты на экран.

---

## Листинг программы

### Файл `Time.h`

```cpp
#pragma once
#include <string>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструкторы
    Time();
    Time(int h, int m, int s);
    Time(const Time& other);
    
    // Деструктор
    ~Time();

    // Геттеры
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

    // Сеттеры с проверкой
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);

    // Функция 1: вычислить количество секунд
    int getTotalSeconds() const;

    // Функция 2: увеличить время на 5 секунд
    void add5Seconds();

    // Формирование строки информации
    std::string getInfo() const;
};
```

### Файл `Time.cpp`

```cpp
#include "Time.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Time::Time() : hours(0), minutes(0), seconds(0) {
    std::cout << "Вызван конструктор по умолчанию для Time" << std::endl;
}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    std::cout << "Вызван параметризованный конструктор для Time" << std::endl;
}

Time::Time(const Time& other) : hours(other.hours), minutes(other.minutes), seconds(other.seconds) {
    std::cout << "Вызван конструктор копирования для Time" << std::endl;
}

Time::~Time() {
    std::cout << "Вызван деструктор для Time" << std::endl;
}

int Time::getHours() const { return hours; }
int Time::getMinutes() const { return minutes; }
int Time::getSeconds() const { return seconds; }

void Time::setHours(int h) {
    if (h >= 0 && h < 24) hours = h;
    else std::cout << "Ошибка: часы должны быть от 0 до 23!" << std::endl;
}

void Time::setMinutes(int m) {
    if (m >= 0 && m < 60) minutes = m;
    else std::cout << "Ошибка: минуты должны быть от 0 до 59!" << std::endl;
}

void Time::setSeconds(int s) {
    if (s >= 0 && s < 60) seconds = s;
    else std::cout << "Ошибка: секунды должны быть от 0 до 59!" << std::endl;
}

int Time::getTotalSeconds() const {
    return hours * 3600 + minutes * 60 + seconds;
}

void Time::add5Seconds() {
    int total = getTotalSeconds() + 5;
    total %= 24 * 3600; // если перешли через полночь
    hours = total / 3600;
    total %= 3600;
    minutes = total / 60;
    seconds = total % 60;
}

std::string Time::getInfo() const {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds;
    return oss.str();
}
```

### Файл `main.cpp`

```cpp
#include <iostream>
#include <locale>
#include "Time.h"

int main() {
    setlocale(LC_ALL, "Russian");

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
```

---

## Результаты работы программы

**Пример вывода в консоль:**

```text
=== Демонстрация класса Time ===

--- Объект 1 (по умолчанию) ---
Вызван конструктор по умолчанию для Time
Время: 00:00:00

--- Изменение через сеттеры ---
Время: 10:30:45

--- Объект 2 (параметризованный) ---
Вызван параметризованный конструктор для Time
Время: 23:59:55

--- Количество секунд в объекте 2 ---
Всего секунд: 86395

--- Увеличение времени объекта 2 на 5 секунд ---
Новое время: 00:00:00

--- Объект 3 (копия объекта 2) ---
Вызван конструктор копирования для Time
Время: 00:00:00

--- Проверка некорректных данных ---
Ошибка: часы должны быть от 0 до 23!
Ошибка: минуты должны быть от 0 до 59!
Ошибка: секунды должны быть от 0 до 59!
Время: 10:30:45

=== Завершение программы ===
Вызван деструктор для Time
Вызван деструктор для Time
Вызван деструктор для Time
```

---

## Выводы

В ходе лабораторной работы были изучены принципы объектно-ориентированного программирования в C++. Освоено создание классов с закрытыми полями (`private`) и открытыми методами (`public`), реализация конструкторов (по умолчанию, параметризованного и копирования) и деструктора. На практике применена инкапсуляция: доступ к полям осуществляется только через геттеры и сеттеры с проверкой корректности вводимых данных. Также реализованы методы обработки данных (перевод времени в секунды и прибавление 5 секунд с корректным переходом через полночь).