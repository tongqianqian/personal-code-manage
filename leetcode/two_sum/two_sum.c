#include <stdio.h>
#include <stdlib.h>

int* two_sum(int* nums, int num_size, int target, int* return_size) {
    for (int i = 0; i < num_size; ++i) {
        for (int j = i + 1; j < num_size; ++j) {
            if (nums[i] + nums[j] == target) {
                int* res = (int*)malloc(2*sizeof(int));
                res[0] = i;
                res[1] = j;
                *return_size = 2;
                return res;
            }
        }
    }
    *return_size = 0;
    return NULL;
}

int main() {
    int nums[] = {1, 2, 9, 6, 12};
    int res_size = 0;
    int* res = two_sum(nums, 5, 13, &res_size);
    for (int i = 0; i < res_size; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}

