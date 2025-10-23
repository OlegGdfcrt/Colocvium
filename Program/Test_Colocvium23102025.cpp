#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <locale.h>
#include "Colocvium23102025.h"

using namespace std;
using namespace Colocvium23102025;

void runTests() {
    cout << "=== ÇÀÏÓÑÊ UNIT-ÒÅÑÒÎÂ ===" << endl;

    int passed = 0;
    int total = 0;

    try {
        auto fib0 = FibonacciGenerator::generateFirstNFibonacci(0);
        if (fib0.empty()) {
            cout << "ÒÅÑÒ 1 ÏÐÎÉÄÅÍ: 0 ÷èñåë Ôèáîíà÷÷è" << endl;
            passed++;
        }
        else {
            cout << "ÒÅÑÒ 1 ÍÅ ÏÐÎÉÄÅÍ: 0 ÷èñåë Ôèáîíà÷÷è" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "ÒÅÑÒ 1 ÍÅ ÏÐÎÉÄÅÍ: èñêëþ÷åíèå" << endl;
        total++;
    }

    try {
        auto fib5 = FibonacciGenerator::generateFirstNFibonacci(5);
        if (fib5.size() == 5 && fib5[0] == 0 && fib5[4] == 3) {
            cout << "ÒÅÑÒ 2 ÏÐÎÉÄÅÍ: 5 ÷èñåë Ôèáîíà÷÷è" << endl;
            passed++;
        }
        else {
            cout << "ÒÅÑÒ 2 ÍÅ ÏÐÎÉÄÅÍ: 5 ÷èñåë Ôèáîíà÷÷è" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "ÒÅÑÒ 2 ÍÅ ÏÐÎÉÄÅÍ: èñêëþ÷åíèå" << endl;
        total++;
    }

    try {
        if (PalindromeChecker::isPalindrome(121) && !PalindromeChecker::isPalindrome(123)) {
            cout << "ÒÅÑÒ 3 ÏÐÎÉÄÅÍ: ïðîâåðêà ïàëèíäðîìîâ" << endl;
            passed++;
        }
        else {
            cout << "ÒÅÑÒ 3 ÍÅ ÏÐÎÉÄÅÍ: ïðîâåðêà ïàëèíäðîìîâ" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "ÒÅÑÒ 3 ÍÅ ÏÐÎÉÄÅÍ: èñêëþ÷åíèå" << endl;
        total++;
    }

    try {
        if (PalindromeChecker::isPalindrome(0) && PalindromeChecker::isPalindrome(7)) {
            cout << "ÒÅÑÒ 4 ÏÐÎÉÄÅÍ: îäíîçíà÷íûå ÷èñëà" << endl;
            passed++;
        }
        else {
            cout << "ÒÅÑÒ 4 ÍÅ ÏÐÎÉÄÅÍ: îäíîçíà÷íûå ÷èñëà" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "ÒÅÑÒ 4 ÍÅ ÏÐÎÉÄÅÍ: èñêëþ÷åíèå" << endl;
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
            cout << "ÒÅÑÒ 5 ÏÐÎÉÄÅÍ: ðàçâîðîò ñïèñêà" << endl;
            passed++;
        }
        else {
            cout << "ÒÅÑÒ 5 ÍÅ ÏÐÎÉÄÅÍ: ðàçâîðîò ñïèñêà" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "ÒÅÑÒ 5 ÍÅ ÏÐÎÉÄÅÍ: èñêëþ÷åíèå" << endl;
        total++;
    }

    try {
        LinkedList<string> list2;
        list2.append("hello");
        list2.append("world");
        list2.reverseIterative();
        auto result = list2.toVector();
        if (result.size() == 2 && result[0] == "world") {
            cout << "ÒÅÑÒ 6 ÏÐÎÉÄÅÍ: ñïèñîê ñòðîê" << endl;
            passed++;
        }
        else {
            cout << "ÒÅÑÒ 6 ÍÅ ÏÐÎÉÄÅÍ: ñïèñîê ñòðîê" << endl;
        }
        total++;
    }
    catch (...) {
        cout << "ÒÅÑÒ 6 ÍÅ ÏÐÎÉÄÅÍ: èñêëþ÷åíèå" << endl;
        total++;
    }

    try {
        FibonacciGenerator::generateFirstNFibonacci(10000);
        cout << "ÒÅÑÒ 7 ÍÅ ÏÐÎÉÄÅÍ: îáðàáîòêà áîëüøèõ ÷èñåë" << endl;
        total++;
    }
    catch (const invalid_argument&) {
        cout << "ÒÅÑÒ 7 ÏÐÎÉÄÅÍ: îáðàáîòêà áîëüøèõ ÷èñåë" << endl;
        passed++;
        total++;
    }
    catch (...) {
        cout << "ÒÅÑÒ 7 ÍÅ ÏÐÎÉÄÅÍ: íåâåðíîå èñêëþ÷åíèå" << endl;
        total++;
    }

    cout << "==========================================" << endl;
    cout << "ÐÅÇÓËÜÒÀÒ: " << passed << "/" << total << " òåñòîâ ïðîéäåíî" << endl;
    cout << "==========================================" << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");

    runTests();

    cout << "\nÍàæìèòå Enter äëÿ âûõîäà...";
    cin.get();
    return 0;
}