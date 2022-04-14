#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Вы хотите ввести данные из файла или из консоли?" << endl;
    cout << "0 - из файла, 1 - из консоли." << endl;
    int a;
    (cin >> a).get();
    if (a == 1) {
        return 0;
    }
    else {
        cout << "Введите полное имя файла. Напишите нет, если не хотите вводить полное имя." << endl;
        string filename;
        getline(cin, filename);
        ofstream fout(filename.c_str());
        fout << "i'm dead";
        fout.close();
    }
}
