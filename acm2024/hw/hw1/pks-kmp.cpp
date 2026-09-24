#include <iostream>
#include <cstring>

void build_next(std::string &s, int *next) {
    int n = s.length();
    int i = 1, k = 0;
    next[0] = 0;
    while (i < n) {
        if (s[i] == s[k]) {
            next[i] = k + 1;
            i++;
            k++;
        } else if (k == 0) {
            next[i] = 0;
            i++;
        } else {
            k = next[k - 1];
        }
    }
}

void printer(int k, int* next) {
    if (k > 1) {
        printer(next[k - 1], next);
        std::cout << k << '\n';
    }
    else if (k == 1)
        std::cout << k << '\n';
}

int main() {
    std::string s;
    std::cin >> s;
    int k = s.length();
    int* next = new int[k];
    build_next(s, next);
    printer(k, next);
    delete[] next;
}