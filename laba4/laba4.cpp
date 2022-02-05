#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void counter(string s[]) {
    
}

void fail(string path) {
    cout << "Хорошо, читаю файл." << endl;
    if (path == "") {
        path = "4laba.txt";
    }
    ifstream fin(path);
    while (!fin.is_open()) {
        cout << "Файл невозможно открыть. Повторите имя файла." << endl;
        cin >> path;
        cout << "Хорошо, читаю файл." << endl;
        ifstream fin(path);
    }
    int n;
    fin >> n;
    string* s;
    fin >> s[n];
    counter(s);
}

void cons() {
    cout << "Хорошо, вводите данные. Для начала введите число n." << endl;
    int n;
    cin >> n;
    cout << "Теперь введите символы s1...sn." << endl;
    string* s;
    cin >> s[n];
    counter(s);
    cout << "Хотите повторить ввод исходных данных ? Да — 1, Нет — 0." << endl;
    int x;
    cin >> x;
    if (x == 1) {
        cons();
    }
    else {
        cout << "Хорошо, завершаю работу." << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
    int a;
    cin >> a;
    if (a == 1) {
        cons();
    }
    else {
        cout << "Введите путь до файла." << endl;
        string path;
        cin >> path;
        fail(path);
    }
}
