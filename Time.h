#pragma once
#include <string>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();
    Time(int h, int m, int s);
    Time(const Time& other);
    ~Time();

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;

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