//������
//������ x �� y �� �� mod ȡģ 
LL Qpow(LL x,LL y,LL mod)
{
    LL res=1;
    x=x%mod;
    while(y>0)
    {
        if(y&1)
        res=(res*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return res;
}



