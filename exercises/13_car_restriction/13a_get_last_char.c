/*
 * Lesson 13a: 函数封装 — get_last_char
 *
 * 知识点：字符串遍历，函数设计，while 循环
 * 参考原课 restrict.c 中的 get_last_char() 函数
 *
 * 任务：实现 get_last_char(str) 函数：
 *       1. 定义 char c, int i = 0
 *       2. while (str[i]) { c = str[i]; i++; }
 *       3. return c — 返回字符串最后一个字符
 *
 * 验证：输入 "A23456" → "6\n"; 输入 "hello" → "o\n"
 */

#include <stdio.h>
//char c = 'A'; char c = 56; char str[] = abcde; (char存一个字符，加[]后可以存长串)
//此处方框内数字表示该变量内有几个字符，比如hello方框内是6（别忘了\0），方框内也可不打
//%c 用来打印单个字符 str[i]
//%s 打印整个字符串 str
//字符串末尾一定有 \0，str[i] == '\0' 代表字符串结束
char get_last_char(char str[]) {
    char c;
    int i = 0;
    while (str[i]) { c = str[i]; i++; }
    //str[i] == 0时停止，C 语言里：非 0 的值为真；0 为假
    return c;
}
int main(void) {
    char buf[64];
    scanf("%s", buf);
    printf("%c\n", get_last_char(buf));
    return 0;
}
