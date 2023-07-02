#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<map>
#include<windows.h>

using namespace std;

vector<int> stringNumbersToArray(string &inputString) {
    vector<int> data;
    string curString = "";
    for (char i: inputString) {
        if (i != ' ') {
            curString += i;
        } else {
            data.push_back(stoi(curString));
            curString = "";
        }
    }
    if (curString != "") {
        data.push_back(stoi(curString));
    }
    return data;

}

void sortInputArray() {
    cout << "Введите числа через пробел:" << endl;
    string s;
    getline(cin, s);
    vector<int> numbers = stringNumbersToArray(s);
    sort(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }
}


void countInputSymbols() {
    cout << "Введите строку символов:" << endl;
    string s;
    getline(cin, s);
    map<int, int> m;
    for (int i = 0; i < s.length(); ++i) {
        if (!m[int(s[i])]) {
            m[int(s[i])] = 0;
        }
        m[int(s[i])]++;
    }
    for (auto x: m) {
        cout << char(x.first) << ": " << x.second << endl;
    }
    cout << endl;
}

void deleteInputDuplicates() {
    cout << "Введи строку символов: " << endl;
    string s;
    getline(cin, s);
    unordered_set<char> ust;
    for (char i : s) {
        ust.insert(i);
    }
    for (char numb: ust) {
        cout << numb;
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите 0, если хотите отсортировать массив по возрастанию" << endl
         << "Введите 1, если хотите удалить дубликаты с помощью set" << endl
         << "Введите 2, если хотите посчитать количества букв в строке" << endl;
    int n;
    cin >> n;
    cin.ignore();
    switch (n) {
        case 0:
            sortInputArray();
            break;
        case 1:
            deleteInputDuplicates();
            break;
        case 2:
            countInputSymbols();
            break;
        default:
            cout << "Вы не попали в нужную категорию";
    }
}