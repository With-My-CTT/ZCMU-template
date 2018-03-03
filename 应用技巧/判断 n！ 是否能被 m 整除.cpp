/*  �ж� n�� �Ƿ��ܱ� m ���� 
n!�м�����˶��ٸ�x(x�������һ����������һ����������Ƕ�ֻ����xΪ����)��
��������Ĵ��ǣ�
n/x+n/(x^2)+n/(x^3).....[һֱ�ӵ�x�ĳ˷�������n]����������֤��Ҳ�ǳ��ļ򵥣�
����Ͳ���׸����
 
Ȼ����һ�����۵Ļ�����ʶ��������һ�������������ֽ�
����֪�����ַֽ���Ψһ��
������y=sigma[(pi)^ni]
����pi�ķ�Χ��2����sqrt(n)֮��;
���Ǻ������ǿ����ȷֽ��m����������˶���ʱ�䣬���������ɸѡ�����ٵĻ���\
*/
#include<stdio.h>  
#include<string.h>  
struct node {  
    long p;  
    long n;  
    node()  
    {  n=0; }  
};  
long prime[50000];  
bool flag[50000];  
node stc[1000];  
long num1=0,num2;  
void init()  
{  
    unsigned long i,j;  
    memset(flag,0,sizeof(flag));  
    for(i=2;i<50000;i++)  
    {  
        if(!flag[i])  
        {  
            prime[num1++]=i;  
            for(j=i*i;j<50000;j=j+i)  
                flag[j]=true;  
        }  
    }  
}  
void devide(long m)  
{  
    long i;  
    num2=0;  
    for(i=0;prime[i]*prime[i]<=m;i++)  
    {  
        if(m%prime[i]==0)  
        {  
            stc[num2].p=prime[i];  
            stc[num2].n++;  
            m=m/prime[i];  
            while(m%prime[i]==0)  
            {  
                stc[num2].n++;  
                m=m/prime[i];  
            }  
            num2++;  
        }  
        if(m==1)  
            break;  
    }  
    if(m>1)  
    {  
        stc[num2].p=m;  
        stc[num2].n++;  
        num2++;  
    }  
}  
bool judge(long n,long m)  
{  
    long i,sum,temp;  
    for(i=num2-1;i>=0;i--)  
    {  
        sum=0;  
        temp=stc[i].p;  
        while(n>=temp)  
        {  
            sum=sum+n/temp;  
            temp=temp*stc[i].p;  
        }  
        if(sum<stc[i].n)  
            return false;  
    }  
    return true;  
}  
int main()  
{  
    long n,m,i;  
    init();  
    while(scanf("%ld%ld",&n,&m)!=EOF)  
    {  
        for(i=0;i<1000;i++)  
            stc[i].n=0;  
        if(n<=1&&m>1)  
        {  
            printf("%ld does not divide %ld!/n",m,n);  
            continue;  
        }  
        if(m==0)  
        {  
            printf("%ld does not divide %ld!/n",m,n);  
            continue;  
        }  
        if(n>=m)  
        {  
            printf("%ld divides %ld!/n",m,n);  
            continue;  
        }  
        devide(m);  
        if(judge(n,m))  
            printf("%ld divides %ld!/n",m,n);  
        else  
            printf("%ld does not divide %ld!/n",m,n);  
    }  
    return 0;  
}  
