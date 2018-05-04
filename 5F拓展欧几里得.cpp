/*F: 欧几里得算法
在RSA密码体系中, 欧几里得算法是加密或解密运算的重要组成部分。它的基本运算过程就是解 x*a=1(mod n) 这种方程。整个解的过程是这样的，我们用一个例子来说明。
当a = 1001 ，n = 3837时
方程为 x * 1001 = 1 (mod 3837)
求解过程：
3837 = 3 * 1001 + 834
1001 = 1 * 834 + 167
834 = 4 * 167 + 166
167 = 166 + 1
所以
1 = 167 – 166
= 167 - (834 - 4 * 167)
= 5 * 167 – 834
= 5 *(1001 - 834) – 834
= 5 * 1001 - 6 *834
= 5 * 1001 - 6 * (3837 -3 *1001)
= 23 * 1001 - 6 *3837
然后对等式两端同时除以模3837得
23 * 1001 = 1 (mod 3837)
于是 x = 23
现在给出a和n，你能不能在最短的时间内解出这个方程呢？
 
输入
 
输入包括多组测试数据。每组测试数据对应输入的一行，每行包括两个整数a和n。1<a,n<2^31(用long可以存下)
当a=n=0时输入结束，这组数据不包括在需要计算的数据中。

输出

对应每组输入数据，输出最小的满足题意的解x。

样例输入
 
1001 3837
136468984 134548555
0 0
 
样例输出
 
23
112206854
 
提示
 
1. 本题用穷举是不可能做出来的
2. 结果必须是正数*/
#include<iostream>
using namespace std;

int extgcd(long a, long b,int &x, int &y)
{
    int d = a;
    if(b != 0)
	{
        d = extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else x=1,y=0;
    return d;
}

int main()
{
	
	long int a,n;
	
	while(1)
	{
	    cin>>a>>n;
		if(a==0&&n==0)
		  break;
		 int x1,y1;  
         extgcd(a,n,x1,y1);
         if(x1<0)
     	 	 x1=x1+n;
		  cout<<x1<<endl;
	}
return 0;
}













