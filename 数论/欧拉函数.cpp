//ŷ������
//��1~(N-1)���ж��ٸ�����N���� 
//ʱ�临�Ӷȣ�sqrt(N) 
int eular(long long a)  
{
    long long tem=a;
    for(int i=2;i*i<=a;i++)
    {
    	if(a%i==0)  
        {  
            tem=tem/i*(i-1);//ŷ������  
            while(!(a%i)) a/=i;  
        }  
	} 
    if(a!=1) tem=tem/a*(a-1);  //a�����������  
    return tem;  
}



