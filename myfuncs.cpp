#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void proverka(char s[], int n, int x) {
    int plus{0}, umnoj{0}, obshee{0};
    int i{};
    char d{};
    for (i = 0; i < n; i++) {
        d = s[i];
        if (d == '+') {
            plus++;
            obshee++;
        }
        if (d == '*') {
            umnoj++;
            obshee++;
        }
        if (d == '-') {
            obshee++;
        }
    }
    if (x == 1) {
        cout << "Количество символов + = ";
        cout << plus << endl;
        cout << "Количество символов * = ";
        cout << umnoj << endl;
        cout << "Количество символов + и - и * =";
        cout << obshee << endl;
    }
    else {
        ofstream fout("3labaout.txt");
        fout << "Количество символов + = ";
        fout << plus << endl;
        fout << "Количество символов * = ";
        fout << umnoj << endl;
        fout << "Количество символов + и - и * =";
        fout << obshee << endl;
    }
}

void fail() {
    int x;
    x = vivod();
    cout << "Хорошо, читаю файл." << endl;
    ifstream fin("3laba.txt");
    if (!fin.is_open())
        cout << "Файл невозможно открыть. Завершаю работу." << endl;
    else {
        int i{};
        int n{};
        fin >> n;
        char* s{};
        s = new char[n];
        for (i = 0; i < n; i++) {
            fin >> s[i];
        }
        proverka(s, n, x);
    }
}

int end_cons() {
    cout << "Хотите повторить ввод исходных данных ? Да — 1, Нет — 0." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        start();
    }
    else {
        if (a[0] == '0') {
            cout << "Хорошо, завершаю работу" << endl;
            return 0;
        }
        else {
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            end_cons();
        }
    }
}

void cons() {
    int x{};
    int i{};
    x = vivod();
    cout << "Хорошо, вводите данные. Для начала введите число n." << endl;
    int n{};
    cin >> n;
    char* s{};
    s = new char[n];
    cout << "Введите символы." << endl;
    for (i = 0; i < n; i++) {
        cin >> s[i];
    }
    proverka(s, n, x);
    end_cons();
}

int vivod() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите вывести данные в файл или консоль?" << endl;
    cout << "0 - в файл, 1 - в консоль." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        return 1;
    }
    else {
        if (a[0] == '0') {
            return 0;
        }
        else {
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            vivod();
        }
    }
}

void start() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        cons();
    }
    else {
        if (a[0] == '0') {
            fail();
        }
        else {
            cout << "Ошибка ввода. Попробуйте снова." << endl;
            start();
        }
    }
}