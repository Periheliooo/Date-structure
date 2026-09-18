#include <cstdio>
#include <cstring>

void get_next(const char *target, int* next) {
    int i = 1, k = 0, len_t = strlen(target);
    next[0] = 0;
    while (i < len_t) {
        if (target[i] == target[k]) {
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

int KMP(const char *source, const char *target) {
    int len_s = strlen(source), len_t = strlen(target);
    if (len_t == 0) return 0;
    int* next = new int[len_t];
    get_next(target, next);

    int i = 0, j = 0;
    while (i < len_s) {
        if (source[i] == target[j]) {
            i++;
            j++;
            if (j == len_t) {
                delete[] next;
                return i - j;
            }
        } else if (j == 0) {
            i++;
        } else {
            j = next[j - 1];
        }
    }
    delete[] next;    // Attention!
    return -1;
}

int main() {
    return 0;
}