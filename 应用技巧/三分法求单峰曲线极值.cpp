//���ַ��󵥷庯����ֵ
//Y=a*X^2+b*X+c 
//��ĳ�� P(x,y) ���ö��κ������ߵ�������� 
const double mid=0.000001;
int a, b, c; // �������������� 
int x, y;  // �õ������ 
double left, right; // ���������� ����Ҫ��ֵ 
double calc(double x)
{ return a*x*x+b*x+c; } 
//��ȡ������yֵ
double dist(double dd)
{ return (dd-x)*(dd-x)+(calc(dd)-y)*(calc(dd)-y);} 
//��ȡ���������ϵĵ㵽����һ��ľ���
double Three_search()
{
	double mid, midmid;
    double mid_value, midmid_value;
    //left=?  right=?
    while(left+eps<right)
    {
        mid = (left+right)/2; mid_value=dist(mid);
        midmid=(mid+right)/2; midmid_value=dist(midmid);
        if(mid_value>=midmid_value )
        { left=mid; }//����ƽ�
		else
		{ right=midmid; }//����ƽ�
    }
    double ans=dist(left);
    //��ʱ��left��right�Ѿ��ƽ���ֵ������ͬ��
    ans = sqrt(ans);
    return ans;
}



