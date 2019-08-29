/*LCA+��ϯ��
ÿ��ѯ��u,v,k,ѯ������u-v��·���б�ȨֵС��k������ 
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PI;
const int maxn = 1e5+5;
vector<int>a;
vector<PI>e[maxn];
int head[maxn],n,tot,len;
int s[maxn*20],l[maxn*20],r[maxn*20];
int dep[maxn],f[maxn][20];

int build( int le,int ri )
{
    int rt = tot++;
    int mid = le+ri>>1;
    if(le == ri){
        l[rt] = r[rt] = -1;
        return rt;
    }
    l[rt] = build( le,mid );
    r[rt] = build( mid+1,ri );
    return rt;
}

int updata( int prt,int le,int ri,int val )
{

    int rt = tot++;
    int mid = le+ri>>1;
    s[rt] = s[prt]+1;
    if( le==ri )
    {
        l[rt] = r[rt] = -1;
        return rt;
    }
    if( val<=mid )
    {
        l[rt] = updata( l[prt],le,mid,val );
        r[rt] = r[prt];
    }
    else
    {
        l[rt] = l[prt];
        r[rt] = updata( r[prt],mid+1,ri,val );
    }
    return rt;
}

int query( int rt,int le,int ri,int val )
{
    if( 1<=le&&ri<=val ) return s[rt];
    if( ri<1||val<le ) return 0;
    int mid = le+ri>>1;
    return query( l[rt],le,mid,val )+query( r[rt],mid+1,ri,val );
}

void pre(int u,int fa)
{
    dep[u]=dep[fa]+1;
    f[u][0]=fa;
    for(int i=1;(1<<i)<=dep[u];i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(int i=0;i<e[u].size();i++){
        int to = e[u][i].first;
        int ww = e[u][i].second;
        if(to==f[u][0]) continue;
        head[to] = updata( head[u],1,len, lower_bound( a.begin(),a.end(),ww )-a.begin()+1  );
        pre(to,u);
    }
}

int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);//��x����ȸ���
    int cha=dep[x]-dep[y];//����a��x��y�����֮��
    for(int i=0;(1<<i)<=cha;i++){
        if((1<<i)&cha){
            x=f[x][i];
        }
    }//��x������y��ͬ�߶���
    if(x!=y){//���a��b����ͬһ�������ô��Ҫ������,�����ͬһ����㣬��ô������LCA
        for(int i=(int)log2(n);i>=0;i--){//�Ӵ�С������ȷ����Ȼ��
            if(f[x][i]!=f[y][i]){//�������ȣ���˵���ýڵ����Ȼ��Ǳ�LCA��
                x=f[x][i];
                y=f[y][i];
                //�Ǿͼ�����
            }
        }
        x=f[x][0];
        //���ʱ��x��y������ͬһ���ڵ㣬����x��y�ĸ��׾���x��y��lca��
    }
    return x;
}
int main()
{
    int m; scanf( "%d%d", &n, &m );
    for( int i=1;i<n;i++ )
    {
        int u,v,w; scanf( "%d%d%d", &u, &v, &w );
        a.push_back( w );
        e[u].push_back( PI(v,w) );
        e[v].push_back( PI(u,w) );
    }
    sort( a.begin(),a.end() );
    a.erase( unique( a.begin(),a.end()),a.end() );
    tot = 0;
    len = a.size();
    head[1] = build( 1,len );
    //printf( "sas" );
    pre( 1 , 0 );
    for( int i=1;i<=m;i++ )
    {
        int u,v,w; scanf( "%d%d%d", &u, &v, &w );
        int p = upper_bound( a.begin(),a.end(),w )-a.begin();
       // printf("%d===\n", p );
        if( p<1 ) printf( "0\n" );
        else
        {
            printf( "%d\n", query( head[u],1,len,p )+query( head[v],1,len,p )-2*query( head[ lca(u,v) ],1,len,p ) );
        }
    }
}

