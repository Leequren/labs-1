#include<iostream>
#include<string>
#include<windows.h>

using namespace std;

void inputIntOperation() {
    cout << "Введите:" << endl << "\t 0, если хотите сложить 2 числа" << endl << "\t 1, если хотите умножить 2 числа"
         << endl << "\t 2, если хотите найти разность двух чисел" << endl
         << "\t 3, если хотите найти частное двух чисел" << endl;
    int operationNumber;
    cin >> operationNumber;
    cout << "Введите числа: \n";
    int a, b;
    cin >> a >> b;

    switch (operationNumber) {
        case 0:
            cout << "Сумма: " << a + b;
            break;
        case 1:
            cout << "Умножение: " << a * b;
            break;
        case 2:
            cout << "Разность: " << a - b;
            break;
        case 3:
            cout << "Частное: " << a / b;
            break;
    }
    cout << endl;
}

void inputDoubleOperation() {
    cout << "Введите:" << endl << "\t 0, если хотите сложить 2 числа" << endl << "\t 1, если хотите умножить 2 числа"
         << endl << "\t 2, если хотите найти разность двух чисел" << endl
         << "\t 3, если хотите найти частное двух чисел" << endl;
    int operationNumber;
    cin >> operationNumber;
    cout << "Введите числа: \n";
    double a, b;
    cin >> a >> b;

    switch (operationNumber) {
        case 0:
            cout << "Сумма: " << a + b;
            break;
        case 1:
            cout << "Умножение: " << a * b;
            break;
        case 2:
            cout << "Разность: " << a - b;
            break;
        case 3:
            cout << "Частное: " << a / b;
            break;
    }
    cout << endl;
}

bool checkPalindrome(string &s) {
    for (int i = 0; i < s.length() / 2; ++i) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Введите 0, если хотите выполнить выполнить арифметические операции с целыми числами" << endl
         << "Введите 1, если хотите выполнить операции с вещественными числами" << endl
         << "Введите 2, если хотите выполнить проверку строки на палиндромность" << endl;
    int n;
    cin >> n;
    switch (n) {
        case 0:
            inputIntOperation();
            break;
        case 1:
            inputDoubleOperation();
            break;
        case 2: {
            cout << "Введите строку: \n";
            string s;
            cin >> s;
            string ans = int(checkPalindrome(s)) == 0 ? "Ложь" : "Правда";
            cout << "Результат проверки на палиндромность: " << ans << endl;
        }
            break;
        default:
            cout << "Вы не попали в нужную категорию";
    }
}