#include <stdio.h>


// 栈空间，数组越界导致死循环
int main() {
    int i = 0;
    int arr[10] = {0};
    
    for (i = 0; i <= 11; i++) {
        printf("i = %d\n", i);
        arr[i] = 0;
    }
}