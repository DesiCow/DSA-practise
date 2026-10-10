#include <iostream>
#include <limits>
#include <unordered_set>
#include <vector>
using namespace std;

void a4() {
    int weight;
    cin >> weight;
    if (weight <= 2) {
        cout << "NO";
    }
    cout << (weight % 2 == 0 ? "YES" : "NO") << endl;
}

void a231() {
    int problems{ };
    cin >> problems;
    int solvableProblems{ };
    for (int i = 0; i < problems; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) solvableProblems++;
    }
    cout << solvableProblems << endl;
}

void a469() {
    int numberOfLevels {};
    cin >> numberOfLevels;

    unordered_set<int> levels {};

    int firstIteration {};
    cin >> firstIteration;
    for (int i = 0; i < firstIteration; i++) {
        int num {};
        cin >> num;
        levels.insert(num);
    }

    int secondIteration {};
    cin >> secondIteration;
    for (int i = 0; i < secondIteration; i++) {
        int num {};
        cin >> num;
        levels.insert(num);
    }

    if (levels.size() == numberOfLevels) cout << "I become the guy." << endl;
    else cout << "Oh, my keyboard!" << endl;
}

// https://codeforces.com/problemset/problem/181/A
// horrendous solution
void a181() {
    int n, m {};
    cin >> n >> m;

    vector<int>xCoords;
    vector<int>yCoords;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char slot {};
            cin >> slot;
            if (slot == '*') {
                xCoords.emplace_back(j);
                yCoords.emplace_back(i);
            }
        }
    }

    int xAns = xCoords[2];
    int yAns = yCoords[2];

    if (xCoords[0] != xCoords[1]) {
        xAns = xCoords[0] == xCoords[2] ? xCoords[1] : xCoords[0];
    }

    if (yCoords[0] != yCoords[1]) {
        yAns = yCoords[0] == yCoords[2] ? yCoords[1] : yCoords[0];
    }

    cout << yAns << " " << xAns << endl;
}

// https://codeforces.com/problemset/problem/1665/A
void a1665(int n) {
    cout << n - 3 << " " << 1 << " " << 1 << " " << 1 << "\n";
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

int findIndex(int x, int arraySize) {
    return x + 1 % arraySize;
}

int calcModulus(int a, int b) {
    return (a % b + b) % b;
}

void rotate(std::vector<int>& nums, int k) {
    std::vector<int> original(nums);

    int modulus = nums.size() - 1;
    std::cout << "the modulus is " << modulus << std::endl;
    for (int i = 0; i <= modulus; i++) {
        std::cout << i << " -> " << calcModulus(i+k, modulus + 1) << std::endl;
        nums[i] = original[calcModulus(i - k, modulus + 10  )];
    }
}

void usernameCheck() {
    std::string username {};
    std::getline(std::cin >> std::ws, username);

    std::unordered_set<char> characters {};
    for (int i = 0; i < username.length(); i++) {
        characters.insert(username[i]);
    }

    std::cout << ((characters.size() % 2 == 0) ? "CHAT WITH HER!" : "IGNORE HIM!") << std::endl;
}


int main() {
    int lines {};
    cin >> lines;
    int number {};
    for (int i = 0; i < lines; i++) {
        cin >> number;
        a1665(number);
    }
};


