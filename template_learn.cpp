<pre name="code" class="cpp">// TemplateTest.cpp : 定义控制台应用程序的入口点。  
///<summary>  
///测试C++中的template(模板)的使用方法 最新整理时间2016.5.21  
///</summary>  
///<remarks>1:template的使用是为了简化不同类型的函数和类的重复定义.  
///<remarks>2:char类型变量c,d输入的都是字母，不是数字，如输入32则c=3,d=2.  
#include "stdafx.h"  
#include <iostream>  
#include<vector>  
using namespace std;  
template <typename T>  
T mmax(T a,T b)  
{  
    return a>b?a:b;  
}  
int _tmain(int argc, _TCHAR* argv[])  
{  
    cout<<"Please enter the value of a and b:"<<endl;  
    int a,b;  
    cin>>a>>b;  
    cout<<mmax(a,b)<<endl;  
    cout<<"Please enter the value of c and d:"<<endl;  
    char c,d;  
    cin>>c>>d;  
    cout<<mmax(c,d)<<endl;  
    cout<<"Please enter the value of f and g:"<<endl;  
    double f,g;  
    cin>>f>>g;  
    cout<<mmax(f,g)<<endl;  
    while(1);  
    return 0;  
}  
