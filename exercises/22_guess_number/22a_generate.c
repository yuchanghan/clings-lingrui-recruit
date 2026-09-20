/*
 * Lesson 22a: 生成不重复的 4 位随机数
 *
 * 知识点：伪随机数，do-while, used[] 数组标记
 * 参考原课 guess.c 中的 generate_secret() 函数
 *
 * 任务：实现 generate_secret(secret[4]):
 *       1. 用 used[10] = {0} 标记已使用的数字
 *       2. do { d = my_rand() % 10; } while (used[d]) 生成不重复数字
 *       3. secret[i] = d; used[d] = 1;
 *
 * 验证：my_rand() 固定种子 (LCG)，输出 4 个不重复数字
 */

#include <stdio.h>
/* 平台无关的伪随机数生成器 (Linear Congruential Generator) */
static unsigned int _seed = 42;
int my_rand(void) {
    _seed = _seed * 1103515245 + 12345;
    return (_seed >> 16) & 0x7fff;
}//用于生成随机数
void generate_secret(int secret[4]) {//void函数没有返回值
    int used[10] = {0}; // 定义used数组，数字全部初始化为0
    int i = 0;
    while(i < 4){
        int num = my_rand() % 10;
        if(used[num] == 0) {
            secret[i] = num;
            used[num] = 1; 
            i++;
        }//用于判断数字是否被使用
    }
}
int main(void) {
    int secret[4];
    int i;
    generate_secret(secret);
    for (i = 0; i < 4; i++) printf("%d", secret[i]);
    printf("\n");
    return 0;
}
