/*	�߶��� ���串�� �����ѯ
	���串�ǣ���һ������������ֵ�滻����һ��ֵ 
	���㸲�ǣ��������ұ߽�Ϊͬһֵ���� 
*/ 

#define lson l , m , rt << 1  
#define rson m + 1 , r , rt << 1 | 1  
const int maxn = 100100;  
const int INF=0x7fffffff;  

int lazy[maxn<<2];  
int MAX[maxn<<2];  
int MIN[maxn<<2];  
int SUM[maxn<<2];  
void PushUp(int rt) 
{ //�����ӡ��Һ������ϸ��¸��ڵ�  
    SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];  
    MAX[rt] = max(MAX[rt<<1],MAX[rt<<1|1]);  
    MIN[rt] = min(MIN[rt<<1],MIN[rt<<1|1]);  
}  
void PushDown(int rt,int m) 
{ //���¸���  
    if (lazy[rt]) 
	{ //������  
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];  
        SUM[rt<<1] = (m - (m >> 1)) * lazy[rt];  
        SUM[rt<<1|1] = ((m >> 1)) * lazy[rt];  
        MAX[rt<<1]=MAX[rt<<1|1]=lazy[rt];  
        MIN[rt<<1]=MIN[rt<<1|1]=lazy[rt];  
        lazy[rt] = 0;  
    }  
}  
//���е�l��r��rt  ����1��n��1  
void build(int l,int r,int rt) 
{ //��ʼ������  
    lazy[rt] = 0;  
    if (l== r) {  
        SUM[rt]=MAX[rt]=MIN[rt]=0;  //��ʼ��Ϊ0�Ľ���  
        /*scanf("%d",&SUM[rt]);  //�߶���߽����ķ��� 
          MAX[rt]=MIN[rt]=SUM[rt]; */ 
        return ;  
    }  
    int m = (l + r) >> 1;  
    build(lson);  
    build(rson);  
    PushUp(rt);  
}  
void update(int L,int R,int v,int l,int r,int rt) 
{   //��L~R�����ֵ��Ϊv  
    //if(L>l||R>r) return;  
    if (L <= l && r <= R) 
	{  
        lazy[rt] = v;  
        SUM[rt] = v * (r - l + 1);  
        MAX[rt] = MIN[rt] = v;  
        //printf("%d %d %d %d %d\n", rt, sum[rt], c, l, r);  
        return ;  
    }  
    PushDown(rt , r - l + 1);  
    int m = (l + r) >> 1;  
    if (L <= m) update(L , R , v , lson);  
    if (R > m) update(L , R , v , rson);  
    PushUp(rt);  
}  
  
int querySUM(int L,int R,int l,int r,int rt) 
{  //������L~R�ĺ�  
    if (L <= l && r <= R) return SUM[rt];  
    PushDown(rt , r - l + 1);  
    int m = (l + r) >> 1;  
    int ret = 0;  
    if (L <= m) ret += querySUM(L , R , lson);  
    if (m < R) ret += querySUM(L , R , rson);  
    return ret;  
}  
int queryMIN(int L,int R,int l,int r,int rt) 
{  //������L~R����Сֵ  
    if (L <= l && r <= R) return MIN[rt];  
    PushDown(rt , r - l + 1);  
    int m = (l + r) >> 1;  
    int ret = INF;  
    if (L <= m) ret = min(ret, queryMIN(L , R , lson));  
    if (m < R) ret = min(ret,queryMIN(L , R , rson));  
    return ret;  
}  
int queryMAX(int L,int R,int l,int r,int rt) 
{  //������L~R�����ֵ  
    if (L <= l && r <= R) return MAX[rt];  
    PushDown(rt , r - l + 1);  
    int m = (l + r) >> 1;  
    int ret = -INF;  
    if (L <= m) ret = max(ret, queryMAX(L , R , lson));  
    if (m < R) ret = max(ret,queryMAX(L , R , rson));  
    return ret;  
}  
  
int main() 
{  
    int  n , m;  
    char str[5];  
    while(scanf("%d%d",&n,&m)!=EOF) 
	{  
        build(1 , n , 1);  
        while (m--) 
		{  
            scanf("%s",str);  
            int a , b , c;  
            if(str[0]=='T') 
			{   //���串�� 
                scanf("%d%d%d",&a,&b,&c);  
                update(a , b , c , 1 , n , 1);  
            } 
			else if(str[0]=='Q') 
			{   //�����ѯ ��� 
                scanf("%d%d",&a,&b);  
                cout<<querySUM(a,b,1,n,1)<<endl;  
            } 
			else if(str[0]=='A') 
			{   //�����ѯ ���ֵ 
                scanf("%d%d",&a,&b);  
                cout<<queryMAX(a,b,1,n,1)<<endl;  
            } 
			else if(str[0]=='I') 
			{   //�����ѯ ��Сֵ 
                scanf("%d%d",&a,&b);  
                cout<<queryMIN(a,b,1,n,1)<<endl;  
            }  
        }  
    }  
    return 0;  
}  
