/*
 * Lesson 16: 字符串拷贝
 *
 * 知识点：指针，const, assert, while (*dest++ = *src++) 惯用法
 *
 * 任务：参考原课 mystrcpy.c，实现 mystrcpy 函数：
 *       1. char *mystrcpy(char *dest, const char *src)
 *       2. 逐字符复制直到 '\0' 也复制过去
 *       3. 返回 dest 起始地址
 *       4. main 中从 stdin 读入字符串，用 mystrcpy 复制后打印
 *
 * 验证：输入 "copy me" → "copy me\n"
 */

#include <assert.h>//assert用来警报与报错
#include <stdio.h>
//指针就是内存地址
// int *p：p 是指针变量，专门存 int 类型变量的地址
// p = &a：把 a 的门牌号放进 p 里面
// *p：解引用，拿着 p 里存的门牌号，去找到那个房间，读写里面的数据
char *mystrcpy(char *dest, const char *src) {//destination与source
    //char *使函数返回一个字符指针
    //const char *src：指向的内容不能改；指针 src 可以移动
    //char * const src：指针 src 本身不能移动；但是指向的字符可以修改
    //const char * const src：内容不能改，指针也不能动
    assert(dest != NULL && src != NULL);//两个指针地址有一个为空时报错
    //NULL = 空指针，指针变量的值等于 0，代表这个指针没有指向一块可用内存。
    char * ret = dest;//将目标地址头存入ret
    while ((*dest++ = *src++) != '\0');//";代表循环为空，只有括号内内容执行"
    //虽然有++，也不会漏第一个，因为是先赋值，后移动
    //并且由于++的运算优先于*，所以地址先加，内容再变
    return ret;
}

int main(void) {
    char s1[256] = "";
    char s2[256];
    fgets(s2, sizeof(s2), stdin);//输入s2
    //sizeof(s2)：缓冲区总字节数，限制最多读多少字符，防止溢出
    //stdin：标准输入，就是键盘
    int i = 0;
    while (s2[i] && s2[i] != '\n') i++;
    s2[i] = '\0';
    //这一步在将fgets中读取的用户输入的\n(回车)转换为\0
    mystrcpy(s1, s2);
    printf("%s\n", s1);
    return 0;
}
/*char s1[80], s2[80] ;
    int i ;
    gets(s1);
    for( i=0 ; s1[i]!='\0' ; i++ )
        s2[i] = s1[i] ;
    s2[i] = '\0';
    puts(s2);
    也可以这么写，这样不需要用到指针*/