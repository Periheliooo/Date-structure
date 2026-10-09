#include <iostream>
#include <cstring>
using namespace std;

void build_next(string &s, int *next) {
    int n = s.length();
    int i = 1, k = 0;
    next[0] = 0;
    while (i < n) {
        if (s[k] == '?' || s[i] == s[k]) {
            next[i++] = ++k;
        } else if (k == 0) {
            next[i++] = 0;
        } else {
            k = next[k - 1];
        }
    }
}

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int n = s.length(), m = t.length();
    int* next = new int[n];
    build_next(s, next);

    int i = 0, j = 0;
    while (i < n) {
        if (s[i] == '?' || t[j] == '?' || s[i] == t[j]) {
            i++;
            j++;
            if (j == m) {
                cout << i - m << endl;
                j = 0;
            }
        } else if (j == 0) {
            i++;
        } else {
            j = next[j - 1];
        }
    }
}