//����ͼ���ƥ��  �ڽӾ��� 
//ʱ�临�Ӷȣ�O(sqrt(V)*E) 
//��ʼ����ӳ��ͼG  clr(G,0)  
//��ͼ�������ֶ����� Nx Ny   (x->y : G[x][y]=1 )
//���أ����ƥ��res  ƥ������ Mx[] My[] 
//�ĳ���ͨͼ���ƥ�䣺�ܶ����� Nx = Ny = n+m ; 
int G[MAXN][MAXN],Nx,Ny;  
int dx[MAXN],dy[MAXN],Mx[MAXN],My[MAXN];  
int dis;
bool vis[MAXN];  
bool searchP()
{  
    queue<int>Q;  
    dis=INF;  
    clr(dx,-1); clr(dy,-1);
    for(int i=0;i<Nx;i++)  
        if(Mx[i]==-1) 
            Q.push(i),dx[i]=0;  
    while(!Q.empty())
	{  
        int x=Q.front(); Q.pop();  
        if(dx[x]>dis)  break;  
        for(int y=0;y<Ny;y++)  
            if(G[x][y]&&dy[y]==-1)
			{  
                dy[y]=dx[x]+1;  
                if(My[y]==-1)  dis=dy[y];  
                else  
                {  
                    dx[My[y]]=dy[y]+1;  
                    Q.push(My[y]);  
                }  
            }  
    }  
    return dis!=INF;  
}  
bool DFS(int x)
{  
    for(int y=0;y<Ny;y++)  
       if(!vis[y]&&G[x][y]&&dy[y]==dx[x]+1)  
       {  
           vis[y]=1;  
           if(My[y]!=-1&&dy[y]==dis) continue;  
           if(My[y]==-1||DFS(My[y]))  
           {  
               My[y]=x,Mx[x]=y;  
               return 1;  
           }  
       }  
    return 0;  
}  
int MaxMatch()
{  
    int res=0;  
    clr(Mx,-1);  clr(My,-1);
    while(searchP())  
    {  
        clr(vis,0);
        for(int i=0;i<Nx;i++)  
          if(Mx[i]==-1 && DFS(i)) res++;  
    }  
    return res;  
}  


