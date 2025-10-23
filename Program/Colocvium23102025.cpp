#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <locale.h>
#include "Colocvium23102025.h"

using namespace std;
using namespace Colocvium23102025;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void demonstrateFibonacci() {
    cout << "=== Генерация чисел Фибоначчи ===" << endl;
    cout << "Введите количество чисел Фибоначчи: ";

    int n;
    if (!(cin >> n)) {
        cout << "Ошибка: введите целое число!" << endl;
        clearInputBuffer();
        return;
    }

    if (n < 0) {
        cout << "Ошибка: количество не может быть отрицательным!" << endl;
        return;
    }

    try {
        auto result = FibonacciGenerator::generateFirstNFibonacci(n);
        cout << "Первые " << n << " чисел Фибоначчи: ";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

void checkPalindrome() {
    cout << "=== Проверка палиндрома ===" << endl;
    cout << "Введите число для проверки: ";

    long long number;
    if (!(cin >> number)) {
        cout << "Ошибка: введите целое число!" << endl;
        clearInputBuffer();
        return;
    }

    try {
        bool isPal = PalindromeChecker::isPalindrome(number);
        cout << "Число " << number << " - это "
            << (isPal ? "палиндром" : "НЕ палиндром") << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

void demonstrateLinkedList() {
    cout << "=== Работа со связным списком ===" << endl;
    cout << "Введите числа для добавления в список (через пробел, окончание - Enter): ";

    clearInputBuffer();
    string input;
    getline(cin, input);

    LinkedList<int> list;
    size_t pos = 0;

    try {
        while (pos < input.length()) {
            size_t next_pos = input.find(' ', pos);
            string num_str = input.substr(pos, next_pos - pos);

            if (!num_str.empty()) {
                int num = stoi(num_str);
                list.append(num);
            }

            if (next_pos == string::npos) break;
            pos = next_pos + 1;
        }

        cout << "Исходный список: ";
        auto original = list.toVector();
        for (size_t i = 0; i < original.size(); ++i) {
            cout << original[i];
            if (i < original.size() - 1) cout << " -> ";
        }
        cout << endl;

        list.reverseIterative();

        cout << "Развернутый список: ";
        auto reversed = list.toVector();
        for (size_t i = 0; i < reversed.size(); ++i) {
            cout << reversed[i];
            if (i < reversed.size() - 1) cout << " -> ";
        }
        cout << endl;

    }
    catch (const exception& e) {
        cout << "Ошибка: некорректный ввод!" << endl;
    }
}

void showMenu() {
    cout << "\n==========================================" << endl;
    cout << "    COLOCVIUM23102025 - ГЛАВНОЕ МЕНЮ" << endl;
    cout << "==========================================" << endl;
    cout << "1. Числа Фибоначчи" << endl;
    cout << "2. Проверка палиндрома" << endl;
    cout << "3. Разворот связного списка" << endl;
    cout << "0. Выход" << endl;
    cout << "==========================================" << endl;
    cout << "Выберите опцию: ";
}

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "Добро пожаловать в Colocvium23102025!" << endl;
    cout << "Промышленная реализация алгоритмов на C++" << endl;

    int choice;

    do {
        showMenu();

        if (!(cin >> choice)) {
            cout << "Ошибка: введите число от 0 до 3!" << endl;
            clearInputBuffer();
            continue;
        }

        switch (choice) {
        case 1:
            demonstrateFibonacci();
            break;
        case 2:
            checkPalindrome();
            break;
        case 3:
            demonstrateLinkedList();
            break;
        case 0:
            cout << "Выход из программы. До свидания!" << endl;
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}