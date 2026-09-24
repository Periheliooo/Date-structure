#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string S;
    cin >> S;
    string rev = S;
    reverse(rev.begin(), rev.end());
    string t = rev + "#" + S;

    int n = t.length();
    int* next = new int[n];
    next[0] = 0;
    int i = 1;
    int k = 0;
    while (i < n) {
        if (t[i] == t[k]) {
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
    cout << S.length() - next[n - 1] << endl;
    delete[] next;
}