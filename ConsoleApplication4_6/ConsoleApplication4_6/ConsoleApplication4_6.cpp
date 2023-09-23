// ConsoleApplication4_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
// #include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    map<char, int> alphabet;
    alphabet['I'] = 1;
    alphabet['V'] = 5;
    alphabet['X'] = 10;
    alphabet['L'] = 50;
    alphabet['C'] = 100;
    alphabet['D'] = 500;
    alphabet['M'] = 1000;
    string roman;
    int sum = 0;
    int  num = 0;
    cout << "Введите число: "s << endl;
    cin >> roman;
    int i = 0;
    boolean flag = false;
    while (i < roman.size()) {
        num += alphabet[roman[i]];
        if (alphabet[roman[i]] == 0)
        {
            cout << "Ошибка ввода данных" << endl;
            flag = true;
            break;
        }
        while (i < roman.size() && alphabet[roman[i + 1]] == alphabet[roman[i]]) {
            num += alphabet[roman[i]];
            i++;
        }
        if (i < roman.size() && alphabet[roman[i + 1]] > alphabet[roman[i]]) {
            sum -= num;
        }
        else {
            sum += num;
        }
        i++;
        num = 0;
    }
    if (!flag)
    {
        cout << sum << endl;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
