#include <iostream>
#include <string>
using namespace std;

void build_next(string &s, int *next) {
    next[0] = 0;
    int n = s.length();
    int i = 1, k = 0;
    while (i < n) {
        if (s[i] == s[k]) {
            next[i++] = ++k;
        } else if (k == 0) {
            next[i++] = 0;
        } else {
            k = next[k - 1];
        }
    }
}

/*
bool test(const string &s1, const string &s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    if (n2 % n1 != 0)
        return false;
    
    int k = n2 / n1;
    for (int i = 0; i < k; i++) {
        if (s2.substr(i * n1, n1) != s1)
            return false;
    }
    return true;
}
    */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, k;
    string S;

    cin >> N;
    cin >> S;
    cin >> k;

    int* next = new int[N];
    build_next(S, next);
    int c = N, len;
    
    while (k > 0) {
        c = next[c - 1];
        len = N - c;
        if (N % len == 0) {
            k--;
            if (k == 0)
                break;
        }
    }
    cout << S.substr(0, len) << endl;
    delete[] next;

    return 0;
}