//���Լ������С������ 

//�⺯��  
__gcd(a,b) 

//���� A * B = gcd(a,b) * lcm(a,b)
//����֮�����������Լ������С������֮��  

//���Լ��  շת����� 
int GCD( int A, int B)
{
    int temp;
    while( B!= 0 )
    {
        temp=B;
        B=A%B;
        A=temp;
    }
    return A;
}  
