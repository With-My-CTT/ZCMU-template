/*	��ά��״����  �����ѯ ������� 
	�ռ临�Ӷȣ�4*N*M
	ʱ�临�Ӷ�: �����޸� logN*logM  �����ѯ logN*logM 
	ע�⣺ 	���ʺ����������޸ģ������ѯ���ͣ������޸ģ������ѯ�� 
			ʱ�俪�����������ַ����ĳ�����
*/  
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2048;

int n, m;
int lowbit(int x)
{ return x&(-x); }

template<class T>
struct BIT_2D {
    struct Core{
        T C[4][MAXN][MAXN];
        void I() { memset(C, 0, sizeof(C)); }
        void update(int x0,int y0,T val) 
		{
            for(int x = x0; x <= n; x += lowbit(x)) 
			{
                for(int y = y0; y <= m; y += lowbit(y)) 
				{
                    C[0][x][y] += val;
                    C[1][x][y] += val * x0;
                    C[2][x][y] += val * y0;
                    C[3][x][y] += val * x0 * y0;
                }
            }
        }
        T query(int x0,int y0) 
		{
            T ret = 0;
            for(int x = x0; x > 0; x -= lowbit(x)) 
			{
                for(int y = y0; y > 0; y -= lowbit(y)) 
				{
                    ret += C[0][x][y] * (x0 + 1) * (y0 + 1);
                    ret -= C[1][x][y] * (y0 + 1);
                    ret -= C[2][x][y] * (x0 + 1);
                    ret += C[3][x][y];
                }
            }
            return ret;
        }
    };
    Core core;
    void update(int x0,int y0,int x1,int y1,T val) 
	{
        int dx[4] = {x0, x1 + 1, x0, x1 + 1};
        int dy[4] = {y0, y1 + 1, y1 + 1, y0};
        T v[4] = {val, val, -val, -val};
        for(int i = 0; i < 4; ++i) 
            core.update(dx[i], dy[i], v[i]);
    }
    T query(int x0,int y0,int x1,int y1) 
	{
        T ret = 0;
        int dx[4] = {x0 - 1, x1, x0 - 1, x1};
        int dy[4] = {y0 - 1, y1, y1, y0 - 1};
        int v[4] = {1, 1, -1, -1};
        for(int i = 0; i < 4; ++i) 
            ret += v[i] * core.query(dx[i], dy[i]);
        return ret;
    }
};
BIT_2D<int> bit; //�˴��޸ı������������ 

//ʹ������ 
int op;
int x[2], y[2], v;
int main() 
{
	scanf("%d%d",&n,&m);  //��ά�ռ��С 
    while(scanf("%d",&op)!=EOF) 
	{
        scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);
        if(op==1)  //�����ѯ��� 
			printf("%d\n",bit.query(x[0], y[0], x[1], y[1]));
		else    	
		{   //�����޸�ֵ 
			scanf("%d",&v);
            bit.update(x[0], y[0], x[1], y[1], v);
        }
    }
    return 0;
}
