//��˹��Ԫ
//������Է����� 

//��˹��Ԫ������򷽳��飬���ط��̽�ø�����  
const int N = 30;  
int A[N][N];//��ϵ����  
int Gauss(int equ,int var)
{//���ؽ�ø�����  
    int row,col;  
    for(row=0,col=0;row<equ&&col<var;col++,row++)
	{  
        int max_r=row;//Ĭ�����Ϊ����  
        for(int i=row+1;i<equ;i++)
		{//���ϵ����ҳ����ģ��˴�01����Ϊ1  
            if(A[row][col]==1)  break;  
            if(A[max_r][col]<A[i][col])
			{  max_r=i;break;  }  
        }  
        if(max_r!=row)
		{  
            for(int j=0;j<=var;j++)
				swap(A[max_r][j],A[row][j]);  
        }  
        if(A[row][col]==0) row--;//���²��ұ�����һ��   
        for(int i=row+1;i<equ;i++)
		{  
            if(A[i][col]==0)continue;//���ĳ����Ϊ0������������  
            for(int j=col;j<=var;j++)
                A[i][j]^=A[row][j];   
        }  
    }  
    for(int i=row;i<equ;i++)  
        if(A[i][col]!=0) return -1;  
    return 1<<(n-row);//���ܻ���long long  1LL<<(n-row)  
}  




//��˹��Ԫ������򷽳��飨ö�����н⣩  
const int N = 30;  
int n;  
int A[N][N];  
int Major[N];//��¼��Ԫ����λ��  
int x[N];//��ʱ�� x[]={0,1};  
  
void DFS_freevar(int n,int r,int var){//�ݹ�ö������Ԫ  
    if(var==-1){  
          
        //...����ÿһ������д���  
    }  
    if(var==Major[r]){//��ǰΪ��Ԫ  
        int y=A[r][n];  
        for(int i=var+1;i<n;i++){  
            y^=(A[r][i]*x[i]);  
        }  
        x[var]=y;  
        DFS_freevar(n,r-1, var-1) ;  
    }  
    else{//������Ԫö��  
        for(int i=0;i<2;i++){  
            x[var]=i;  
             DFS_freevar(n,r, var-1) ;  
        }  
    }  
    
}  
int Gauss(int equ,int var){//�����Ƿ��н�  
    int row,col;  
    for(row=0,col=0;col<var&&row<equ;col++,row++){  
        int max_r=row;  
        for(int i=row+1;i<equ;i++){  
            if(A[row][col]==1)break;  
            if(A[max_r][col]<A[i][col]){  
                max_r=i;break;  
            }  
        }  
        if(A[max_r][col]==0){  
            row--;  
            continue;  
        }  
        if(max_r!=row)  
            for(int j=0;j<=var;j++)  
                swap(A[row][j],A[max_r][j]);  
        for(int i=row+1;i<equ;i++){  
            if(A[i][col]==0)continue;  
            for(int j=col;j<=var;j++){  
                A[i][j]^=A[row][j];  
            }  
        }  
        Major[row]=col;  
    }  
    for(int i=row;i<equ;i++){//�޽�����  
        if(A[i][col]!=0)return -1;  
    }  
    DFS_freevar(n,row-1,col-1);  
    return 1;  
}  


//������ֻ��Ψһ��ʱ�ɼ���  
double A[N][N];  
double x[N];  
void Gauss(int equ,int var){  
    int row,col;  
    for(row=0,col=0;col<var&&row<equ;col++,row++){  
        int max_r=row;  
        for(int i=row+1;i<equ;i++){  
            if(eps<fabs(A[i][col])-fabs(A[max_r][col])){  
                max_r=i;  
            }  
        }  
        if(max_r!=row)  
            for(int j=0;j<var+1;j++)  
                swap(A[row][j],A[max_r][j]);  
        for(int i=row+1;i<equ;i++){  
            if(fabs(A[i][col])<eps)continue;  
            double tmp=-A[i][col]/A[row][col];  
            for(int j=col;j<var+1;j++){  
                A[i][j]+=tmp*A[row][j];  
            }  
        }  
         
    }  
       for(int i=var-1;i>=0;i--){//����Ψһ�⡣  
        double tmp=0;  
        for(int j=i+1;j<var;j++){  
            tmp+=A[i][j]*x[j];  
        }  
        x[i]=(A[i][var]-tmp)/A[i][i];  
    }  
}  
