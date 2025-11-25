#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

vector<int> numbers1{3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
vector<int> reverseNumbers1{0, 0, 0};

vector<int> numbers2{88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
vector<int> reverseNumbers2{0, 0, 0};

vector<int> numbers3{24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
vector<int> reverseNumbers3{0, 0, 0};

void merge_sort(vector<int> &numbers, vector<int> &reverseNumbers)
{
  if (numbers.size() == 0) // если длина исходного массива == 0(он пустой), ...
  {
    reverseNumbers.clear();                // очистить возвратный массив(сделать его длину 0)...
    std::cout << "Массив пустой!" << endl; // вывести сообщение,
    return;                                // прервать подпрограмму.
  };

  if (numbers.size() == 1) // если в исходном массиве всего одно число...
  {
    reverseNumbers.clear();               // очищаем возвратный массив...
    reverseNumbers.push_back(numbers[0]); // внести единственный элемент в возвратный массив...
    return;                               // прервать подпрограмму.
  };

  if (numbers.size() > 1) // если в исходном массиве 2 или более чисел...
  {
    reverseNumbers.clear();                       // очищаем возвратны массив...
    int summaryLength = numbers.size();           // суммарная длина несортированного массива
    int leftLength = summaryLength / 2;           // левая длина = суммарная /2;
    int rightLength = summaryLength - leftLength; // правая длина = суммарная - левая

    vector<int> leftNumbers{};  // создаём левый массив
    vector<int> rightNumbers{}; // создаём правый массив

    for (int i = 0; i < leftLength; ++i)
    {
      leftNumbers.push_back(numbers[i]); // заполняем левый массив на его длину...
    };

    for (int i = 0; i < rightLength; ++i)
    {
      rightNumbers.push_back(numbers[i + leftLength]); // заполняем правый массив на его длину из осн. масс. со смещением
    };

    vector<int> reversLeftNumbers{};              // левый массив для возвращения
    vector<int> reversRightNumbers{};             // правый массив для возвращения
    merge_sort(leftNumbers, reversLeftNumbers);   // рекурсия левого массива
    merge_sort(rightNumbers, reversRightNumbers); // рекурсия правого массива
    int a = 0;                                    // начальное значение индекса левого возвращённого массива
    int b = 0;                                    // начальное значение индекса правого возвращённого массива
    while (true)                                  // цикл;
    {
      if ((a == reversLeftNumbers.size()) && (b < reversRightNumbers.size())) // если левый кончился, а правый -нет...
      {
        reverseNumbers.push_back(reversRightNumbers[b]); // добавить из правого
        ++b;                                             // инкрементируем указатель правого
        continue;                                        // обновляем цикл
      };
      if ((b == reversRightNumbers.size()) && (a < reversLeftNumbers.size())) // если правый кончился, а левый - нет...
      {
        reverseNumbers.push_back(reversLeftNumbers[a]); // добавляем из левого
        ++a;                                            // инкрементируем указатель левого
        continue;                                       // обновляем цикл
      };
      if ((a == reversLeftNumbers.size()) && (b == reversRightNumbers.size())) // если кончились оба...
      {
        break; // слом цикла
      }
      if (reversLeftNumbers[a] <= reversRightNumbers[b]) // если левый меньше правого...
      {
        reverseNumbers.push_back(reversLeftNumbers[a]); // добавляем из левого...
        ++a;                                            // инкрементируем указатель левого
        continue;                                       // обновляем цикл
      };
      if (reversRightNumbers[b] < reversLeftNumbers[a]) // если правый меньше левого...
      {
        reverseNumbers.push_back(reversRightNumbers[b]); // добавляем из правого...
        ++b;                                             // инкрементируем указатель правого...
        continue;                                        // обновляем цикл.
      };
    }; // дно цикла слияния массивов
    return; // прерывание условия
  };
  return; // безусловное прерывание подпрограммы;
};

void show(vector<int> &numbers, vector<int> &reverseNumbers) // подпрограмма отображения сортировки массивов
{
  SetConsoleOutputCP(CP_UTF8); // кириллич. символы;

  cout << "Исходный массив:" << endl; // выводим объявление исходного массива...
  for (int i = 0; i < numbers.size(); ++i)
  {
    cout << numbers[i] << " "; // отображаем исходный массив...
  };
  cout << endl; // прерываем строчку...

  merge_sort(numbers, reverseNumbers); // сортируем наш массив;

  cout << "Отсортированный массив:" << endl; // выводим объявление
  for (int i = 0; i < reverseNumbers.size(); ++i)
  {
    cout << reverseNumbers[i] << " "; // отображаем сортированный массив
  };
  cout << endl; // прерываем строчку
  return;       // прерываем подпрограмму
};

int main() // основная подпрограмма
{
  show(numbers1, reverseNumbers1); // отображаем первый массив
  show(numbers2, reverseNumbers2); // отображаем второй массив
  show(numbers3, reverseNumbers3); // отображаем третий массив

  return 0;
};