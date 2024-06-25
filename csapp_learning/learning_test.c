#include <stdio.h>
#include <sys/time.h>  
#include <unistd.h>

// 栈空间只有8M，一个线程最多占用8M栈空间，1024就会失败
#define ARRAY_LEN 1000

// 测试数组越界
#define TEST_STRUCT 0

// 测试不同复制的效率
#define TEST_I_J_COPY 1

// 测试大小端
#define TEST_ADDR 1

#if TEST_STRUCT
struct test_struct {
    int a[2];
    double d;
};

double test_func_00(int i) {
    struct test_struct s = {0};
    s.d = 3.14;
    s.a[i] = 1073741284;

    return s.d;
}
#endif

#if TEST_ADDR
typedef unsigned char * pointer;

void show_bytes(pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; ++i) {
        printf("%p\t0x%.2x\n", start + i, start[i]);
    }
    printf("\n");
}

#endif

int main() {
#if TEST_STRUCT
    double res = 0;
    for (int i = 0; i < 7; i++) {
        res = test_func_00(i);
        printf("test_func(%d) ---> %lf \n", i, res);
    }
#endif

#if TEST_I_J_COPY
    int src[ARRAY_LEN][ARRAY_LEN];
    int dst[ARRAY_LEN][ARRAY_LEN];

    struct timeval start, end;  
    long long diff_milliseconds;  
  
    // 获取开始时间  
    if (gettimeofday(&start, NULL) != 0) {  
        perror("gettimeofday");  
        return 1;  
    }

    for (int i = 0; i < ARRAY_LEN; ++i) {
        for (int j = 0; j < ARRAY_LEN; ++j) {
            dst[i][j] = src[i][j];
        }
    }

    // 获取结束时间  
    if (gettimeofday(&end, NULL) != 0) {  
        perror("gettimeofday");  
        return 1;  
    }  
  
    // 计算时间差（毫秒）  
    diff_milliseconds = (end.tv_sec - start.tv_sec) * 1000LL + (end.tv_usec - start.tv_usec) / 1000;  
  
    // 打印结果  
    printf("Time difference in milliseconds i_j: %lld\n", diff_milliseconds);

    // 获取开始时间  
    if (gettimeofday(&start, NULL) != 0) {  
        perror("gettimeofday");  
        return 1;  
    }

    for (int i = 0; i < ARRAY_LEN; ++i) {
        for (int j = 0; j < ARRAY_LEN; ++j) {
            dst[j][i] = src[j][i];
        }
    }

    // 获取结束时间  
    if (gettimeofday(&end, NULL) != 0) {  
        perror("gettimeofday");  
        return 1;  
    }  
  
    // 计算时间差（毫秒）  
    diff_milliseconds = (end.tv_sec - start.tv_sec) * 1000LL + (end.tv_usec - start.tv_usec) / 1000;  
  
    // 打印结果  
    printf("Time difference in milliseconds j_i: %lld\n", diff_milliseconds);

#endif

#if TEST_ADDR
    int a = 15213;
    printf("int a = 15213;\n");
    show_bytes((pointer) &a, sizeof(int));

#endif

}


