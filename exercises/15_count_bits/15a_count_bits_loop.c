/*
 * Lesson 15a: 逐位检测 — 统计 bit 1 个数
 *
 * 知识点：位运算 &, 位移 <<, 掩码 1<<i, for 循环
 * 参考原课 bits.c 方法一
 *
 * 任务：实现 count_bits(num) 用逐位检测：
 *       for (i = 0; i < 32; i++)
 *           if (num & (1 << i)) sum++;
 *
 * 验证：输入 15 → "4\n"; 输入 1024 → "1\n"
 */

#include <stdio.h>
// << n 指将数后加n个0（*2的n次方）
// a & b 是将a与b加到一起（每一位分别相加，1+1=1，0+0与0+1都是0）
// a | b 也是将a与b加到一起（但0+0=0，1+1与0+1都是1）
// 用x & (1 << i) 是否为0来检验第i位是否是1
//_seed 是 unsigned int（一般 32 位，[高16位][低16位]）
int count_bits(int num) {
    int sum = 0;
    int i;
    for (i = 0; i < 32; i++){//此处不能写i <= 32,因为第1位i=0
        if(( num & (1 << i)) != 0){
            sum++;
        }
    }
    return sum;
}

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d\n", count_bits(num));
    return 0;
}
