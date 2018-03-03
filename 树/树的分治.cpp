//���ķ���
/*
����һ��N(1<= N <=10000)�����Ĵ�Ȩ��������dist(u,v)Ϊu,v���������·�����ȣ�
·���ĳ��ȶ���Ϊ·�������бߵ�Ȩ�͡��ٸ���һ�� K  ��������ڲ�ͬ���������a,b��
�������dist(a,b) <=K�����(a,b)Ϊ�Ϸ���ԡ���Ϸ���Ը�����
˼·���������ġ������㷨������·�������е�Ӧ�á������潲��ĺ������һ��·��Ҫ
ô�����ڵ㣬Ҫô��һ�������У������÷����㷨���ҵ�����������Ϊ���ڵ㣬����ÿ��
���Ľڵ������ټ���һ�롣��������ǰ���ڵ�·��<=k�ĵ������Ȼ��Ѹ��ڵ�ȥ�����
��ԭ�������ֳɼ��������ˣ��ٴ����������������󾭹�һ�����ڵ��·��ʱ�����滹����
�˵������ͬһ�����������������Ҫȥ���ⲿ�ֵĵ㡣
dis(i)+dis(j)<=k(i,j�ĸ��ڵ㲻Ϊ���ڵ��ͬһ�����ӣ�
=dis(i)+dis(j)<=k-dis(i)+dis(j)<=k(i,j�ĸ��ڵ����ڸ��ڵ��ͬһ����).
*/ 


#include <algorithm>  
#include<stdio.h>  
#include<string.h>  
const int N=10010;  
using namespace std;  
int head[N],num,f[N],son[N],n,D,root,size,ans,dis[N],d[N],cum;  
bool vis[N];  
#define max(a,b) (a<b?b:a)  
struct edge  
{  
    int st,ed,w,next;  
}e[N*2];  
void addedge(int x,int y,int w)  
{  
    e[num].st=x;e[num].ed=y;e[num].w=w;e[num].next=head[x];head[x]=num++;  
    e[num].st=y;e[num].ed=x;e[num].w=w;e[num].next=head[y];head[y]=num++;  
}  
void getroot(int u,int father)//����������  
{  
    int i,v;  
    f[u]=0;son[u]=1;  
    for(i=head[u];i!=-1;i=e[i].next)  
    {  
        v=e[i].ed;  
        if(vis[v]||v==father)continue;  
        getroot(v,u);  
        son[u]+=son[v];  
        f[u]=max(f[u],son[v]);  
    }  
    f[u]=max(f[u],size-son[u]);  
    if(f[u]<f[root])root=u;  
}  
void getdis(int u,int father)//��ڵ㵽���ڵ�ľ���  
{  
    int i,v;  
    son[u]=1;//���������Ľڵ���ӽڵ�����������Ҳ��ac  
    d[cum++]=dis[u];//���㵽���ڵ�ľ����������  
    for(i=head[u];i!=-1;i=e[i].next)  
    {  
        v=e[i].ed;  
        if(vis[v]||v==father)continue;  
        dis[v]=dis[u]+e[i].w;  
        getdis(v,u);  
        son[u]+=son[v];  
    }  
}  
int cont(int u,int mit)  
{  
    int res=0,L,R;  
    dis[u]=mit;  
    cum=0;  
    getdis(u,0);  
    sort(d,d+cum);//���㵽���ڵ�ľ�������  
    for(L=0,R=cum-1;L<R;)  
    {  
        if(d[L]+d[R]<=D) res+=(R-L++);  
		//���d[L]+d[R]<=D,L����Ľڵ�����루R-L�����ڵ�ɶ�  
        else R--;  
    }  
    return res;  
}  
void work(int u)  
{  
    int i,v;  
   vis[u]=true;  
   ans+=cont(u,0);//·�������ø��ڵ�ĵ����  
   for(i=head[u];i!=-1;i=e[i].next)  
   {  
      v=e[i].ed;  
      if(vis[v])continue;  
      ans-=cont(v,e[i].w);//��ȥ����v�����ĵ����  
      root=0;f[root]=size=son[v];  
      getroot(v,0);//��v�����ĸ��ڵ�  
      work(root);//��v�����ĵ��  
   }  
}  
int main()  
{  
    int i,x,y,w;  
    while(scanf("%d%d",&n,&D),n||D)  
    {  
        memset(head,-1,sizeof(head));  
        num=0;  
        for(i=1;i<n;i++)  
        {  
            scanf("%d%d%d",&x,&y,&w);  
            addedge(x,y,w);  
        }  
        memset(vis,false,sizeof(vis));  
        root=0;f[root]=size=n;ans=0;  
        getroot(1,0);  
        work(root);  
        printf("%d\n",ans);  
    }  
    return 0;  
}  
