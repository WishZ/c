#include<cstdio>

int main() {
//需要一个把英寸单位转换为厘米单位（1 英寸=2.54 厘米）的程序。该程序要提示用户输入英寸值
    double inch;

    printf("单位换算：英寸转厘米，请输入英寸值\n");

    scanf("%lf", &inch);

    printf("%f 英寸等于 %lf 厘米!\n",inch, inch * 2.54);

    return 0;

}