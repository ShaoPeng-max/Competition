
#include<stdio.h>
int main()
{
    int a,b,c,t,n,k,q,w,e,i,f,x,y,g;
    for(i=123;i<=329;i++)  //枚举所有可能的解，最大不超过329
    {
		a=i*2;b=i*3;
    	t=i/100;n=i/10%10;k=i%10;
    	x=a/100;y=a/10%10;c=a%10;
    	q=b/100;w=b/10%10;e=b%10;//取出每个数的个位数，十位数和百位数
    	f=t+n+k+x+y+c+q+w+e;
    	g=t*n*k*x*y*c*q*w*e;
    	if(f==45&&g==362880) //若相加等于45，相乘等于362880，那么每个数恰好使用一次
    		printf("%d %d %d\n",i,i*2,i*3);
    }
    return 0;
}
