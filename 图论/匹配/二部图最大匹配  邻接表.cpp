//����ͼ���ƥ��  �ڽӱ�
//ʱ�临�Ӷȣ�O(sqrt(V)*E) 
//��ʼ����vector<>G �ڽӱ�  G[i].clear;  
//��ͼ�������ֶ����� Nx Ny  
//		(x->y : G[x].push_back(y); )
//      ����ͼҪ˫������ 
//���أ����ƥ��res  ƥ������ Left[]
//�ĳ���ͨͼ���ƥ�䣺�ܶ����� Nx = Ny = n+m ; 
vector<int> G[MAXN];
int Nx,Ny;
int Left[MAXN];
bool vis[MAXN];
bool match(int i)
{
	if(vis[i]) return false;
	vis[i]=true;
    for(int j=0;j<G[i].size();++j) 
		if(!vis[G[i][j]])
	    {
	        int v = G[i][j];
	        if(Left[v]<0||match(Left[v]))
	        {
	            Left[v] = i;
	            Left[i] = v;
	            return true;
	        }
	    }
    return false;
}
//�������ƥ����
int hungary()
{
    int res=0;
    clr(Left,-1);
    for(int i=0;i<Ny;++i)
    	if(Left[i]<0)
	    {  //��0�㿪ʼ 
	        clr(vis,0);
	        if(match(i)) res++;
	    }
    return res;
}


