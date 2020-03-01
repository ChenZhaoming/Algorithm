#include <iostream>

using namespace std;

const int MAX = 3;

int main()
{
    int var1 = 20;
    int var2[] = {10, 100, 200};
    char *var3[] = {"a", "b", "c"}; //指向字符的指针数组，可用于存储字符串列表（其他类型不可）

    int *p1;
    int *p21, *p22;
    int *p2[MAX]; //指针数组，即存储指针的数组
    int **p3; //指向指针的指针

    p1 = &var1; //指针指向变量的地址，通过&获取其地址
    p21 = var2; // 数组是一个指针常量，无需&获取其地址
    p22 = &var2[0]; //数组的地址为其第一个元素的地址
    p2[0] = &var2[0]; //指针数组和一般数组一样，只不过其元素为指针
    p3 = &p1;

    cout << &var1 << endl;
    cout << p1 << endl;
    cout << var1 << endl;
    cout << *p1 << endl;

    cout << p21 << endl; // 指向var2的地址
    cout << p22 << endl; // 指向var2的地址
    cout << p2[0] << endl; // 指向var2的地址
    cout << *p21 << endl; //*取地址指向的变量值
    cout << *(++p21) << endl; //先++，指向下一个地址，*取值

    cout << var3[0] << endl; //输出结果为a
    cout << var3 << endl; //输出结果为指针数组的地址

    cout << p3 << endl; //指向p1的地址
    cout << *p3 << endl; //其值为p1指向的地址，即var1的地址
    cout << **p3 << endl; //var1的值
//    char *p2 = new char('a');
//    cout << "p2=" << p2 << endl;
//    cout << "*p2=" << *p2 << endl;
//    cout << "&p2=" << &p2 << endl;
    return 0;
}
