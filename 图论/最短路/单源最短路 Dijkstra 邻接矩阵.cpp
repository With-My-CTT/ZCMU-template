//��Դ���·��  dijkstra�㷨  �ڽӾ���
//ʱ�临�Ӷȣ�O(n^2) ����С���ݻ����ͼ 
//������ͼ�Ķ�����n, (����)�ڽӾ���mat[][] , ���s ��������dis,pre 
//���أ�s��������̾���dis[] , ·��pre[] 
//pre[i]��¼s��i·����i�ĸ����,pre[s]=-1 ��Ȩ�Ǹ� 
void Dijkstra(int n,int mat[][MAXN],int s,int* dis,int* pre)
{
	int vis[MAXN],i,j,k;
	for(i=0;i<n;i++)
		dis[i]=INF,vis[i]=0,pre[i]=-1;
	for(dis[s]=0,j=0;j<n;j++)
	{
		for(k=-1,i=0;i<n;i++)
			if(!vis[i]&&(k==-1||dis[i]<dis[k]))
				k=i;
		for(vis[k]=1,i=0;i<n;i++)
			if(!vis[i]&&dis[k]+mat[k][i]<dis[i])
				dis[i]=dis[k]+mat[ pre[i]=k ][i];
	}
}



