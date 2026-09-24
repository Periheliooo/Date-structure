#include <iostream>
#include <cstring>

void build_next(std::string &T, int* next) {
    int i = 1, k = 0;
    next[0] = 0;
    while (i < (int)T.length()) {
        if (T[i] == T[k]) {
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

int main() {
    std::string S, T;
    std::cin >> S;
    std::cin >> T;
    int* next = new int[(int)T.length()];
    build_next(T, next);
    int i = 0, j = 0;
    while (i < (int)S.length()) {
        if (S[i] == T[j]) {
            i++;
            j++;
            if (j == (int)(T.length())) {
                std::cout << i - j + 1 << '\n';
                j = next[j - 1];
            }
        } else if (j == 0) {
            i++;
        } else {
            j = next[j - 1];
        }
    }
    for (i = 0; i < (int)T.length(); i++) {
        std::cout << next[i] << ' ';
    }
    delete[] next;
}