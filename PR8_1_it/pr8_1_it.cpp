// Лабораторна робота  8.1. Варіант 27.
// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Визначити число входжень в послідовність групи букв "while".
// 2. Замінити кожну групу букв "while" трійкою зірочок "***".
// Спосіб 1: сканування рядка ітераційним способом.

#include <iostream>
#include <cstring>

using namespace std;

// Перевіряє, чи починається з позиції i групи букв "while".
// Умови з '&&' обчислюються зліва направо, тому за кінець рядка не виходимо.
bool IsWhile(const char* str, int i)
{
    return str[i] == 'w' &&
        str[i + 1] == 'h' &&
        str[i + 2] == 'i' &&
        str[i + 3] == 'l' &&
        str[i + 4] == 'e';
}

// Повертає кількість входжень групи букв "while" у рядок str.
int Count(const char* str)
{
    int k = 0;
    int i = 0;
    while (str[i] != 0)
        if (IsWhile(str, i))
        {
            k++;
            i += 5;                    // пропускаємо знайдену групу
        }
        else
            i++;

    return k;
}

// Замінює кожну групу "while" на "***".
// Результат записується у параметр str і повертається як результат функції
// (новий динамічний рядок, який потрібно звільнити через delete[]).
char* Change(char* str)
{
    size_t len = strlen(str);

    // "while" (5 символів) -> "***" (3 символи), тому результат не довший за вихідний рядок
    char* tmp = new char[len + 1];
    char* t = tmp;

    int i = 0;
    while (str[i] != 0)
        if (IsWhile(str, i))
        {
            *t++ = '*';
            *t++ = '*';
            *t++ = '*';
            i += 5;
        }
        else
            *t++ = str[i++];
    *t = '\0';

    strcpy_s(str, len+1, tmp);
   
    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'while'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    return 0;
}