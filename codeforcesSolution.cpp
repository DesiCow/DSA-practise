#include <iostream>
using namespace std;

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


int main() {
    int weight;
    cin >> weight;
    if (weight <= 2) {
        cout << "NO";
        return 0;
    }
    cout << (weight % 2 == 0 ? "YES" : "NO") << endl;
};


