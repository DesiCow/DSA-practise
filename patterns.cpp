#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.


void pattern2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void pattern3(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << i;
        }
        std::cout << std::endl;
    }
}

void pattern5(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void pattern6(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << j;
        }
        std::cout << std::endl;
    }
}

// number of stars in a row = 2n-1
//
void pattern7(int n) {
    for (int i = 1; i <= n; i++) {
        std::cout << std::string(n - i, ' ') << std::string((2 * i) -1, '*');
        std::cout << std::endl;
    }
}

void pattern8(int n) {
    for (int i = n; i >= 1; i--) {
        std::cout << std::string(n - i, ' ') << std::string((2 * i) -1, '*');
        std::cout << std::endl;
    }
}

// sneaky ahh
void pattern9(int n) {
    pattern7(n);
    pattern8(n);
}

// tried a while loop as another approach, honestly it looks uglier than last approach
void pattern9M2(int n) {
    int i {1};
    while (i <= 2*n) {
        if (i <= n) {
            std::cout << std::string(n - i, ' ') << std::string((2 * i) -1, '*');
            std::cout << std::endl;
        }
        else {
            std::cout << std::string(i - n, ' ') << std::string((2 * (2*n-i)) -1, '*');
            std::cout << std::endl;
        }
        i++;
    }
}

void pattern10(int n) {
    int rows = 2 * n - 1;
    for (int i = 1; i <= rows; i++) {
        std::cout << std::string(i < n ? i : (rows - i + 1), '*');
        std::cout << std::endl;
    }
}

void pattern11(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j >= 1; j--) {
            std::cout << (j % 2 == 0 ? 0 : 1) << " ";
        }
        std::cout << std::endl;
    }
}

// not working rn!
void pattern12(int n) {
    int columns = 2 * n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= columns; j++) {
            int distance = std::min(j, columns - j);
            if (distance <= i) {
                std::cout << distance;
            }
            else std::cout << " ";
        }
        std::cout << std::endl;
    }
}

// https://leetcode.com/problems/reverse-integer/description/
int reverseInteger(int x) {
    int ans {};
    int maxAcceptable = std::numeric_limits<int>::max() / 10;
    int minAcceptable = std::numeric_limits<int>::min() / 10;

    while (x != 0) {
        int lastDigit = x % 10;

        if (ans >= 0 && ans <= maxAcceptable ||
            ans < 0 && ans >= minAcceptable) {
            ans = ans * 10 + lastDigit;
        }
        else {
            ans = 0;
            break;
        }
        x = x / 10;
    }

    return ans;
}

// https://leetcode.com/problems/palindrome-number/description/
bool palindrome(int x) {
    if (x < 0 || x % 10 == 0) return false;
    return reverseInteger(x) == x;
}

bool isPrime(int x) {
    if (x <= 1) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;
}

// https://codeforces.com/problemset/problem/80/A
bool isNextPrime(int smaller, int larger) {
    if (larger < smaller || larger <= 0) return false;
    if (!isPrime(smaller) || !isPrime(larger)) return false;

    for (int i = smaller + 1; i < larger; i++) {
        if (isPrime(i)) return false;
    }

    return true;
}

void solveCfNextPrime() {
    int n, m;
    std::cin >> n >> m;

    std::cout << (isNextPrime(n, m) ? "YES" : "NO") << std::endl;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Reattempt, without using STL functions and optimize it properly
int removeDuplicates(std::vector<int>& nums) {
    int pointer {INT_MIN};
    int unique {};

    for (int &k : nums) {
        if (k != pointer) {
            pointer = k;
            unique++;
        } else {
            k = {INT_MAX};
        }
    }

    std::erase_if(nums, [](int n) {
        return n == INT_MAX;
    });

    return unique;
}

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.


    std::vector<int> input {1, 2, 2};
    std::cout << "The uncleaned vector has: " << input.size() << " elements." << std::endl;
    std::cout << "The cleaned vector has: " << removeDuplicates(input) << " elements." << std::endl;
    std::cout << "The cleaned nums array is: " << std::endl;

    for (auto i : input) {
        std::cout << i << " ";
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}