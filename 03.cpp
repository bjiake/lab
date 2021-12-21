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

    int numberDay, february;
    int week = 7, year = 1900, highYear = 366, lowYear = 365;
    cout << "Введите год: ";
    cin >> numberDay;
    if ((numberDay % 4 == 0 && numberDay % 100 != 0) || numberDay % 400 == 0) {//високосный год
        february = 29;
    } else {
        february = 28;
    }

    int leapYears, years, days, startDay;

    years = numberDay - year;
    leapYears = (years - 1) / 4;

    if ((numberDay % 4 == 0 && numberDay % 100 != 0) || numberDay % 400 == 0) {//високосный год
        days = years * highYear + leapYears;
    }
    else {
        days = years * lowYear + leapYears;
    }

    startDay = days % week;
    cout << endl;

    startDay = countMonth(startDayb, 31, "Январь");
    startDay = countMonth(startDay, february, "Февраль");
    startDay = countMonth(startDay, 31, "Март");
    startDay = countMonth(startDay, 30, "Апрель");
    startDay = countMonth(startDay, 31, "Май");
    startDay = countMonth(startDay, 30, "Июнь");
    startDay = countMonth(startDay, 31, "Июль");
    startDay = countMonth(startDay, 31, "Август");
    startDay = countMonth(startDay, 30, "Сентябрь");
    startDay = countMonth(startDay, 31, "Октябрь");
    startDay = countMonth(startDay, 30, "Ноябрь");
    startDay = countMonth(startDay, 31, "Декабрь");
    system("pause");
}

