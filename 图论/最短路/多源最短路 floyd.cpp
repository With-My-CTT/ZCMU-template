//��Դ���·��,floyd�㷨
//ʱ�临�Ӷȣ�O(n^3)
//����������ͼ�Ĵ�Сn, �ڽӾ���mat
//����: �������̾���dis[][] �� ·��pre[][]
//pre[i][j]��¼i��j���·����j�ĸ����
int dis[MAXN][MAXN],pre[MAXN][MAXN];
void floyd(int n,int mat[][MAXN])
{	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			dis[i][j]=mat[i][j];
			pre[i][j]=(i==j)?-1:i;
		}
	for(int k=0;k<n;k++)
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		if(dis[i][k]+dis[k][j]<min[i][j])
		{
			dis[i][j]=dis[i][k]+dis[k][j];
			pre[i][j]=pre[k][j];
		}
}


