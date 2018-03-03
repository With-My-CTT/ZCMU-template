//ƽ����չ�� 
namespace Splay
{
	const int maxn = 100000 + 5, INF = 1 << 30;
	int fa[maxn], ch[maxn][2], key[maxn];
	int s[maxn], root, tot, cnt[maxn];
	void init() 
	{
		memset(fa, 0, sizeof fa); memset(ch, 0, sizeof ch);
		memset(key, 0, sizeof key); memset(s, 0, sizeof s);
		tot = root = 0;
	}
	void up(const int &u) 
	{ s[u] = s[ch[u][0]] + s[ch[u][1]] + cnt[u]; }
	//x become the father of y
	void Rot(const int &x, const int& d) 
	{
		int y = fa[x];
		ch[y][d^1] = ch[x][d];
		if (ch[x][d]) fa[ch[x][d]] = y;
		fa[x] = fa[y];
		if (fa[x]) 
		{
			if (y == ch[fa[y]][0]) ch[fa[y]][0] = x;
			else ch[fa[y]][1] = x;
		}
		ch[x][d] = y; fa[y] = x;
		up(y); up(x);
	}
	//tag become x's father
	void splay(const int &x, const int &tag) 
	{
		while (fa[x] != tag) 
		{
			int y = fa[x];
			if (x == ch[y][0]) 
			{
				if (fa[y] != tag && y == ch[fa[y]][0]) Rot(y,1);
				Rot(x,1);
			} 
			else 
			{
				if (fa[y] != tag && y == ch[fa[y]][1]) Rot(y,0);
				Rot(x,0);
			}
		}
		if (!tag) root = x;
	}
	void ins(int &x, const int &val, const int &p) 
	{
		if (!x) 
		{
			x = ++tot; key[x] = val; ch[x][0] = ch[x][1] = 0;
			fa[x] = p; cnt[x] = s[x] = 1; 
		} 
		else 
		{
			int t = x;
			if (val < key[t]) ins(ch[t][0],val,t);
			else if (val > key[t]) ins(ch[t][1],val,t);
			else ++cnt[x];
			up(t);
		}
	}
	void insert(const int &val) 
	{
		ins(root, val, 0); 
		splay(tot,0);
	}
	int find(int x, const int &val) 
	{
		if (!x) return 0;
		if (val < key[x]) return find(ch[x][0],val);
		if (val > key[x]) return find(ch[x][1],val);
		splay(x, 0); return x;
	}
	//delete root
	void del() 
	{
		if (cnt[root] > 1) 
		{ --cnt[root]; --s[root]; return; }
		if( !ch[root][0] )
		{
            fa[ ch[root][1] ] = 0 ;
            root = ch[root][1];
        }
		else
		{
            int cur = ch[root][0];
            while( ch[cur][1] ) cur = ch[cur][1];
            splay( cur , root );
            ch[cur][1] = ch[root][1];
            root = cur , fa[cur] = 0;
			if ( ch[root][1] ) fa[ch[root][1]] = root;
            up( root );
        }
	}
	void Delete(const int& val) 
	{
		int k = find(root,val);
		if (k) del();
	}
	int Kth(int u, int k) 
	{
		if (!u) return 0;
		if (k <= s[ch[u][0]]) return Kth(ch[u][0],k);
		if (k > s[ch[u][0]] + cnt[u]) 
			return Kth(ch[u][1],k-s[ch[u][0]]-cnt[u]);
		return key[u];
	}
	int Rank(int u, int val) 
	{
    	if (!u) return 0;
    	if (key[u] == val) return s[ch[u][0]] + 1;
	    if (key[u] < val) 
			return s[ch[u][0]] + cnt[u] + Rank(ch[u][1],val);
    	else return Rank(ch[u][0],val);
	}
	int pred(int u, int val) 
	{
    	if (!u) return INF;
    	if (val <= key[u]) return pred(ch[u][0],val);
    	int ans = pred(ch[u][1],val);
    	if (ans == INF) ans = key[u];
    	return ans;
	}
	int succ(int u, int val) 
	{
    	if (!u) return INF;
    	if (val >= key[u]) return succ(ch[u][1],val);
    	int ans = succ(ch[u][0],val);
    	if (ans == INF) ans = key[u];
    	return ans;
	}
}
int main() 
{
	int n, op, x;
    scanf("%d", &n);
    using namespace Splay;
    init();
    while (n--) 
	{
        scanf("%d%d", &op, &x);
        if (op == 1) insert(x);
        else if (op == 2) Delete(x);
        else if (op == 3) printf("%d\n", Rank(root,x));
        else if (op == 4) printf("%d\n", Kth(root,x));
        else if (op == 5)printf("%d\n", pred(root,x));
        else printf("%d\n", succ(root,x));
    }
	return 0;
}
