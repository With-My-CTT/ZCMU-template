//���������  �ڽӾ��� 
//ʱ�临�Ӷ� ��n^2logm 
//������������n ͼmat[][] Դ��source ���sink 
//���أ������j ÿ���ߵ�����flow[][] 
//ע�⣺ ��ӱߣ�G[x][y]+=v (һ��Ϊ����) 
//���� �κ������������������������С������� 
int max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN])
{
	int pre[MAXN],que[MAXN],dis[MAXN],p,q,t,i,j;
	if(source==sink) return INF;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++) flow[i][j]=0;
	for(;;)
	{
		for(i=0;i<n;i++) pre[i]=0;
		pre[ t=source ]=source+1;
		dis[t]=INF;
		for (p=q=0 ; p<=q && !pre[sink] ; t=que[p++] )
			for (i=0;i<n;i++)
				if ( !pre[i] && (j=mat[t][i]-flow[t][i]) )
				{
					pre[ que[q++]=i ]=t+1;
					dis[i]= dis[t]<j ? dis[t] : j;
				}
				else if ( !pre[i] && (j=flow[i][t]) )
				{
					pre[ que[q++]=i ]=-t-1;
					dis[i]= dis[t]<j ? dis[t] : j;
				}
		if( !pre[sink] ) break;
		for( i=sink ; i!=source ; )
			if(pre[i]>0)
			{
				flow[ pre[i]-1 ][i]+=dis[sink];
				i=pre[i]-1;
			}
			else 
			{
				flow[i][ -pre[i]-1 ]-=dis[sink];
				i=-pre[i]-1;
			}
	}
	for(j=i=0;i<n;i++) j+=flow[source][i];
	return j;
 } 
 
 
