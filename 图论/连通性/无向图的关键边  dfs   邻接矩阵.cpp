//����ͼ�Ĺؼ���  dfs   �ڽӾ���
//ʱ�临�Ӷȣ� O(n^2)
//�ؼ���  ��ȥ���˱���ͼ����ͨ���������� 
//����:�ؼ�������,key[][2]���ر߼�  k[][0]-k[][1]:x--y 
//����ͼ�Ĵ�Сn���ڽ���G,�����ڵ��Ȩ0
int n,G[MAXN][MAXN];
int key[MAXN][2]; 
int dfn[MAXN],low[MAXN];
void search(int now,int& cnt)
{
	low[now]=dfn[now];
	for (int i=0;i<n;i++)
		if (G[now][i])
		{
			if (!dfn[i])
			{
				dfn[i]=dfn[now]+1;
				search(i,cnt);
				if (low[i]>dfn[now])
					key[cnt][0]=i,key[cnt++][1]=now;
				if (low[i]<low[now])
					low[now]=low[i];
			}
			else if ( dfn[i]<dfn[now]-1 && dfn[i]<low[now] )
				low[now]=lev[i];
		}
}
int key_edge()
{
	int ret=0,i;
	for (i=0;i<n;i++) dfn[i]=low[i]=0;
	for (i=0;i<n;i++)
		if (!dfn[i])
		{
			dfn[i]=1;
			search(i,ret);
		}		
	return ret;
}


