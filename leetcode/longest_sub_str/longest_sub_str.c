#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a >= b? a : b;
}

int min(int a, int b) {
    return a <= b? a : b;
}

int lengthOfLongestSubstring(char* str) {
    int hash[128] = {0};
    int left = 0;
    int right = -1;
    int max_len = 0;
    int str_len = strlen(str);


    for (; left < str_len; left++) {
        if (left) {
            hash[str[left - 1]] = 0;
        }

        while (right + 1 < str_len && !hash[str[right + 1]]) {
            hash[str[right + 1]] = 1;
            right++;
        }

        max_len = max(max_len, right - left + 1);
    }

    return max_len;
}

int main() {
    char* str = "abgcidddc";
    int len = lengthOfLongestSubstring(str);
    
    printf("len: %d\n", len);
    return 0;
}

