//����ͼǿ��ͨ����   BFS �ڽӾ��� 
//ʱ�临�Ӷȣ�O(n^2) 
//ǿ��ͨ�������ڲ�ÿ���㶼�໥�ɴ����ͨ���� 
//���أ� ǿ��ͨ������ret  
//id[x]: ����x���ڵ�id[x]��ǿ��ͨ���� 
//�й���Ŀ�ؼ�����ʹ��id[]�ж϶����Ƿ�����ͬһ��ǿ��ͨ���� 
int n;
int G[MAXN][MAXN];
int id[MAXN];
int find_components()
{
	int ret=0,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
	clr(id,0);
	for(int k=0;k<n;k++)
	if(!id[k])
	{
		for(int i=0;i<n;i++)
			a[i]=b[i]=c[i]=d[i]=0;
		a[k]=b[k]=1;
		int ok=1;
		while(ok)
		{
			ok=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]&&!c[i])
				{
					c[i]=ok=1;
					for(int j=0;j<n;j++)
						if(G[i][j]&&!a[j])
							a[j]=1;
				}
				if(b[i]&&!d[i])
				{
					d[i]=ok=1;
					for(int j=0;j<n;j++)
						if(G[j][i]&&!b[j])
							b[j]=1;
				}
			}
		}
		ret++;
		for (int i=0;i<n;i++)
			if (a[i]&b[i])  id[i]=ret;
	}
	return ret;
}


