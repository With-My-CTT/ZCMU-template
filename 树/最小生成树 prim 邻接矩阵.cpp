//����ͼ��С������ prim �ڽӾ��� 
//ʱ�临�Ӷȣ� o(n^2) 
//ע�⣺���뱣֤ͼ����ͨ 
int G[MAXN][MAXN];
void prim()
{   //Ĭ�����Ϊ 0 
    int dis[MAXN],vis[MAXN];  
    int i,v,j,mi;  
    for(i=0;i<n;i++) 
        vis[i]=0,dis[i]=G[0][i];  
    for(i=0;i<n;i++)
	{  
        mi=INF;  
        for(j=0;j<n;j++)  
            if(!vis[j] && dis[j]<mi)  
                mi=dis[j],v=j;  
        vis[v]=j;  
        for(j=0;j<n;j++) 
            if(!vis[j] && G[v][j]<dis[j])  
                dis[j]=G[v][j];  
    }  
    for(dis[0]=0,i=0;i<n;i++) dis[0]+=dis[i];  
    return dis[0];   
}  


