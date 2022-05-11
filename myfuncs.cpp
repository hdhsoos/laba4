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
        cout << "���������� �������� + = ";
        cout << plus << endl;
        cout << "���������� �������� * = ";
        cout << umnoj << endl;
        cout << "���������� �������� + � - � * =";
        cout << obshee << endl;
    }
    else {
        ofstream fout("3labaout.txt");
        fout << "���������� �������� + = ";
        fout << plus << endl;
        fout << "���������� �������� * = ";
        fout << umnoj << endl;
        fout << "���������� �������� + � - � * =";
        fout << obshee << endl;
    }
}

void fail() {
    int x;
    x = vivod();
    cout << "������, ����� ����." << endl;
    ifstream fin("3laba.txt");
    if (!fin.is_open())
        cout << "���� ���������� �������. �������� ������." << endl;
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
    cout << "������ ��������� ���� �������� ������ ? �� � 1, ��� � 0." << endl;
    char a[256]{};
    cin >> a;
    if (a[0] == '1') {
        start();
    }
    else {
        if (a[0] == '0') {
            cout << "������, �������� ������" << endl;
            return 0;
        }
        else {
            cout << "������ �����. ���������� �����." << endl;
            end_cons();
        }
    }
}

void cons() {
    int x{};
    int i{};
    x = vivod();
    cout << "������, ������� ������. ��� ������ ������� ����� n." << endl;
    int n{};
    cin >> n;
    char* s{};
    s = new char[n];
    cout << "������� �������." << endl;
    for (i = 0; i < n; i++) {
        cin >> s[i];
    }
    proverka(s, n, x);
    end_cons();
}

int vivod() {
    setlocale(LC_ALL, "rus");
    cout << "�� ������ ������� ������ � ���� ��� �������?" << endl;
    cout << "0 - � ����, 1 - � �������." << endl;
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
            cout << "������ �����. ���������� �����." << endl;
            vivod();
        }
    }
}

void start() {
    setlocale(LC_ALL, "rus");
    cout << "�� ������ ������ ������ �� ����� ��� �� �������?" << endl;
    cout << "0 - �� �����, 1 - �� �������." << endl;
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
            cout << "������ �����. ���������� �����." << endl;
            start();
        }
    }
}