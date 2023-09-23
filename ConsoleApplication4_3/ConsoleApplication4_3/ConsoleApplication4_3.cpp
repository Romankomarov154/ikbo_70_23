﻿// ConsoleApplication4_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

const float PI = 3.1415927;

float S(float r)
{
    return PI * pow(r, 2);
}

float S(float a, float b)
{
    return a * b;
}

float S(float a, float b, float c)
{
    float p = (a + b + c) / 2.0;
    return sqrt((p - a) * (p - b) * (p - c));
}

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Меню" << endl;
    cout << "0.Круг" << endl;
    cout << "3.Треугольник" << endl;
    cout << "4.Прямоугольник" << endl;
    int choice;
    float a, b, c;
    cin >> choice;
    switch (choice)
    {
    case 0:
        cout << "Введите радиус: ";
        cin >> a;
        cout << S(a) << endl;
        break;
    case 3:
        cout << "Введите стороны квадрата: ";
        cin >> a >> b;
        cout << S(a, b) << endl;
        break;
    case 4:
        cout << "Введите стороны треугольника: ";
        cin >> a >> b >> c;
        cout << S(a, b, c) << endl;
        break;
    default:
        cout << "Введено несуществующее значение" << endl;
        break;
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
