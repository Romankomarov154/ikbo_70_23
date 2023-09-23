// ConsoleApplication4_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void transNatation(string inNum, int in, int out)
{
    string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string outNum = "";
    int num = 0;
    bool right;
    for (int i = 0; i < inNum.length(); i++)
    {
        right = false;
        for (int j = 0; j < in; j++)
        {
            if (inNum[i] == alphabet[j])
            {
                num += j * pow(in, inNum.length() - i - 1);
                right = true;
                break;
            }
        }
        if (!right)
        {
            cout << "ERROR! WRONG NUMBER" << endl;
            return;
        }
    }
    while (num)
    {
        outNum += alphabet[num % out];
        num /= out;
    }
    char temp;
    for (int i = 0; i < outNum.length()/2; i++)
    {
        temp = outNum[outNum.length() - i - 1];
        outNum[outNum.length() - i - 1] = outNum[i];
        outNum[i] = temp;
    }
    cout << outNum;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    string num;
    int in, out;
    cout << "Введите число, входную СС, выходную СС: ";
    cin >> num >> in >> out;
    transNatation(num, in, out);
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
