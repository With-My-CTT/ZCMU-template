//����������� 
//ʱ�临�Ӷ� O(n^2)
//���������� a��b ���䳤�� n , m 

int dp[MAXN][MAXN];
int a[MAXN],b[MAXN];
int n,m; 
int LCS(int n,int m) 
{  
    for (int i = 0; i <= n; i++) 
	{  
        for( int j = 0; j <= m; j++) 
		{  
            if(i == 0 || j == 0) dp[i][j] = 0;  
			else if (a[i-1] == b[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;  
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);  
        }  
    }  
    return dp[n][m];  
}  




