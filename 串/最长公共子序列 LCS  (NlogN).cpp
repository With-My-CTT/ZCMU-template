//�����������   LCS  
//ʱ�临�Ӷ� ��O(nlogn) 
/*˼·�� 
	a,BΪ�������У�lis��¼a��Ԫ����b�е�λ�ã�d[i]Ϊ����i���������������
һ��Ԫ�ص�ֵ��pos[i][j]��¼a��ֵΪi��Ԫ����b�г��ֵĵ�j��λ�õ����
	���lis[i]����Ŀǰ������е����һ��Ԫ�أ���lia[i]���ڸ����к�ߣ����ɳ�
��+1������У�ͬʱ����d[]��ֵ.�����ҵ�d[]�е�һ������lis[i]��λ��k����lis[i]
���ڳ���Ϊk-1�����к�ߣ�����Ϊ����Ϊk�����У���˸���d[k]��ֵΪlis[i]*/

char s1[MAXN],s2[MAXN];//ԭʼ�ַ��� 
int a[MAXN], b[MAXN];//ԭʼ����(��1��ʼ) 

int B, lis[MAXN*20],d[MAXN*20];
vector<int> pos[MAXN];
int LCS(int len_a,int len_b)
{
	
	int len_lis = 1;
    for (int i = 0; i <= len_a; i++)
        for (int k = pos[a[i]+5000].size() - 1; k >= 0; k--)
            lis[len_lis++] = pos[a[i]+5000][k];

    d[1] = lis[1];
    int max_len_lcs = 1;

    for (int i = 2; i <= len_lis; i++)
	{
        if (lis[i] > d[max_len_lcs])
            d[++max_len_lcs] = lis[i];
        else {
            int pos_greater_than_lis_i = lower_bound(d, d + max_len_lcs, lis[i]) - d;
            d[pos_greater_than_lis_i] = lis[i];
        }
    }
    return max_len_lcs;
}
int LCS_num(int len_a,int len_b)  //�������� 
{
	for(int i=0;i<MAXN;i++) pos[i].clear();
    for (int i = 1; i <= len_b; i++)
	{
        B=b[i];
        pos[B+5000].push_back(i);
    }
	return LCS(len_a,len_b);
}
int LCS_char(int len_a,int len_b)  //�����ַ��� 
{
	for(int i=0;i<MAXN;i++) pos[i].clear();
	for(int i=1;i<=len_a;i++) a[i]=s1[i-1];
	for(int i=1;i<=len_b;i++) 
	{
		B=s2[i-1];
		pos[B+5000].push_back(i);
	}
	return  LCS(len_a,len_b);
}

