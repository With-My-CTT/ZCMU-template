//���������������
//ʱ�临�Ӷȣ� O(n^2)
/* ��һά�洢 f[i]��ʾ b ������ j ��β���� a[]���鹹��
����������������С� ������ d ������ j λ�� ��ö�� 
a[1 ~n1]����a[i] == b[j] ʱ �� ��1 ~ j - 1�� �ҳ� b[k] 
С�� a[ i ] ���� d[k] ��ֵ��� �� a[ i ] > b [j ] ʱ��
 ��0��j-1�У�����С��a[i]�ģ�����fֵ�����Ž� ������С��
 a [ i ] ���� d[k]ֵ����ֵ���ڵ�λ�ã���*/ 
 
int a[MAXN], b[MAXN], d[MAXN];
int LCIS(int n1,int n2)
{
	memset(d, 0, sizeof(d));
    for(int i = 0; i < n1; i++)
    {
        int k = 0;
        for(int j = 0; j < n2; j++)
        {
            if(a[i] == b[j])
                d[j] = max(d[j], d[k] + 1);
            else if(a[i] > b[j])
                if(d[k] < d[j]) k = j;
        }
    }
    int mx = 0;
    for(int i = 0; i < n2; i++)
        mx = max(mx, d[i]);
    return mx;
}

