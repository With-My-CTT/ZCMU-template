//�����������  LIS  ���д�� 
//ʱ�临�Ӷȣ�NlogN
//������ <algorithm> 
//�ı���� cmp �ɻ������Ч�� 
int a[MAXN]; 
template<class Cmp>  
int LIS (int n,Cmp cmp)  
{  
    static int m=0, end[MAXN];  //static ����ʡ�� 
    for (int i=0;i<n;i++)  
    {  
        int pos = lower_bound(end, end+m, a[i], cmp)-end;  
        end[pos] = a[i], m += pos==m;  
    }  
    return m;  
}  

//ʹ�÷����� 
LIS(n,less<int>() );           �ϸ�����  
LIS(n,less_equal<int>() );     ���ϸ�����  
LIS(n,greater<int>() );        �ϸ��½�  
LIS(n,greater_equal<int>() );  ���ϸ��½�  
 
 
 
