#include <iostream>

using namespace std;

const int MAX = 3;

int main()
{
    int var1 = 20;
    int var2[] = {10, 100, 200};
    char *var3[] = {"a", "b", "c"}; //ָ���ַ���ָ�����飬�����ڴ洢�ַ����б��������Ͳ��ɣ�

    int *p1;
    int *p21, *p22;
    int *p2[MAX]; //ָ�����飬���洢ָ�������
    int **p3; //ָ��ָ���ָ��

    p1 = &var1; //ָ��ָ������ĵ�ַ��ͨ��&��ȡ���ַ
    p21 = var2; // ������һ��ָ�볣��������&��ȡ���ַ
    p22 = &var2[0]; //����ĵ�ַΪ���һ��Ԫ�صĵ�ַ
    p2[0] = &var2[0]; //ָ�������һ������һ����ֻ������Ԫ��Ϊָ��
    p3 = &p1;

    cout << &var1 << endl;
    cout << p1 << endl;
    cout << var1 << endl;
    cout << *p1 << endl;

    cout << p21 << endl; // ָ��var2�ĵ�ַ
    cout << p22 << endl; // ָ��var2�ĵ�ַ
    cout << p2[0] << endl; // ָ��var2�ĵ�ַ
    cout << *p21 << endl; //*ȡ��ַָ��ı���ֵ
    cout << *(++p21) << endl; //��++��ָ����һ����ַ��*ȡֵ

    cout << var3[0] << endl; //������Ϊa
    cout << var3 << endl; //������Ϊָ������ĵ�ַ

    cout << p3 << endl; //ָ��p1�ĵ�ַ
    cout << *p3 << endl; //��ֵΪp1ָ��ĵ�ַ����var1�ĵ�ַ
    cout << **p3 << endl; //var1��ֵ
//    char *p2 = new char('a');
//    cout << "p2=" << p2 << endl;
//    cout << "*p2=" << *p2 << endl;
//    cout << "&p2=" << &p2 << endl;
    return 0;
}
