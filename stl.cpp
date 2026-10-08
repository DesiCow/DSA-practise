#include<bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1083
void findMissingNumber() {
    int numbers {};
    cin >> numbers;

    unordered_set<int> numberSet {};
    int number {};
    for (int i = 0; i < numbers - 1; i++) {
        cin >> number;
        numberSet.insert(number);
    }

    auto endPointer = numberSet.end();
    for (int i = 1; i <= numbers; i++) {
        if (numberSet.find(i) == endPointer) {
            cout << i << endl;
            break;
        }
    }
}

// Fails due to Integer overflow!
void findMissingNumberM2() {
    int numbers {};
    cin >> numbers;

    int realSum = numbers * (numbers + 1) / 2;
    int fakeSum {};
    int number {};
    for (int i = 0; i < numbers - 1; i++) {
        cin >> number;
        fakeSum += number;
    }
    cout << realSum - fakeSum << endl;
}


int main() {
    findMissingNumberM2();
    return 0;
}