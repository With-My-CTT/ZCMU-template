//����Ӷκ�
//ʱ�临�Ӷȣ�O(n)
//���أ� ����Ӷκ�res 
//�Ӷ�����յ�λ�� start end (ͬ�����ȡ�ϳ���ǰ����)
int start,end;
int maxsub(int n,int a[])
{
	int sum,res=-INF, k=0;
	start=end=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum>res)
			res=sum,start=k,end=i;
		if(sum<0)
			sum=0,k=i+1;
	}
	return res;
} 





