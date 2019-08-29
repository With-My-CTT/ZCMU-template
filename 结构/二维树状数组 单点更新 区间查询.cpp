/*	��ά��״���� 	������� �����ѯ 
	ʱ�临�Ӷ�: �����޸� logN*logM  �����ѯ logN*logM 
 	1��	�����±�һ��Ҫ��1��ʼ!!!!!!!!! 
 	2��	ע��Sum�� c ��Ҫ��ʱ����long long 
	3�� ���������ʱ���Ӷȣ�n*m*logn*logm 
*/
const int maxn = 3000;  
int Bit[maxn][maxn]; 
int Row, Col;  
inline int Lowbit(const int &x)
{ return x&(-x); } // x > 0 
void Init()
{
	//Row = ?  Col = ?  //���䷶Χ
	memset(Bit,0,sizeof(Bit)); 
 } 
int Sum(int i,int j)
{   
    int tempj, sum = 0;  
    while( i > 0 )
	{  
        tempj= j;  
        while( tempj > 0 )
		{  
            sum += Bit[i][tempj];  
            tempj -= Lowbit(tempj);  
        }  
        i -= Lowbit(i);  
    }  
    return sum;  
}  
void Update(int i, int j, int num)
{   //������� 
    int tempj;  
    while( i <= Row )
	{  
        tempj = j;  
        while( tempj <= Col )
		{  
        	Bit[i][tempj] += num;  
        	tempj += Lowbit(tempj);  
        }  
        i += Lowbit(i);  
    }  
}  
//������� 
int Query(int x1,int y1,int x2,int y2)
{ return Sum(x2,y2)-Sum(x1-1,y2)-Sum(x2,y1-1)+Sum(x1-1,y1-1);  } 
