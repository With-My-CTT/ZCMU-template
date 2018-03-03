/*�������ģ�
	���ʣ�
	1���������е㵽ĳ����ľ�����У������ĵľ��������С�ģ�
		������������ģ���ô���ǵľ����һ���� 
	2����������ͨ��һ���������õ�һ���µ�������ô�µ���������������
		ԭ�������������ĵ�·���ϡ� 
	3����һ������ӻ�ɾ��һ��Ҷ�ӣ���ô�����������ֻ�ƶ�һ���ߵľ��롣 

    ������    �ҵ�һ���㣬�����е����������������ڵ�������,
��ô�������������������,ɾȥ���ĺ����ɵĶ����������ƽ�⡣

�������Ŀ���ͨ���򵥵����������������һ���������ÿ������
�ӽ������son[u]���ڶ��������ҳ�ʹmax{son[u],n-son[u]-1}��С�Ľ�㡣

ʵ��������������������һ�α����н�����Խ��u��ÿһ������v��
�ݹ�Ĵ���v�����son[v]��Ȼ���ж��Ƿ��ǽ������������������
�������ӽ����ж�u�Ƿ�Ϊ���ġ� 

*/
int n;  
vector <int> adj[MAXN];  
int son[MAXN];  
bool vd[MAXN];  
int ans,asize = 1<<29;  
void DFS(int s)  
{  
    vd[s] = 1;  
    son[s] = 0;  
    int blance = 0;  
    int size = adj[s].size();  
    for (int j = 0;j < size;j++)  
    {  
        int u = adj[s][j];  
        if (vd[u]) continue;  
        DFS(u);  
        son[s] += son[u]+1;  
        blance = max(blance,son[u]+1);  
    }  
    blance = max(blance,n - son[s] - 1);  
    if (blance < asize || blance == asize && s < ans)  
        ans = s,asize = blance;  
}  
  
int main()  
{  
//    freopen("test.txt","r",stdin);  
    int T;  
    cin>>T;  
    while(T--)  
    {  
        cin>>n;  
        for (int i = 1;i <= n;i++) adj[i].clear();  
        for (int i = 1;i <= n-1;i++)  
        {  
            int u,v;  
            scanf("%d%d",&u,&v);  
            adj[u].push_back(v);  
            adj[v].push_back(u);  
        }  
        memset(vd,0,sizeof(vd));  
        asize = 1<<29;  
        DFS(1);  
        cout<<ans<<" "<<asize<<endl;  
    }  
    return 0;  
}  
