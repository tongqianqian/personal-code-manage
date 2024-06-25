#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a >= b? a : b;
}

int min(int a, int b) {
    return a <= b? a : b;
}

int max_area(int* nums, int num_size) {
    int left = 0;
    int right = num_size - 1;
    int area = 0;
    while (left < right) {
        int cur_area = min(nums[left], nums[right]) * (right - left);
        area = max(area, cur_area);
        nums[left] <= nums[right]? left++ : right--;
    }

    return area;
}

int main() {
    int nums[] = {1, 2, 6, 9, 7, 6, 12};
    int area = max_area(nums, 7);
    
    printf("max_area: %d\n", area);
    return 0;
}

