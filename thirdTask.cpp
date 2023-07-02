#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>

using namespace std;

void readDataFromFile() {
    string path = "..\\data.txt";
//    cout << path;
    ifstream data(path);
    if (data) {
        cout << "Файл открылся\nСодержимое файла:" << endl;
        string s;
        while (!data.eof()) {
            getline(data, s);
            cout << s << endl;
        }
        data.close();
    } else {
        cout << "Файл не открылся" << endl;
    }
}

void appendDataToFile() {
    string path = "..\\data.txt";
    ofstream data(path, ios_base::app);
    if (data) {
        cout << "Дописывайте данные:" << endl;
        string s;
        getline(cin, s);
        while (s != "exit") {
            data << s << endl;
            getline(cin, s);
        }
        data.close();
    } else {
        cout << "Файл не открылся" << endl;
    }

}

void rewriteDataFile() {
    string path = "..\\data.txt";
    ofstream data(path);
    if (data) {
        cout << "Введите данные:" << endl;
        string s;
        getline(cin, s);
        while (s != "exit") {
            data << s << endl;
            getline(cin, s);
        }
        data.close();
    } else {
        cout << "Файл не открылся";
    }
}

int main() {

    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите 0, если хотите прочитать содержимое файла" << endl
         << "Введите 1, если хотите дописать данные в файл" << endl
         << "Введите 2, если хотите перезаписать данные в файле" << endl;
    int n;
    cin >> n;
    cin.ignore();
    switch (n) {
        case 0: {
            readDataFromFile();
            break;
        }
        case 1:
            appendDataToFile();
            break;
        case 2:
            rewriteDataFile();
            break;
        default:
            cout << "Вы не попали в нужную категорию";
    }
}