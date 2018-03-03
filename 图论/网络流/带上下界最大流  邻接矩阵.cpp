//�����½������  �ڽӾ��� 
//������������n ͼmat[][] Դ��source ���sink 
//���أ������j ÿ���ߵ�����flow[][] 
//��������������һ��ģ�� 
int limit_max_flow(int n,int mat[][MAXN],int bf[][MAXN],
				int source,int sink,int flow[][MAXN])
{
	int i,j,sk,ks;
	if (source==sink) return INF;
	mat[n][n+1]=mat[n+1][n]=mat[n][n]=mat[n+1][n+1]=0; 
	for (i=0;i<n;i++)
	{
		mat[n][i]=mat[i][n]=mat[n+1][i]=mat[i][n+1]=0;
		for (j=0;j<n;j++)
		{
			mat[i][j]-=bf[i][j];
			mat[n][i]+=bf[j][i];
			mat[i][n+1]+=bf[i][j];
		}
	}
	sk=mat[source][sink];
	ks=mat[sink][source];
	mat[source][sink]=mat[sink][source]=INF;
	for (i=0;i<n+2;i++)
		for (j=0;j<n+2;j++) flow[i][j]=0;
		
	_max_flow(n+2,mat,n,n+1,flow);//���������һ��ģ�� 
	
	for (i=0;i<n;i++)
		if (flow[n][i]<mat[n][i]) return -1;
	flow[source][sink]=flow[sink][source]=0;
	mat[source][sink]=sk;
	mat[sink][source]=ks;
	
	_max_flow(n,mat,source,sink,flow);//���������һ��ģ�� 
	
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			mat[i][j]+=bf[i][j];
			flow[i][j]+=bf[i][j];
		 } 
	for (j=i=0;i<n;i++) j+=flow[source][i];
	return j;
}


