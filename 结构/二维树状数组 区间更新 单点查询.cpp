/*| 	��ά��״���� 	������� �����ѯ 
		ʱ�临�Ӷ�: �����޸� logN*logM  �����ѯ logN*logM 
 	1��	��ʼ����Bit[][]��Ϊ0; n,m Ҫ����ֵ 
 		�����±�һ��Ҫ��1��ʼ!!!!!!!!! 
*/
typedef long long LL;
const int maxn = 2048;
LL Bit[maxn][maxn];
int n,m;
int lowbit(int x)
{ return x&(-x); }
void add(int x,int y,LL v)
{
	for(int i=x;i<n+10;i+=lowbit(i))
		for(int j=y;j<m+10;j+=lowbit(j))
			Bit[i][j]+=v;
}
LL sum(int x,int y)
{	//�����ѯ 
	LL res=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			res+=Bit[i][j];
	return res;
}
void update(int r1,int c1,int r2,int c2,LL v)
{	//	��ά������� 
	add(r1,c1,v);
	add(r1,c2+1,-v);
	add(r2+1,c1,-v);
	add(r2+1,c2+1,v);
}

