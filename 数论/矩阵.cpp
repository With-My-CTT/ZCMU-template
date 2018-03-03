//����

//����
struct Matrix{
	int n,m;  //�� �� 
	int date[MAXN][MAXN]; 
	Matrix(int n,int m):n(n),m(m){}
}; 
//�����ʼ��
//�� ���Խ��߽�Ϊ 1
Matrix init(int x,int y)
{
	Matrix res(x,y);
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			if(i==j) res.date[i][j]=1;
			else res.date[i][j]=0;
	return res;
} 

//����ӷ�
//Ҫ�������� a.n==b.n  a.m==b.m 
Matrix plu(Matrix a,Matrix b)
{
	Matrix c(a.n,a.m);
	for(int i=0;i<a.n;i++)
		for(int j=0;j<a.m;j++)
			c.date[i][j]=a.date[i][j]+b.date[i][j];
	return c;
}

//����˷�  
//Ҫ�������Ͼ���˷�����: a.m==b.n
//���Ӷȣ�N^3 
Matrix mul(Matrix a,Matrix b)
{
	Matrix c(a.n,b.m);
	for(int i=0;i<c.n;i++)
		for(int j=0;j<c.m;j++)
		{
			c.date[i][j]=0;
			for(int k=0;k<a.m;k++)
				c.date[i][j]+=a.date[i][k]*b.date[k][j];
		}
	return c;
}

//��������� 
//����� a �� k�η� (���� a ����Ϊ���� n==m )
Matrix fastmod(Matrix a,int k)
{
	Matrix res=init(a.n,a.m);
	while(k)
	{
		if(k&1) res=mul(res,a); //�˷� 
		k>>=1;
		a=mul(a,a); //�˷� 
	}
	return res;
}

//�� ���� a �� 1~K ��֮��
//���� a^1+a^2+a^3+...+a^k
Matrix dfs(Matrix a,int k)
{
	if(k==1) return a;
	Matrix res=init(a.n,a.m);
	res=plu(res,fastmod(a,k>>1));
	res=mul(res,dfs(a,k>>1));
	if(k&1) res=plu(res,fastmod(a,k));
	return res;
}










 
