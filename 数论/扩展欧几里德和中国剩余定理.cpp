//��չŷ�����
//���ڲ���ȫΪ 0 �ķǸ����� a��b��
//��Ȼ���������� x��y ��ʹ�� gcd��a��b��=ax+by��
//x ���� a ���� b �ĳ˷���Ԫ��a * x % b = 1 
int e_gcd(int a,int b,int &x,int &y)
{
    if (b==0)
	{
        x=1,y=0;
        return a;
    }
    int res=e_gcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}

//����С����
//����p����������a��p���ʣ���ôa^(p-1) = 1 (mod p);
//�����ʽ��ת��Ϊ : a * a^(p-2) = 1 (mod p)
//����a^(p-2) �� a ���� p �� �˷���Ԫ 


//����չŷ����½���й�ʣ�ඨ��
/*	�й�ʣ�ඨ��
	X % Bi = Ai,����С��δ֪��X 
*/

int solve(int a[],int b[],int n)
{
	int sum=0,s=1,x,y;
	for(int i=0;i<n;i++) s*=a[i];
	for(int i=0;i<n;i++)
	{
		m=s/a[i];
		e_gcd(m,a[i],x,y);
		x=(x%a[i]+a[i])%a[i];
		sum=(sum+m*b[i]*x%s)%s;
	}
	return sum;
}

