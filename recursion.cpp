#include <iostream>
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

int main() {
    cout << factorial(6);
}