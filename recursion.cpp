#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

// Print numbers from the parameter n to 1 by usiing the concept of backtracking, i.e. the print line should come after
// the function call
void backtrackingPractise(int i, int n){
    if (i > n) return ;

    backtrackingPractise(i + 1, n);
    cout << i << endl;
}

int factorial(int n) {
    if (n <= 1) return 1;

    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long double realPow(long double x, long long n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    long double half = realPow(x, n / 2);
    long double otherHalf{half};

    if (n % 2 != 0) {
        otherHalf *= x;
    }
    return half * otherHalf;
}

long double myPow(double x, int n) {
    if (x == 1 || x == 0) return x;

    long long newN = n;
    long double newX = x;
    if (newN < 0) {
        newX = 1/newX;
        newN = -newN;
    }

    return realPow(newX, newN);
}

void reverseString(vector<char>& s) {
        for (int i = 0; i < (s.size() - 1) / 2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
        }
}

int main() {
    cout << setprecision(6);
    cout << myPow(2, 3) << endl;
}