/*	�ݳ�ԭ�� 
	����������ȥ���ظ��Ĺ������� 
*/

/* 
	����һ���� [a , b] ��Χ�� ����� n ���ʵ����ĸ��� 
	*����д�� * 
	˼·��1���� n �ֽ�������
		  2�����ݳ�ԭ��ȥ���ظ��������� 
*/
#include <stdio.h>
#include <stdlib.h>
long long  a[1000],num;//a������
void init(long long n)//��һ�����������ӣ��涨��ס��
{
    long long i;
    num=0;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            a[num++]=i;
            while(n%i==0)
                n=n/i;
        }
    }
    if(n>1)
        a[num++]=n;
}
long long haha(long long m)//�ö�������ʵ���ݳ�ԭ��ģ��
{
    long long que[10000],i,j,k,t=0,sum=0;
    que[t++]=-1;
    //ѭ����ˣ��ݳ⣬��ȥ����ģ�����ӣ���-1�Ӽ���k=t���ж���˭��
    for(i=0;i<num;i++)
    {
        k=t;
        for(j=0;j<k;j++)
           que[t++]=que[j]*a[i]*(-1);
    }
    for(i=1;i<t;i++) sum=sum+m/que[i];
    return sum;
}
int main()
{
    long long x,y,n,sum;
    while(scanf("%lld%lld%lld",&x,&y,&n)!=EOF)
    {
       init(n);
       sum=y-haha(y)-(x-1-haha(x-1));
	   //���е�ĸ���y��ȥ1~y����n���ʵĸ�����         
	   //�ټ���1~x�ﲻ��n���ʵĸ������ټ�ȥ1~x���е����
       printf("%lld\n",sum);
    }
    return 0;
}


/*	�������DFSд��
	�ʣ�����m���������� 1 ~ n-1 �����ж��ٸ���
		�ܱ���m����������һ���������� 
*/
#include<stdio.h>  
#include<string.h>  
int a[20], N, M, la ;  
int hash[20];  
__int64 gcd(__int64 a, __int64 b)  
{  
    __int64 c ;  
    while(b)  
     {  
         c = a % b ;  
         a = b ;  
         b = c ;  
     }  
    return a ;  
}  

void dfs(int now, int count, __int64 lcm, __int64 &sum)  
{  //    ��ǰ�� �Ѿ������ݳ�ĸ�������¼�ݳ�Ĺ���ֵ   ���  
    lcm = a[now] / gcd(lcm, a[now]) * lcm ;  
    if(count & 1)  
         sum += (N - 1) / lcm ;  
    else sum -= (N - 1) / lcm ;  
    for(int i = now + 1; i < M; i++)  
         dfs(i, count + 1, lcm, sum);  
}  
int main()  
{  
    int b,i ;  
    while(scanf("%d%d", &N, &M) != EOF)  
     {  
        for(i = 0, la = 0; i < M; i++)  
        {  
            scanf("%d", &b);  
            if(b) a[la++] = b ;  
        }  
        M = la ;  
        __int64 sum = 0 ;  
        //memset(hash,0,sizeof(hash));  
        for(i = 0; i < M; i++) //ö�����  
             dfs(i, 1, a[i], sum);  
         printf("%I64d\n", sum);  
     }  
    return 0 ;  
}   
