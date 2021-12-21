/*************************
* Донгак Ай-Бэлэк, ПИ-211 *
* ************************/
#include <iostream>
#include <iomanip>

using namespace std;

int countMonth(int startDay, int daysNumber, const char* name, int week) {
    cout << "                     " << name << endl
        << "__________________________________________________" << endl
        << "Пн\tВт\tСр\tЧт\tПт\tСб\tВс" << endl;

    for (int index = 1; index < startDay; ++index) {//Начало в нужной неделе
        cout << "\t";
    }

    for (int index = 1; index <= daysNumber; ++index) {//Заполнение календаря
        cout << index << "\t";
        if ((startDay + index) % week == 1) {
            cout << endl;
        }
    }

    cout << endl << endl;
    startDay = (startDay + daysNumber) % week;

    if (startDay == 0) {
        startDay = week;
    }
    return startDay;
}

int main() {
    setlocale(LC_ALL, "ru");
    int a, Feb;
    int week = 7, year = 1900, highYear = 366, lowYear = 365;
    cout << "Введите год: ";
    cin >> a;
    if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {//високосный год
        Feb = 29;
    }
    else {
        Feb = 28;
    }

    int leapyears, years, days, b;

    years = a - year;
    leapyears = (years - 1) / 4;

    if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {//високосный год
        days = years * highYear + leapyears;
    }
    else {
        days = years * lowYear + leapyears;
    }

    b = days % week;

    cout << endl;

    b = countMonth(b, 31, "Январь", week);
    b = countMonth(b, Feb, "Февраль", week);
    b = countMonth(b, 31, "Март", week);
    b = countMonth(b, 30, "Апрель", week);
    b = countMonth(b, 31, "Май", week);
    b = countMonth(b, 30, "Июнь", week);
    b = countMonth(b, 31, "Июль", week);
    b = countMonth(b, 31, "Август", week);
    b = countMonth(b, 30, "Сентябрь", week);
    b = countMonth(b, 31, "Октябрь", week);
    b = countMonth(b, 30, "Ноябрь", week);
    b = countMonth(b, 31, "Декабрь", week);
    system("pause");
}

