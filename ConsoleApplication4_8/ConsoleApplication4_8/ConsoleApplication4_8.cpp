﻿// ConsoleApplication4_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int a[3][4] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
    float b[4][2] = { {1.2, 0.5}, {2.8, 0.4}, {5, 1}, {2, 1.5} }, c[3][2];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            c[i][j] = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 4; k++)
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
    cout << "Деньги вырученные с продажи:\t";
    float sale = 0;
    for (int i = 0; i < 3; i++)
    {
        cout << c[i][0] << "\t";
        sale += c[i][0];
    }
    cout << endl;
    float commission = 0;
    cout << "Комиссионные:\t\t\t";
    for (int i = 0; i < 3; i++)
    {
        cout << c[i][1] << "\t";
        commission += c[i][1];
    }
    cout << endl;

    cout << "Общая сумма денег за товары:\t" << sale << endl;
    cout << "Общие комиссионные:\t\t" << commission << endl;
    cout << "Общая сумма денег:\t\t" << sale + commission << endl;
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