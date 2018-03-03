//������������ 


// ��N���ֳɶ��������ͬ������
// dp(i,j)��ʾ����i�Ļ����У�ÿ��������������j�Ļ�����
int N,dp[MAXN][MAXN];
clr(dp,0);
for(int i = 1; i <= N; i++) 
    for(int j = 1; j <= N; j++) 
	{
        if(i < j) dp[i][j] = dp[i][i];
        else if(i > j) dp[i][j] = dp[i - j][j] + dp[i][j - 1];
        else dp[i][j] = dp[i][j - 1] + 1;
    }
int ans=dp[N][N];


// N���ֳ�K��������֮�͵Ļ�����Ŀ
// dp(i,j)��ʾ������i���ֳ�j��������
int N, K;
int dp[MAXN][MAXN];
clr(dp,0); 
dp[0][0] = 1;
for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++) 
	{
        if(i<j) dp[i][j] = 0;
        else if(i>j) dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
        else dp[i][j] = 1;
	}
int ans=dp[N][K];


// N���ֳ����ɸ���ͬ������֮�͵Ļ�����Ŀ
// dp(i,j)��ʾ������i����Ϊ������j�Ĳ�ͬ�����Ļ�����
clr(dp,0);
dp[0][0] = 1;
for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++) 
	{
        if(i<j) dp[i][j] = dp[i][i];
        else if(i>j) dp[i][j]=dp[i-j][j-1]+dp[i][j-1];
        else dp[i][j] = dp[i][j - 1] + 1;
    }
int ans=dp[N][N];


// N���ֳ����ɸ���������֮�͵Ļ�����Ŀ
// f(i,j)��ʾ������i����Ϊj������֮�͵Ļ�����
// g(i,j)��ʾ������i����Ϊj��ż��֮�͵Ļ�����
int g[MAXN][MAXN];
int f[MAXN][MAXN];
clr(g,0);clr(f,0);
f[0][0] = g[0][0] = 1;
for(int i = 1; i <= N; i++)
    for(int j = 1; j <= i; j++) 
	{
        g[i][j] = f[i - j][j];
        f[i][j] = f[i - 1][j - 1] + g[i - j][j];
    }
