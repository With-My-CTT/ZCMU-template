/*�������Ķ��壺�����κ�������n����Լ��������Ϊf(n)������f(6)=4�����ĳ��������n���㣺�����������
            �������У���ô��Ϊ��������
 
�ӷ������Ķ����п��Կ����������ʣ�
��1��һ�������������������ӱ�Ȼ�Ǵ�2��ʼ���������ɸ���������Ϊ�������Ǳ�֤Լ������Ϊ�����������С
��2��ͬ���ĵ����������ô����
��ACM�����У�������������£�
��1������һ��������һ����С����������ʹ�õ�Լ������Ϊ
��2�������Լ���������������
������������п��Կ���������Ҫ����С�ģ�����Լ������Ϊ����ô���������������⡣
��ǰ������һ��������������Ҳ�������������磬��ÿһ��Ϊ����һ�㽨�������������Ϊ
��Ϊ������˵�����������£�
���Կ����Ӹ��ڵ㵽ÿһ��Ҷ�ӽ������·���ϵ��������ֳ���������12��Լ��������12��6��Լ����
������˼·�������ˣ��Ӹ��ڵ㿪ʼ�������ѣ���Ҷ�ӽ�㣬�������£�*/

void dfs(int dept,LL ans = 1)  
{  
    if(dept == cnt)  
    {  
        fac[ct++] = ans;  
        return;  
    }  
    for(int i=0;i<=num[dept];i++)  
    {  
        dfs(dept+1,ans);  
        ans *= pri[dept];  
    }  
}  

/*�ص����ǵ����⣬ͬ��������������С�ġ�
��Ŀ��http://codeforces.com/problemset/problem/27/E
���⣺	��һ����N����һ����С����������ʹ���������Ӹ���ΪN��
		N<=1000
������	�������ӵķ������ƣ��Ƚ�������������ÿһ��Ϊһ�㽨�����ͽṹ��
        ����������ȡ��С�ġ� */
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
typedef unsigned long long ULL;  
const ULL INF = ~0ULL;  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
int n;  
ULL ans;  
void dfs(int dept,ULL tmp,int num)  
{  
    if(num > n) return;  
    if(num == n && ans > tmp) ans = tmp;  
    for(int i=1;i<=63;i++)  
    {  
        if(ans / p[dept] < tmp) break;  
        dfs(dept+1,tmp *= p[dept],num*(i+1));  
    }  
}  
int main()  
{  
    while(cin>>n)  
    {  
        ans = INF;  
        dfs(0,1,1);  
        cout<<ans<<endl;  
    }  
    return 0;  
}  

/*��Ŀ��http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1562
���⣺�ҳ�С��n����������������N<2^63
˼·��һ���� A ���Էֽ�� p1^k1 * p2^k2 * ���� * pn^kn ����pΪ������
    �����ֽ�֮��A�����Ӹ���S = ��k1+1�� *�� k2+1�� * ���� *�� kn+1��
    Ȼ����dfsö�� + ��֦���Եõ�s��ֵ��������ö������С��n��A��sֵ�����õ����ֵ��
���룺*/
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
typedef unsigned long long ULL;  
const ULL INF = ~0ULL;  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
ULL ans,n;  
int best;  
void dfs(int dept,ULL tmp,int num)  
{  
    //��Ҷ�ӽ�㣬����  
    if(dept >= 16) return;  
    //num��¼�����Ӹ��������������С�ģ��͸���  
    if(num > best)  
    {  
        best = num;  
        ans = tmp;  
    }  
    //�����Ӹ�����ͬʱ��ȡֵ��С��  
    if(num == best && ans > tmp) ans = tmp;  
    for(int i=1;i<=63;i++)  
    {  
        if(n / p[dept] < tmp) break;  
        dfs(dept+1,tmp *= p[dept],num*(i+1));  
    }  
}  
int main()  
{  
    while(cin>>n)  
    {  
        ans = INF;  
        best = 0;  
        dfs(0,1,1);  
        cout<<ans<<endl;  
    }  
    return 0;  
}  

/*��Ŀ��http://acm.timus.ru/problem.aspx?space=1&num=1748
 
�������������Ҫע�����ݴ���������������⣬���ݷ�ΧС�����Կ��Բ��ü�֦���������Ҫ�ˡ�*/
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
typedef unsigned long long ULL;  
const ULL INF = ~0ULL;  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
ULL ans,n;  
int best;  
void dfs(int dept,int limit,ULL tmp,int num)  
{  
    if(tmp > n) return;  
    if(num > best)  
    {  
        best = num;  
        ans = tmp;  
    }  
    if(num == best && ans > tmp) ans = tmp;  
    for(int i=1;i<=limit;i++)  
    {  
        double cur = (double)tmp;  
        if(n < cur*p[dept]) break;  
        dfs(dept+1,i,tmp *= p[dept],num*(i+1));  
    }  
}  
int main()  
{  
    int T;  
    cin>>T;  
    while(T--)  
    {  
        cin>>n;  
        ans = INF;  
        best = 0;  
        dfs(0,60,1,1);  
        cout<<ans<<" "<<best<<endl;  
    }  
    return 0;  
}  
/*
��Ŀ��	http://acm.hdu.edu.cn/showproblem.php?pid=4542

���⣺	����һ����K����������
    	���������0�������һ����С��������X������X��Լ������ΪK��
    	���������1�������һ����С��X������X��Լ������ΪX-K��
������	���ڲ���0��������������ֱ�������㶨�����ڲ���1������1��X
	�в���X��Լ������ΪK��
 
���룺*/
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
const int N = 50005;  
typedef long long LL;  
const LL INF = (((LL)1)<<62)+1;  
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
LL ans;  
int n;  
int d[N];  
void Init()  
{  
    for(int i=1;i<N;i++) d[i] = i;  
    for(int i=1;i<N;i++)  
    {  
        for(int j=i;j<N;j+=i) d[j]--;  
        if(!d[d[i]]) d[d[i]] = i;  
        d[i] = 0;  
    }  
}  
void dfs(int dept,int limit,LL tmp,int num)  
{  
    if(num > n) return;  
    if(num == n && ans > tmp) ans = tmp;  
    for(int i=1;i<=limit;i++)  
    {  
        if(ans / p[dept] < tmp || num*(i+1) > n) break;  
        tmp *= p[dept];  
        if(n % (num*(i+1)) == 0)  
            dfs(dept+1,i,tmp,num*(i+1));  
    }  
}  
int main()  
{  
    Init();  
    int T,tt=1;  
    scanf("%d",&T);  
    while(T--)  
    {  
        int type;  
        scanf("%d%d",&type,&n);  
        if(type) ans = d[n];  
        else  
        {  
            ans = INF;  
            dfs(0,62,1,1);  
        }  
        printf("Case %d: ",tt++);  
        if(ans == 0) puts("Illegal");  
        else if(ans >= INF) puts("INF");  
        else printf("%I64d\n",ans);  
    }  
    return 0;  
}  

