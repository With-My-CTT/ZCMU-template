/*  ����ֱ���� 
	���壺������������ľ�������ֵ��
	���Ӷȣ�O(n)
	����������BFS����ȡһ������Զ�ĵ�u
		  ���� u ��Զ�ĵ� v ��u->v����ֱ�� 
    ע�⣺ʹ��ǰdis��G��Ҫ��ʼ�� 
    
*/  
#define MAXN 105  
vector<int> G[MAXN];  
int n,m;  
int dis[MAXN];  
int bfs(int u)  
{  
    queue<int> que;  
    que.push(u);  
    dis[u]=0;  
    int Max=0,Maxi=1;  
    while(!que.empty())  
    {  
        int f=que.front();  
        que.pop();  
        if(dis[f]>Max) Maxi=f;  
        for(int i=0; i<G[f].size(); i++)  
        {  
            int to=G[f][i];  
            if(dis[to]==-1)  
                que.push(to),dis[to]=dis[f]+1;  
        }  
    }  
    return Maxi;  
}  
int main()  
{  
    while(~scanf("%d",&n))  
    {  
        for(int j=0; j<MAXN; j++) G[j].clear();  
        for(int j=1; j<n; j++)  
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            G[u].push_back(v);  
            G[v].push_back(u);  
        }  
        memset(dis,-1,sizeof dis);  
        int p=bfs(1);  
        memset(dis,-1,sizeof dis);  
        int q=bfs(p);  
        int ans=dis[q];  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
