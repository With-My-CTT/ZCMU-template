//��������
int in[MAXN],a[MAXN];
int n,m;
bool map[MAXN][MAXN];
int topu()
{
    queue<int> q;
    int cnt = 1,u;
    while(!q.empty()) q.pop();
    for(int i = 1; i <= n ; i++)
        if(in[i] == 0)
            q.push(i);
		//������������Ľڵ����
    while(!q.empty())  //
    {
        u = q.front();q.pop();
        a[cnt++] = u;
		//��û����������Ľڵ���뵽��������
        for(int i = 1; i <= n ; i++)
        {
            if(map[u][i])
            {
                in[i] --;//ɾȥ��uΪ����ı�
                if(in[i] == 0) q.push(i);
            }
        }
        if(cnt == n)//����������������
    }
}



