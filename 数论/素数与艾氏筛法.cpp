//���� 

//�������� 
//1��X�е���������  ����(x)/(x/ln(x))=1
//��: 
//n=int((double)n-log10((double)n)-log10(log(10.0))+1.0);

//һ�㷨�ж����� 
bool is_prim(int x)
{
	if(x==1) return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0) return 0;
	return 1;
} 

//����ɸ��ͳ������
//is_prime[] ��¼�� [a,b] �Ƿ�Ϊ���� 
//ע�⣺���㷨�Ὣ 1 ����Ϊ���� 
bool is_prime[maxn];
bool is_prime_small[maxn];
void segment_seive(LL a,LL b)
{
	for(int i=0;(LL)i*i<=b;i++) 
		is_prime_small[i]=true;
	for(int i=0;i<=b-a;i++) 
		is_prime[i]=true;
	for(int i=2;(LL)i*i<=b;i++)
		if(is_prime_small[i])
		{
			for(int j=2*i;(LL)j*j<=b;j+=i) 
				is_prime_small[j]=false;
			for(LL j= max(2LL,(a+i-1)/i) * i;j<=b;j+=i) 
				is_prime[j-a]=false;
		}
} 

// ����ɸ����������  �򻯰�
// �� 1 �� MAXN �е��������浽����prime��

int prime[MAXN/10],tot; //��MAXN��Сʱ��10Ҫȥ�� 
bool num[MAXN]; 
void solve()
{
	tot=0;
	clr(num,0); num[1]=1;
	for(int i=2;i<MAXN;i++)
	{
		if(!num[i]) prime[tot++]=i;
		for(int j=0;j<tot&&i*prime[j]<MAXN;j++)
		{
			num[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}


