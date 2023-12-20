/************************************************************
* Русакова Екатерина Алексеевна, ПИ-231                     *
* Share-Link: https://www.onlinegdb.com/online_c++_compiler *
* Дата: 28.11.2023                                          *
*************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

// Функция для определения високосного года
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для определения количества дней в месяце
int daysInMonth (int month, int year) {
    if (month == 2) {
        return isLeapYear (year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Функция для вывода календаря
void printCalendar(int year) {

    for (int month = 1; month <= 12; ++month) {
        // Вывод названия месяца
        switch (month) {
            case 1: cout << "Январь   "; 
            break;
            case 2: cout << "Февраль  "; 
            break;
            case 3: cout << "Март     "; 
            break;
            case 4: cout << "Апрель   "; 
            break;
            case 5: cout << "Май      "; 
            break;
            case 6: cout << "Июнь     "; 
            break;
            case 7: cout << "Июль     "; 
            break;
            case 8: cout << "Август   "; 
            break;
            case 9: cout << "Сентябрь "; 
            break;
            case 10: cout << "Октябрь  "; 
            break;
            case 11: cout << "Ноябрь   "; 
            break;
            case 12: cout << "Декабрь  "; 
            break;
        }

        cout << "\nПн Вт Ср Чт Пт Сб Вс\n";

        int totalDays = daysInMonth(month, year);
        int currentDay = 1;
        int startingDay = (year - 1 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + (13 * 13 + 8) / 5) % 7;

        for (int index = 0; index < startingDay; ++index) {
            cout << "   ";
        }

        while (currentDay <= totalDays) {
            for (int index = startingDay; index < 7 && currentDay <= totalDays; ++index) {
                cout << setw(2) << currentDay << " ";
                ++currentDay;
            }
            startingDay = 0;
            cout << endl;
        }
    
        // Вывод пустой строки между месяцами
        cout << endl;
        if (month % 3 == 0 && month != 12) {
            cout << "-------------------------\n\n";
    }
}

int main() {
    int year;
    cout << "Введите год: ";
    cin >> year;

    printCalendar(year);

    return 0;
}
