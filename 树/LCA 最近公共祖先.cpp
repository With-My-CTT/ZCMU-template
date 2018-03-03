//LCA  �������������
//�ھ�̬��һ������(ǰ��)
//��β�ѯ���������ڵ������������Ⱥ��������� 
//˼·��DFSԤ����+����dp
//ʱ�临�Ӷȣ� Ԥ����NlogN  ��ѯ��logN 
const int MAXN = 200000+100;  
const int M = 20 ;  // M > log2(MAXN) 
vector<int> G[MAXN];  
int deep[MAXN], fa[MAXN][M];  
void DFS(int cur, int pre)  
{   //cur:��ǰ�ڵ�    pre:��һ���ڵ� 
    fa[cur][0] = pre;  //��������
    for(int i=1; i<M; ++i)  
        fa[cur][i] = fa[ fa[cur][i-1] ][i-1];  
    for(int i=0;i<G[cur].size();i++)  
    {  
  		int to=G[cur][i]; 
        if(to == pre) continue;  
        deep[to] = deep[cur] + 1;  
        DFS(to, cur);  
    }  
}  
int LCA(int x, int y)  
{  
    if(deep[x] > deep[y]) swap(x, y);  
    for(int i=0; i<M; ++i)  
        if(deep[y]-deep[x]>>i & 1)  
        	y = fa[y][i];  
    for(int i=M-1; i>=0; --i)  
        if(fa[x][i] != fa[y][i])  
            x = fa[x][i], y=fa[y][i];  
    return x == y?x:fa[x][0];  
}  
int main()  
{  
    int n, q; //�ܹ� n ���ڵ㣬 q ��ѯ�� 
    scanf("%d%d",&n,&q);  
	//�ڵ���Ϊ 1~N �����N-1���� 
    for(int i=2; i<=n; ++i)  
    {   //���� x �� y ������� 
        int x,y;  
        scanf("%d%d",&x,&y);  
        G[y].push_back(x);  
        G[x].push_back(y);  
    }  
    DFS(1, 0);  //�Խڵ� 1 Ϊ���������Ϊ 0 
    while(q--)  
    {  
        int x,y;  
        scanf("%d%d",&x,&y);  
        printf("%d\n",LCA(x,y)); 
		//��������ڵ�������������
		printf("%d\n",deep[x]+deep[y]-2*deep[LCA(x,y)]); 
    	//����������ڵ��ľ��� 
	}  
    return 0;  
}  
