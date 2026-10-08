#include <iostream>
#include <set>
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


int main() {
    int lines {};
    cin >> lines;
    int number {};
    for (int i = 0; i < lines; i++) {
        cin >> number;
        a1665(number);
    }
};


