#include <cstdio>

void get_next(const char *target, int* next) {
    int i = 1, k = 0, len_t;
    next[0] = 0;
    while (i < len_t) {
        if (target[i] == target[k]) {
            next[i] = k + 1;
            i++;
            k++;
        } else if (k == 0) {
            next[i] = 0;
        } else {
            k = next[k - 1];
        }
    }
}

int KMP(const char *source, const char *target) {
    int len_s, len_t;
    int* next = new int[len_t];
    get_next(target, next);

    int i = 0, j = 0;
    while (i < len_s) {
        int k = i;
        if (target[k] == source[i]) {
            k++;
        }
        i++;
    }
    return -1;
}

int main() {

}