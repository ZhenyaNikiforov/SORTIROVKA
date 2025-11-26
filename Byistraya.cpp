/*-- Файл, посвящённый БЫСТРОЙ сортирвке массивов
(задача №2 в домашней работе) --*/

#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

vector<int> numbers1{3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
vector<int> reversNumbers1{0, 0, 0};

vector<int> numbers2{88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
vector<int> reversNumbers2{0, 0, 0};

vector<int> numbers3{24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
vector<int> reversNumbers3{0, 0, 0};

void quick_sort(std::vector<int> &numbers, std::vector<int> &reversNumbers) // подпрограмма быстрой сортировки;
{
  if (numbers.size() == 0) // если массив пустой, то...
  {
    reversNumbers.clear(); // очищаем возвратный массив...
    return;                // ...и прерываем подпрограмму;
  };

  if (numbers.size() == 1) // если в массиве один элемент, то...
  {
    reversNumbers.clear();               // очищаем возвратный массив,
    reversNumbers.push_back(numbers[0]); // заносим этот единственный элемент в возвр. масс.,
    return;                              //...и прерываем подпрограмму.
  };

  if (numbers.size() > 1) // если в массиве два или более элементов, то...
  {
    reversNumbers.clear();                         // очищаем возвратный массив;
    int root = numbers[(numbers.size() - 1)];      // корень - последний элемент массива;
    std::vector<int> leftNumbers{};                // левый массив;
    std::vector<int> rightNumbers{};               // правый массив;
    for (int i = 0; i < (numbers.size() - 1); ++i) // перебираем осн. мас-в кроме послед. элем. (корня);
    {
      if (numbers[i] < root) // если текущ. элем. меньше корня, то...;
      {
        leftNumbers.push_back(numbers[i]); // ...вносим его в левый массив;
      }
      else // если равен или больше, то...;
      {
        rightNumbers.push_back(numbers[i]); //...вносим его в правый массив;
      }
    }; // дно цикла заполнения левого и правого массивов;
    std::vector<int> newLeftNumbers{};              // новый левый массив;
    std::vector<int> newRightNumbers{};             // новый правый массив;
    quick_sort(leftNumbers, newLeftNumbers);        // рекурсия левого массива с нов. лев. масс.;
    quick_sort(rightNumbers, newRightNumbers);      // рекурсия правого массива с нов. прав. масс.;
    for (int i = 0; i < newLeftNumbers.size(); ++i) // начинаем заполнять возвратный массив;
    {
      reversNumbers.push_back(newLeftNumbers[i]); // заносим новый левый массив в возвратный массив;
    };
    reversNumbers.push_back(root);                   // заносим корень;
    for (int i = 0; i < newRightNumbers.size(); ++i) // если пустой, цикл не начнётся;
    {
      reversNumbers.push_back(newRightNumbers[i]); // заносим новый правый массив в возвратный массив;
    };
    return; // прерываем подпрограмму;
  };
  return; // безусловно прерываем подпрограмму
};

void show(vector<int> &numbers, vector<int> &reversNumbers) // подпрограмма выведения массива
{
  SetConsoleOutputCP(CP_UTF8);       // кириллич. символы
  cout << "Первоначальный массив: "; // первоначальный массив
  for (int i = 0; i < numbers.size(); ++i)
  {
    cout << numbers[i] << " "; // показываем первоначальный массив
  };
  std::cout << endl;                  // переносим строчку
  quick_sort(numbers, reversNumbers); // сортируем первоначальный массив
  cout << "Отсортированный массив: "; // отсортированный массив
  for (int i = 0; i < reversNumbers.size(); ++i)
  {
    cout << reversNumbers[i] << " "; // показываем отсортированный массив
  };
  cout << endl; // переносим строчку
  return;       // прерываем подпрограмму
};

int main() // основная подпрограмма;
{
  show(numbers1, reversNumbers1);
  show(numbers2, reversNumbers2);
  show(numbers3, reversNumbers3);
  return 0;
}