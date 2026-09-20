/*
 * Lesson 11: 求两个坐标点之间的距离
 *
 * 知识点：struct, typedef, 函数参数传结构体，math.h sqrt
 *
 * 任务：参考原课 point.c，完成：
 *       1. 定义 struct point { float x; float y; } 和 typedef
 *       2. 实现 float calculate(point_t p1, point_t p2)
 *          - 计算 dx = p1.x - p2.x, dy = p1.y - p2.y
 *          - return sqrt(dx*dx + dy*dy)
 *       3. main 中 scanf 读入两点坐标，调用函数，打印结果
 *
 * 验证：输入 "0 0 3 4" → "5.00\n"; 输入 "1 1 4 5" → "5.00\n"
 */
#include <math.h>
#include <stdio.h>
struct point { float x; float y; };//此处用struct创造了一个叫point的打包结构来表示点，注意要加分号
typedef struct point point_t;//typedef 原类型名 新名字；进行改名
point_t p1, p2;//定义了两个结构体p1,p2
float calculate(point_t p1, point_t p2){
           float dx = p1.x - p2.x;//此处p1.x就指上文的x
           float dy = p1.y - p2.y;
            return sqrt(dx*dx + dy*dy);
    }
int main(void) {
    float distance;
    scanf("%f %f %f %f", &p1.x, &p1.y, &p2.x, &p2.y);
    distance = calculate(p1, p2);
    printf("%.2f\n", distance);
    return 0;
}
