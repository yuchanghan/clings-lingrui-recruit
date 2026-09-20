/*
 * Lesson 07a: 求 100 以内的最大素数
 *
 * 知识点：math.h, sqrt, 强制类型转换 (int), 三层逻辑嵌套
 *
 * 任务：参考原课 prime.c，完成素数判定：
 *       1. 外层 for num 从 1 到 100
 *       2. 计算 tmp = (int)sqrt((double)num)
 *       3. 内层 for i 从 2 到 tmp，判断 num % i == 0 则 break
 *       4. 如果 i == tmp + 1，说明 num 是素数，更新 max
 *       5. 最后打印 "max prime is %d\n"
 *
 * 课堂讨论：j == tmp + 1 能否改为 j == tmp? 为什么？
 *           如果没有数学库，这个程序如何编写效率才能最高？
 *
 * 验证：stdout 精确匹配 "max prime is 97\n"
 */

#include <math.h>//可以使用sqrt
#include <stdio.h>

int main(void) {
    int num;
    int i;
    int max = 0;
    int tmp;
    int n = 0;
    for (num = 2;num <= 100;num++) {
        tmp = (int)sqrt((double)num);//因为sqrt强制要求double,所以要转化
        for (int m = 2;m <= tmp;m++) {
            n = 0;
            if (num % m == 0) {
                 n=1;
                 break;
            }
        }
        if (n==0) {
            max = num;
        }
    }

    printf("max prime is %d\n", max);

    return 0;
}