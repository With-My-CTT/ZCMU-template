//RMQ�㷨  ���������ֵ/��Сֵ
//˼�룺����dp 
//ST(���߲�ѯ):ÿ����һ��ѯ�ʵó�һ����� 
//�ص㣺��̬ ���ɸ���ֵ 
//Ԥ����ʱ�临�Ӷȣ�NlogN
//ѯ��ʱ�临�Ӷȣ�1 
int a[MAXN],n;  //����a[] �� ����n 
int Max[MAXN][K],Min[MAXN][K];
//k>=log2(N)+1; 
void RMQ() //Ԥ�������� 
{
	clr(Max,0);clr(Min,0);
	for(int i=1;i<=n;i++)
		Max[i][0]=Min[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			int p=1<<(j-1);
			Max[i][j]=max(Max[i][j-1],Max[i+p][j-1]);
			Min[i][j]=min(Min[i][j-1],Min[i+p][j-1]);
		}
}
LL query(int i,int j) //ѯ�� i~j �����еļ�ֵ 
{
	int k=(int)log2(j-i+1.0);
	int mx=max(Max[i][k],Max[j-(1<<k)+1][k]);
	int mi=min(Min[i][k],Min[j-(1<<k)+1][k]);
	return mx; //�������ֵ 
	return mi; //������Сֵ 
} 


