#include <iostream>
#include <unordered_map>

int main() {
    int n, m;
    std::unordered_map<std::string, int> id;

    std::cin >> n;
    int num = n;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        id[s] = i;
    }

    std::cin >> m;
    int* source = new int[m];
    int* target = new int[n]();
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        std::string s;
        std::cin >> s;

        if (!id.count(s)) {
            id[s] = num;
            num++;
        }
        if (id[s] < n && target[id[s]] == 0) {
            target[id[s]] = 1;
            cnt++;
        }
        source[i] = id[s];
    }

    int* count = new int[n]();
    
    int left = 0, right = 0;
    int k = 0;
    int min = m;
    while (right < m) {
        if (source[right] < n) {
            if (count[source[right]] == 0)
                k++;
            count[source[right]]++;
        }
        right++;
        while (k == cnt) {
            if (count[source[left]] > 1) {
                count[source[left]]--;
                left++;
                if (right - left < min) {
                    min = right - left;
                }
            } else {
                break;
            }
        }
    }
    

    
    std::cout << cnt << std::endl;
    std::cout << min << std::endl;

    delete[] count;
    delete[] source;

}