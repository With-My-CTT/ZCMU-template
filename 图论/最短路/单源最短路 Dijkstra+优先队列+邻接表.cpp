//��Դ���·��  dijkstra+���ȶ���+�ڽӱ� 
//ʱ�临�Ӷȣ�O(ElogV)   �����ݻ�ϡ��ͼ 
//��������� s 
//���أ�s��������̾���dis[]
//ע�⣺�����и�Ȩ�� 
struct node{  
    int to,cost;  
    node(int a,int b){ to=a;cost=b; }  
    bool operator<(const node &a) const  
    { return cost > a.cost;  } //cost��С�������� 
};  
vector<node> G[MAXN];  
//����߷����� (x->y : v)
//G[x].push_back(node(y,v));
int dis[MAXN];  
void dijkstra(int s)  
{  
    int i;  
    for(i=0;i<MAXN;i++) dis[i]=INF;  
    dis[s]=0;  
    priority_queue<node> pq;  
    pq.push(node(s,dis[s]));  
    while(!pq.empty())  
    {  
        node x=pq.top();  
        pq.pop();  
        for(i=0;i<G[x.to].size();i++)  
        {  
            node y=G[x.to][i];  
            if(dis[y.to]>x.cost+y.cost)  
            {  
                dis[y.to]=x.cost+y.cost;  
                pq.push(node(y.to,dis[y.to]));  
            }  
        }  
    }  
}  



