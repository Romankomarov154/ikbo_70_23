#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void dir_merge(int portion, int n) {
    ifstream a1("A.txt"); //фаза разделения 
    ofstream b1("B.txt");
    ofstream c1("C.txt");
    string line;
    bool exit = false, firstB = true, firstC = true;
    if (a1.is_open() && b1.is_open() && c1.is_open())
    {
        while (!exit)
        {
            for (int i = 0; i < portion; i++)
            {
                if (!a1.eof())
                {
                    if (firstB)
                    {
                        getline(a1, line);
                        b1 << line;
                        firstB = false;
                    }
                    else
                    {
                        getline(a1, line);
                        b1 << endl << line;
                    }
                }
                else
                {
                    exit = true;
                    break;
                }
            }
            for (int i = 0; i < portion; i++)
            {
                if (!a1.eof())
                {
                    if (firstC)
                    {
                        getline(a1, line);
                        c1 << line;
                        firstC = false;
                    }
                    else
                    {
                        getline(a1, line);
                        c1 << endl << line;
                    }
                }
                else
                {
                    exit = true;
                    break;
                }
            }
        }
    }
    a1.close();
    b1.close();
    c1.close();

    ofstream a2("A.txt"); //фаза слияния 
    ifstream b2("B.txt");
    ifstream c2("C.txt");
    if (b2 && c2) 
    {
        int b = 0, c = 0;
        int indB = 0, indC = 0;
        string str = "";
        vector<string> arrayB, arrayC;
        while (!c2.eof() || !b2.eof()) 
        {
            arrayB = {}, arrayC = {};
            for (int i = 0; i < portion; i++) 
            {
                if (!b2.eof()) {
                    getline(b2, line);
                    arrayB.push_back(line);
                }
                else 
                    break;
            }
            for (int i = 0; i < portion; i++) 
            {
                if (!c2.eof()) {
                    getline(c2, line);
                    arrayC.push_back(line);
                }
                else 
                    break;
            }
            while (indB < arrayB.size() && indC < arrayC.size()) 
            {
                if (arrayB[indB] < arrayC[indC]) 
                {
                    str += arrayB[indB] + "\n";
                    indB++;
                }
                else 
                {
                    str += arrayC[indC] + "\n";
                    indC++;
                }
            }
            for (int i = indB; i < arrayB.size(); i++) 
                str += arrayB[i] + "\n";
            for (int i = indC; i < arrayC.size(); i++) 
                str += arrayC[i] + "\n";
            indB = 0, indC = 0;
        }
        a2 << str.substr(0, str.length() - 1);
        a2.close();
        b2.close();
        c2.close();
    }
    if (portion * 2 <= n) 
        dir_merge(portion * 2, n);
}

void est_merge() {
    ifstream a1("A.txt"); //фаза разделения 
    ofstream b1("B.txt");
    ofstream c1("C.txt");
    string line, linePred = "";
    string lineB = "", lineC = "";
    bool flag = true;
    vector<vector<string>> arrayB, arrayC; //массив "серий" чисел 
    vector<string> subarrayB, subarrayC; //массив, характеризующий очередную "серию" 
    if (a1) {
        while (getline(a1, line)) {
            if (linePred > line) { //сравниваем с предыдущим числом 
                flag = !flag;
                if (!subarrayB.empty()) {
                    arrayB.push_back(subarrayB); //суем полученную серию в массив серий 
                    subarrayB = {};
                }
                if (!subarrayC.empty()) {
                    arrayC.push_back(subarrayC); //суем полученную серию в массив серий 
                    subarrayC = {};
                }
            }
            if (flag) {
                lineB += line + "\n";
                subarrayB.push_back(line); //суем число в серию 
            }
            else {
                lineC += line + "\n";
                subarrayC.push_back(line); //суем число в серию 
            }
            linePred = line;
        }
        if (!subarrayB.empty()) 
            arrayB.push_back(subarrayB); //незасунутые остатки суем 
        if (!subarrayC.empty()) 
            arrayC.push_back(subarrayC);
        b1 << lineB.substr(0, lineB.length() - 1);
        c1 << lineC.substr(0, lineC.length() - 1);
        a1.close();
        b1.close();
        c1.close();
    }

    ofstream a2("A.txt"); //фаза слияния 
    ifstream b2("B.txt");
    ifstream c2("C.txt");
    if (b2 && c2) {
        int indB = 0, indС = 0;
        string s = "";
        int len = min(arrayB.size(), arrayC.size()); //чтобы рассматривать серии попарно 
        for (int i = 0; i < len; i++) {
            while (indB < arrayB[i].size() && indС < arrayC[i].size()) {
                if (arrayB[i][indB] < arrayC[i][indС]) {
                    s += arrayB[i][indB] + "\n";
                    indB++;
                }
                else {
                    s += arrayC[i][indС] + "\n";
                    indС++;
                }
            }
            for (int j = indB; j < arrayB[i].size(); j++) { //остатки 
                s += arrayB[i][j] + "\n";
            }
            for (int j = indС; j < arrayC[i].size(); j++) { //остатки 
                s += arrayC[i][j] + "\n";
            }
            indB = 0, indС = 0;
        }
        if (arrayB.size() != arrayC.size()) { //если осталась серия без пары, то суем эту серию в файл А 
            for (int j = 0; j < arrayB[arrayB.size() - 1].size(); j++) {
                s += arrayB[arrayB.size() - 1][j] + " ";
            }
        }
        a2 << s.substr(0, s.length() - 1);
        a2.close();
        b2.close();
        c2.close();
    }
    if (arrayB.size() != 1) est_merge();
}



int main()
{
    int len = 0;
    string str;
    ifstream a("A.txt");

    while (!a.eof())
    {
        getline(a, str);
        len++;
    }

    a.close();
    //dir_merge(1, len);
    est_merge();
}
