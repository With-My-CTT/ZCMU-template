//�������� 

//01���� 
//ÿ����Ʒ����һ��������ѡ��Ż򲻷� 
int n,m,wei[MAXN],val[MAXN];
int dp[MAXN];
for(int i=0;i<n;i++)
	for(int j=m;j>=wei[i];j--)
		dp[j]=max(dp[j],dp[j-wei[i]]+val[i]); 
int ans=dp[m]; 
		
		
//��ȫ���� 
//��N��Ʒ������ΪW�ı���,ʹ��ֵ��� 
//ÿ����Ʒ���������Ƶ��ظ�ʹ�ã�����ѡ��Ż򲻷�
int n,W;
int dp[MAXN],val[MAXN],wei[MAXN];
clr(dp,0); 
for(int i =0 ; i < n ; i++)  
    for(int j = wei[i] ; j <= W ; j++)   
        dp[j] = max(dp[j],dp[j-wei[i]]+val[i]);
int ans=dp[W];
//��Ҫ������װ��������С����
clr(dp,INF);
for(int i =0 ; i < n ; i++)  
    for(int j = wei[i] ; j <= W ; j++)   
        dp[j] = min(dp[j],dp[j-wei[i]]+val[i]);
int ans=dp[W];


//���ر���(MultiplePack): ��N����Ʒ��һ������ΪV�ı�����  
//��i����Ʒ�����n[i]�����ã�ÿ��������c[i]����ֵ��w[i]��  
//��⽫��Щ��Ʒװ�뱳����ʹ��Щ��Ʒ�ķ����ܺͲ���������������  
//�Ҽ�ֵ�ܺ����  
int n,V;
int dp[MAXN],num[MAXN],val[MAXN],wei[MAXN];
for(int i = 0 ; i < n ; i++)  
    for(int k = 0 ; k < num[i] ; k++)  
        for(int j = V ; j >= val[i]; j--)  
            dp[j] = max(dp[j],dp[j-val[i]]+wei[i]);  
                        
                        
                        
                        
                        

