/*   ��׺���� 

4���Ƚϻ�����Ӧ��

Q1��һ����������������󹫹�ǰ׺�Ƕ��٣� 
A1���ⲻ����Height����rmqԤ������O(1)��ѯ�� 
 
Q2��һ�����п��ص����ظ���Ӵ��Ƕ೤�� 
A2������������������׺�������ǰ׺��������������׺�������ǰ׺����Height 
	������ĳһ�ε���Сֵ������ľ���Height�е����ֵ�� 
 
Q3��һ�����ֲ����ص����ظ���Ӵ��Ƕ೤�� 
A3���ȶ��ִ𰸣�ת�����б�ʽ������ȽϺô������赱ǰ��Ҫ�б𳤶�Ϊk�Ƿ��
	��Ҫ��ֻ��������ĺ�׺�ֳ������飬����ÿ��ĺ�׺֮���Height ֵ����
	С��k�����ж�������û�в��ظ��ĺ�׺��������ǿ�����SAֵ����С��SAֵ��
	�������k����һ�鳬���Ļ�k���ǺϷ��𰸡� 
 
A4��һ���ַ�������ȵ��Ӵ��ĸ����Ƕ��٣� 
Q4��ÿ���Ӵ�һ����ĳ����׺��ǰ׺����ôԭ����ȼ��������к�׺֮��Ĳ���ͬ��
	ǰ׺�ĸ��������ҿ��Է���ÿһ����׺Suffix[SA[i]]�Ĺ�����Len - SA[i] + 1,
	�������Ӵ����ظ����ظ��ľ���Heigh[i]����ǰ����ͬ��ǰ׺����ô��ȥ�Ϳ���
	�ˡ����һ����׺Suffix[SA[i]]�Ĺ��׾���Len - SA[k] + 1 - Height[k]�� 
*/ 

const int MAXN = 100005;

char ch[MAXN], All[MAXN];
int SA[MAXN], rank[MAXN], Height[MAXN];
int tax[MAXN], tp[MAXN], a[MAXN], n, m; 
char str[MAXN];
//rank[i] ��i����׺������; 
//SA[i] ����Ϊi�ĺ�׺λ��; 
//Height[i] ����Ϊi�ĺ�׺������Ϊ(i-1)�ĺ�׺��LCP
//tax[i] ��������������; 
//tp[i] rank�ĸ�������(���������еĵڶ��ؼ���),��SA����һ����
//aΪԭ��
void RSort() 
{	//rank��һ�ؼ���,tp�ڶ��ؼ��֡�
    for (int i = 0; i <= m; i ++) tax[i] = 0;
    for (int i = 1; i <= n; i ++) tax[rank[tp[i]]] ++;
    for (int i = 1; i <= m; i ++) tax[i] += tax[i-1];
    for (int i = n; i >= 1; i --) SA[tax[rank[tp[i]]] --] = tp[i]; 
	//ȷ�������һ�ؼ��ֵ�ͬʱ��������ڶ��ؼ��ֵ�Ҫ��
} //��������,���µĶ�Ԫ������

int cmp(int *f, int x, int y, int w) 
{ return f[x] == f[y] && f[x + w] == f[y + w]; } 
//ͨ����Ԫ�������±�ıȽϣ�ȷ�������Ӵ��Ƿ���ͬ

void Suffix() //SA
{
    for (int i = 1; i <= n; i ++) rank[i] = a[i], tp[i] = i;
    m = 127 ,RSort(); //һ��ʼ���Ե����ַ�Ϊ��λ������(m = 127)

    for (int w = 1, p = 1, i; p < n; w += w, m = p) 
	{ //���Ӵ����ȷ���,����rank
        //w ��ǰһ���Ӵ��ĳ���; m ��ǰ��ɢ�������������
        //��ǰ��tp(�ڶ��ؼ���)��ֱ������һ�ε�SA�ĵõ�
        for (p = 0, i = n - w + 1; i <= n; i ++) tp[++ p] = i; 
		//����Խ��,�ڶ��ؼ���Ϊ0
        for (i = 1; i <= n; i ++) if (SA[i] > w) tp[++ p] = SA[i] - w;
        //����SAֵ,����tp��ʱ������һ�ֵ�rank(����cmp�Ƚ�)
        RSort(), swap(rank, tp), rank[SA[1]] = p = 1;
        //���Ѿ���ɵ�SA���������������rank,����ɢrank
        for (i = 2; i <= n; i ++) 
			rank[SA[i]] = cmp(tp, SA[i], SA[i - 1], w) ? p : ++ p;
    }
    //��ɢ������ȵ��ַ�����rank��Ϊ��ͬ��
    //LCP
    int j, k = 0;
    for(int i = 1; i <= n; Height[rank[i ++]] = k) 
        for( k=k?k-1:k,j=SA[rank[i]-1];a[i+k]==a[j+k];++k);
    //���֪��ԭ���ͱȽϺ�������
}
void Init() 
{
    scanf("%s", str);
    n = strlen(str);
    for (int i = 0; i < n; i ++) a[i + 1] = str[i];
}
int main() 
{
    Init(); //����ԭ�� 
    Suffix(); //�����׺���� ,���SA��Height��Rank 
    //for(int i=0;i<=n;i++) printf("%d ",SA[i]); printf("\n"); 
    //for(int i=0;i<=n;i++) printf("%d ",rank[i]); printf("\n"); 
    //for(int i=0;i<=n;i++) printf("%d ",Height[i]); printf("\n"); 
}
