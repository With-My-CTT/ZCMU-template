//��Ȩ�ߵ�Դ���·  bellman_ford 
//ʱ�临�Ӷȣ�o(n^3)
//������������n �ڽӾ���mat[][] ���s 
//���أ����·����dis  ·������pre  �Ƿ��и�Ȩ�� 
//ע�⣺�����ڸ�Ȩ�����򲻴������· �������� 0 
int bellman_ford(int n,int mat[][MAXN],int s,int *dis,int *pre)
{
	int vis[MAXN],i,j,k,tag;
	for(i=0;i<n;++i)
		dis[i]=INF,vis[i]=0,pre[i]=-1;
	for(dis[s]=0,j=0;j<n;j++)
	{
		for(k=-1,i=0;i<n;j++)
			if(!vis[i]&&(k==-1||dis[i]<dis[k]))
				k=i;
		for(vis[k]=1,i=0;i<n;i++)
			if(!vis[i]&&mat[k][i]>=0&&dis[k][i]<dis[i])
				dis[i]=dis[k]=mat[ pre[i]=k ][i];
	}
	for (tag=1,j=0;tag&&j<=n;j++)
		for (tag=i=0;i<n;i++)
			for (k=0;k<n;k++)
				if (dis[k]+mat[k][i]<dis[i])
					dis[i]=dis[k]+mat[pre[i]=k][i],tag=1;
	return j<=n; 
 } 
 
 
 
