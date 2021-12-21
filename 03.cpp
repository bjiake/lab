/*************************
* Донгак Ай-Бэлэк, ПИ-211 *
* ************************/
#include <iostream>
#include <iomanip>

using namespace std;

int countMonth(int startDay, int daysNumber, const char* name) {
    int week = 7;

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
    int numberDay, February;
    int week = 7, year = 1900, highYear = 366, lowYear = 365;
    cout << "Введите год: ";
    cin >> numberDay;
    if ((numberDay % 4 == 0 && numberDay % 100 != 0) || numberDay % 400 == 0) {//високосный год
        February = 29;
    } else {
        February = 28;
    }

    int leapYears, years, days, b;

    years = a - year;
    leapYears = (years - 1) / 4;

    if ((numberDay % 4 == 0 && numberDay % 100 != 0) || numberDay % 400 == 0) {//високосный год
        days = years * highYear + leapYears;
    }
    else {
        days = years * lowYear + leapYears;
    }

    b = days % week;
    cout << endl;

    b = countMonth(b, 31, "Январь");
    b = countMonth(b, Feb, "Февраль");
    b = countMonth(b, 31, "Март");
    b = countMonth(b, 30, "Апрель");
    b = countMonth(b, 31, "Май");
    b = countMonth(b, 30, "Июнь");
    b = countMonth(b, 31, "Июль");
    b = countMonth(b, 31, "Август");
    b = countMonth(b, 30, "Сентябрь");
    b = countMonth(b, 31, "Октябрь");
    b = countMonth(b, 30, "Ноябрь");
    b = countMonth(b, 31, "Декабрь");
    system("pause");
}

