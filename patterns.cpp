#include <iostream>

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

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.

    pattern12(6);

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}