//��������⣺
//��һ������ͼ���ҳ�һ������������ȫͼ
//��ȫͼ(ÿһ�Բ�ͬ����ǡ��һ��������)
//ʱ�临�Ӷȣ�
void clique(int n,int *u,int mat[][MAXN],int L,
			int &Max,int &bb,int *res,int *rr,int *c)
{
    int i,j,vn,v[MAXN];
    if(n)
    {
        if(L+c[u[0]]<=Max) return;
        for(i=0;i<n+L-Max&&i<n;++i)
        {
            for(j=i+1,vn=0;j<n;++j)
                if(mat[u[i][u[j]]) v[vn++]=u[j];
            rr[L]=u[i];
            clique(vn,v,mat,L+1,Max,bb,res,rr,c);
            if(bb) return;
        }
    }
    else if(L>Max)
    {
        Max=L;
        for(i=0;i<L;++i)
            res[i]=rr[i];
        bb=1;
    }
}
int maxclique(int n,int mat[][MAXN],int *ret)
{         //������n  �ڽӾ���mat  �����������ret
    int Max=0,bb,c[MAXN],i,j;
    int vn,v[MAXN],rr[MAXN];
    for(c[i=n-1]=0;i>=0;--i)
    {
        for(vn=0,j=i+1;j<n;++j)
            if(mat[i][j]) v[vn++]=j;
        bb=0;
        rr[0]=i;
        clique(vn,v,mat,1,Max,bb,ret,rr,c);
        c[i]=Max;
    }
    return Max;
}



