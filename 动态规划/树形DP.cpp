/*	����DP 
	���⣺	��һ��������������·��u��v�ļ�ֵΪ·���ϲ�ͬ��ɫ�Ľڵ��������
		  	������·�����ܼ�ֵΪ����
	��⣺	�������⣬����Ҫ���ļ�ֵ����ת��Ϊ������ÿ��·���ϰ�������
			����ɫ��Ҳ����n*��n-1��/2*������ɫ��������Ȼ���ȥÿ����ɫ
			�Բ����������ɫ�ĵ�����·���Ĺ��ס�
			<=> �ȼ���ÿ����ɫ�ж�����·������ <=> ������� - ÿ����ɫ��
			������·��û�о���������ɫ
*/
struct node {
	int to, next;
}edge[maxn<<1];
int head[maxn], tot, sum[maxn], u, v;
void add_edge(int u, int v) 
{
	edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
	edge[tot].to = u; edge[tot].next = head[v]; head[v] = tot++;
}
int col[maxn], size[maxn];
//size[i] �Ըýڵ�Ϊ�������Ľڵ���
//sum[i]����ɫiΪ���������ܴ�С
ll ans, n, num;
bool vis[maxn];
void init() 
{
	clr(sum, 0); clr(size, 0); clr(head, -1); clr(vis, false);
	tot = 0; num = 0; ans = 0;
}
void dfs(int u, int fa) 
{
	size[u] = 1;
	ll pre = sum[col[u]], c = 0;
	for (int i = head[u]; i != -1; i = edge[i].next) 
	{
		int v = edge[i].to;
		if(v != fa) {
			dfs(v, u);
			size[u] += size[v];
			ll tmp = sum[col[u]] - pre;;//����v����col[u]Ϊ����������С
			ll cnt = size[v] - tmp;//����v��, ����u��ɫ֮��Ľڵ����
			pre = sum[col[u]];//��¼��һ�ε�sum
			ans -= cnt * (cnt - 1) / 2;//v�����и��ڵ��໥�������辭��col[u]
			c += tmp;
		}
	}
	sum[col[u]] += size[u] - c;//������uΪ����������С
}
int main() 
{
	int cas = 1;
	while(~scanf("%d", &n)) 
	{
		init();
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d", &col[i]);
			if(!vis[col[i]]) 
				num++,vis[col[i]] = true;
		}
		for (int i = 1; i < n; i++) 
		{
			scanf("%d %d", &u, &v);
			add_edge(u, v);
		}
		ans = num * (n - 1) * n / 2;
		dfs(1, -1);
		for (int i = 1; i <= n; i++) 
		{
			if(sum[i]) 
			{
				ll cnt = n - sum[i];
				ans -= cnt * (cnt - 1) / 2;
			}
		}
		printf("Case #%d: %lld\n", cas++, ans);
	}
	return 0;
}
