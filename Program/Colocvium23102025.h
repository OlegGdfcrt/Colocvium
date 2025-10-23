#pragma once

#include <vector>
#include <memory>
#include <stdexcept>
#include <limits>
#include <string>

using namespace std;

namespace Colocvium23102025 {

    class FibonacciGenerator {
    public:
        static vector<unsigned long long> generateFirstNFibonacci(size_t n) {
            if (n == 0) {
                return {};
            }

            validateInput(n);

            vector<unsigned long long> result;
            result.reserve(n);

            if (n >= 1) {
                result.push_back(0);
            }
            if (n >= 2) {
                result.push_back(1);
            }

            for (size_t i = 2; i < n; ++i) {
                if (willAdditionOverflow(result[i - 1], result[i - 2])) {
                    throw overflow_error("Fibonacci number overflow detected at position " + to_string(i));
                }

                unsigned long long next = result[i - 1] + result[i - 2];
                result.push_back(next);
            }

            return result;
        }

    private:
        static void validateInput(size_t n) {
            constexpr size_t MAX_SAFE_N = 1000;

            if (n > MAX_SAFE_N) {
                throw invalid_argument("Input too large: n = " + to_string(n) +
                    ", maximum allowed is " + to_string(MAX_SAFE_N));
            }
        }

        static bool willAdditionOverflow(unsigned long long a, unsigned long long b) {
            return a > numeric_limits<unsigned long long>::max() - b;
        }
    };

    class PalindromeChecker {
    public:
        static bool isPalindrome(long long number) {
            if (number < 0) {
                return false;
            }
            if (number < 10) {
                return true;
            }

            return number == reverseNumber(number);
        }

    private:
        static long long reverseNumber(long long number) {
            long long reversed = 0;
            long long temp = number;

            while (temp > 0) {
                int digit = temp % 10;

                if (willMultiplicationOverflow(reversed, 10) ||
                    willAdditionOverflow(reversed * 10, digit)) {
                    throw overflow_error("Number reversal would cause overflow for input: " +
                        to_string(number));
                }

                reversed = reversed * 10 + digit;
                temp /= 10;
            }

            return reversed;
        }

        static bool willMultiplicationOverflow(long long a, long long b) {
            if (a > 0 && b > 0) {
                return a > numeric_limits<long long>::max() / b;
            }
            if (a < 0 && b < 0) {
                return a < numeric_limits<long long>::max() / b;
            }
            if (a > 0 && b < 0) {
                return b < numeric_limits<long long>::min() / a;
            }
            if (a < 0 && b > 0) {
                return a < numeric_limits<long long>::min() / b;
            }
            return false;
        }

        static bool willAdditionOverflow(long long a, long long b) {
            if (b > 0) {
                return a > numeric_limits<long long>::max() - b;
            }
            else {
                return a < numeric_limits<long long>::min() - b;
            }
        }
    };

    template<typename T>
    struct ListNode {
        T data;
        shared_ptr<ListNode<T>> next;

        explicit ListNode(const T& value) : data(value), next(nullptr) {}
        explicit ListNode(T&& value) : data(move(value)), next(nullptr) {}
    };

    template<typename T>
    class LinkedList {
    public:
        LinkedList() : head_(nullptr), size_(0) {}

        ~LinkedList() = default;

        LinkedList(const LinkedList&) = delete;
        LinkedList& operator=(const LinkedList&) = delete;

        LinkedList(LinkedList&& other) noexcept : head_(move(other.head_)), size_(other.size_) {
            other.size_ = 0;
        }

        LinkedList& operator=(LinkedList&& other) noexcept {
            if (this != &other) {
                head_ = move(other.head_);
                size_ = other.size_;
                other.size_ = 0;
            }
            return *this;
        }

        void append(const T& value) {
            auto new_node = make_shared<ListNode<T>>(value);

            if (!head_) {
                head_ = new_node;
            }
            else {
                auto current = head_;
                while (current->next) {
                    current = current->next;
                }
                current->next = new_node;
            }
            ++size_;
        }

        void append(T&& value) {
            auto new_node = make_shared<ListNode<T>>(move(value));

            if (!head_) {
                head_ = new_node;
            }
            else {
                auto current = head_;
                while (current->next) {
                    current = current->next;
                }
                current->next = new_node;
            }
            ++size_;
        }

        void reverseIterative() {
            if (!head_ || !head_->next) {
                return;
            }

            shared_ptr<ListNode<T>> prev = nullptr;
            shared_ptr<ListNode<T>> current = head_;
            shared_ptr<ListNode<T>> next = nullptr;

            while (current) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head_ = prev;
        }

        vector<T> toVector() const {
            vector<T> result;
            result.reserve(size_);

            auto current = head_;
            while (current) {
                result.push_back(current->data);
                current = current->next;
            }

            return result;
        }

        size_t size() const { return size_; }
        bool empty() const { return size_ == 0; }
        shared_ptr<ListNode<T>> getHead() const { return head_; }

        void clear() {
            head_ = nullptr;
            size_ = 0;
        }

    private:
        shared_ptr<ListNode<T>> head_;
        size_t size_;
    };

}