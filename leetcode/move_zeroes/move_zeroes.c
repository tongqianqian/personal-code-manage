#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void move_zeroes(int* nums, int num_size) {
    int left = 0;
    int right = 0;
    while (right < num_size) {
        if (nums[right]) {
            swap(&nums[left], &nums[right]);
            left++;
        }
        right++;
    }
}

int main() {
    int nums[] = {1, 2, 0, 9, 0, 6, 12};
    move_zeroes(nums, 7);
    for (int i = 0; i < 7; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

