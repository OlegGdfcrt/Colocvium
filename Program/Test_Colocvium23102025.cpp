#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <locale.h>
#include "Colocvium23102025.h"

using namespace std;
using namespace Colocvium23102025;

void runTests() {
    cout << "=== ������ UNIT-������ ===" << endl;

    int passed = 0;
    int total = 0;

    try {
        auto fib0 = FibonacciGenerator::generateFirstNFibonacci(0);
        if (fib0.empty()) {
            cout << "���� 1 �������: 0 ����� ���������" << endl;
            passed++;
        }
        else {
            cout << "���� 1 �� �������: 0 ����� ���������" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "���� 1 �� �������: ����������" << endl;
        total++;
    }

    try {
        auto fib5 = FibonacciGenerator::generateFirstNFibonacci(5);
        if (fib5.size() == 5 && fib5[0] == 0 && fib5[4] == 3) {
            cout << "���� 2 �������: 5 ����� ���������" << endl;
            passed++;
        }
        else {
            cout << "���� 2 �� �������: 5 ����� ���������" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "���� 2 �� �������: ����������" << endl;
        total++;
    }

    try {
        if (PalindromeChecker::isPalindrome(121) && !PalindromeChecker::isPalindrome(123)) {
            cout << "���� 3 �������: �������� �����������" << endl;
            passed++;
        }
        else {
            cout << "���� 3 �� �������: �������� �����������" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "���� 3 �� �������: ����������" << endl;
        total++;
    }

    try {
        if (PalindromeChecker::isPalindrome(0) && PalindromeChecker::isPalindrome(7)) {
            cout << "���� 4 �������: ����������� �����" << endl;
            passed++;
        }
        else {
            cout << "���� 4 �� �������: ����������� �����" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "���� 4 �� �������: ����������" << endl;
        total++;
    }

    try {
        LinkedList<int> list1;
        list1.append(1);
        list1.append(2);
        list1.append(3);
        list1.reverseIterative();
        auto result = list1.toVector();
        if (result.size() == 3 && result[0] == 3 && result[2] == 1) {
            cout << "���� 5 �������: �������� ������" << endl;
            passed++;
        }
        else {
            cout << "���� 5 �� �������: �������� ������" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "���� 5 �� �������: ����������" << endl;
        total++;
    }

    try {
        LinkedList<string> list2;
        list2.append("hello");
        list2.append("world");
        list2.reverseIterative();
        auto result = list2.toVector();
        if (result.size() == 2 && result[0] == "world") {
            cout << "���� 6 �������: ������ �����" << endl;
            passed++;
        }
        else {
            cout << "���� 6 �� �������: ������ �����" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "���� 6 �� �������: ����������" << endl;
        total++;
    }

    try {
        FibonacciGenerator::generateFirstNFibonacci(10000);
        cout << "���� 7 �� �������: ��������� ������� �����" << endl;
        total++;
    }
    catch (const invalid_argument&) {
        cout << "���� 7 �������: ��������� ������� �����" << endl;
        passed++;
        total++;
    }
    catch (...) {
        cout << "���� 7 �� �������: �������� ����������" << endl;
        total++;
    }

    cout << "==========================================" << endl;
    cout << "���������: " << passed << "/" << total << " ������ ��������" << endl;
    cout << "==========================================" << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");

    runTests();

    cout << "\n������� Enter ��� ������...";
    cin.get();
    return 0;
}