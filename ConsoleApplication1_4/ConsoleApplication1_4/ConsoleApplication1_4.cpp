﻿// ConsoleApplication1_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int time, lamp, curtains;
    while (true)
    {
        cout << "Время суток" << endl;
        cout << "0.Ночь" << endl;
        cout << "1.День" << endl;
        cout << "Введите время суток: ";
        cin >> time;
        system("cls");
        if (!time || time == 1)
            break;
    }
    while (true)
    {
        cout << "Состояние лампы" << endl;
        cout << "0.Выключена" << endl;
        cout << "1.Включена" << endl;
        cout << "Введите состояние лампы: ";
        cin >> lamp;
        system("cls");
        if (!lamp || lamp == 1)
            break;
    }
    while (true)
    {
        cout << "Состояние штор" << endl;
        cout << "0.Закрыты" << endl;
        cout << "1.Открыты" << endl;
        cout << "Введите состояние штор: ";
        cin >> curtains;
        system("cls");
        if (!curtains || curtains == 1)
            break;
    }
    cout << "В комнате ";
    if (time && curtains || lamp)
        cout << "светло" << endl;
    else
        cout << "темно" << endl;
    return 0;
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