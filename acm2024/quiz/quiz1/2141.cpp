#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int m;
    cin >> m;

    string* a = new string[m];

    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    sort(a, a + m);

    int ans = 1;

    for (int i = 1; i < m; i++) {
        if (a[i] != a[i - 1]) {
            ans++;
        }
    }

    cout << ans << endl;

    delete[] a;
    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node* next[26];
    bool isEnd;

    Node() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        isEnd = false;
    }
};

int main() {
    int m;
    cin >> m;

    Node* root = new Node();
    int ans = 0;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        Node* p = root;

        for (int j = 0; j < (int)s.size(); j++) {
            int c = s[j] - 'a';

            if (p->next[c] == nullptr) {
                p->next[c] = new Node();
            }

            p = p->next[c];
        }

        if (!p->isEnd) {
            p->isEnd = true;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}*/

/*
#include <iostream>
#include <string>
using namespace std;

string* s;
int* nxt;
int ans = 0;

void solve(int head, int k) {
    if (head == -1) return;

    int bucket[27];

    for (int i = 0; i < 27; i++) {
        bucket[i] = -1;
    }

    // 按照第 k 位字符分桶
    while (head != -1) {
        int i = head;
        head = nxt[head];

        int c;

        if (k == (int)s[i].size()) {
            c = 26;  // 字符串结束
        } else {
            c = s[i][k] - 'a';
        }

        nxt[i] = bucket[c];
        bucket[c] = i;
    }

    // 结束桶非空，代表一个不同的字符串
    if (bucket[26] != -1) {
        ans++;
    }

    // 对其余 26 个桶继续分组
    for (int i = 0; i < 26; i++) {
        if (bucket[i] != -1) {
            solve(bucket[i], k + 1);
        }
    }
}

int main() {
    int m;
    cin >> m;

    s = new string[m];
    nxt = new int[m];

    for (int i = 0; i < m; i++) {
        cin >> s[i];
        nxt[i] = i + 1;
    }

    nxt[m - 1] = -1;

    solve(0, 0);

    cout << ans << endl;

    delete[] s;
    delete[] nxt;

    return 0;
}
    */