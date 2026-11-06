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