#include <iostream>
 
using namespace std;
 
int month (int startDay, int numDays, char* name) {
  cout << "                      " << name << endl;
  cout << "Пн\tВт\tСр\tЧт\tПт\tСб\tВс" << endl;
  for (int index = 1; index < startDay; ++index) {
    cout << "\t";
  }
  for (int index = 1; index <= numDays; ++index) {
    cout << index << "\t";
    if ((startDay + index) % 7 == 1) {
      cout << endl;
    }
  }
  cout << endl;
  cout << endl;
  startDay = (startDay + numDays) % 7;
  if (startDay == 0) {
    startDay = 7;
  }
  return startDay;
}
 
int main() {
 
  int leap, notLeap, Feb, index; 
  cout << "Год високосный? (0 - нет; 1 - да):";
  cin >> leap;
  if (leap == 1) {
    Feb = 29;
  } else {
    Feb = 28;
  }
 
  cout << "Введите с какого дня недели начинается Январь (1-7 = пн-вс):";
  cin >> notLeap;
  cout << endl;
 
  notLeap = month(notLeap, 31, "Январь");
  notLeap = month(notLeap, Feb, "Февраль");
  notLeap = month(notLeap, 31, "Март");
  notLeap = month(notLeap, 30, "Апрель");
  notLeap = month(notLeap, 31, "Май");
  notLeap = month(notLeap, 30, "Июнь");
  notLeap = month(notLeap, 31, "Июль");
  notLeap = month(notLeap, 31, "Август");
  notLeap = month(notLeap, 30, "Сентябрь");
  notLeap = month(notLeap, 31, "Октябрь");
  notLeap = month(notLeap, 30, "Ноябрь");
  notLeap = month(notLeap, 31, "Декабрь");
  system("pause");
}
