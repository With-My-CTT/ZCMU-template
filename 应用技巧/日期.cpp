//������ص��Զ��庯�� 

struct Time{  //���ڽṹ 
	int y,m,d;
	Time(int y,int m,int d):y(y),m(m),d(d){}  
	Time(int y,int m,int d) { }
}; 

int day_month[2][13]={   //ÿ���µ����� 
	{0,31,28,31,30,31,30,31,31,30, 31,30,31},  
	{0,31,29,31,30,31,30,31,31,30, 31,30,31}  
};   

bool leap(int y)   //�ж����� 
{ return ((y%4==0&&y%100!=0)||(y%400==0)); }

int Weekday(Time t)  //�������ڷ������ڼ�( 0-6��һ~�� ) 
{   
	int y=t.y,m=t.m,d=t.d;
	if(m==1||m==2) { m+=12;y--; }
	return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7; 
} 

int Cnt_day_of_year(Time t)
{   //����һ������, ����������ĵڼ���  
    int days=0;  
    bool k=leap(t.y);
    for (int i = 1;i < t.m;++i )  
        days += day_month[k][i];  
    days += t.d;  
    return days ;  
}  

int legal(Time t)  //�ж����ںϷ� 
{
	if (t.m<0||t.m>12) return 0;
	return t.d>0&&t.d<=day_month[leap(t.y)][t.m];
}

//��������������������
int  Cnt_day_between_Times(Time t1,Time t2)
{    
    int d1 = 0,d2 = 0;  
    bool k1=leap(t1.y),k2=leap(t2.y) ;  
    if ( t1.y == t2.y )  
    {  
        if (t1.m==t2.m) return t1.d-t2.d;  
        else
		{  
            d1=t1.d+day_month[k1][t2.m]-t2.d;  
            for (int i = t2.m+1 ; i <= t1.m-1;++i)  
                d1 += day_month[k1][i];  
            return d1;  
        }  
    }
	else
	{  
        d1 = t1.d;  
        for(int i = 1;i <= t1.m-1;i++)  
            d1 += day_month[k1][i];  
        d2 = day_month[k2][t2.m] - t2.d;  
        for (int i = 12;i >= t2.m+1;--i)  
            d2 += day_month[k2][i];  
        for (int y = t2.y+1;y <= t1.y-1;++y)  
            d2 += 365+leap(y); 
        return d1+d2;  
    }  
}  

//�������ĵڼ�������� 
Time Time_of_nTH_day(int year,int days)
{  
    Time t(year,1,1);  
    bool k = leap(year);  
    for ( int i = 1; i <= 12;++i )
	{  
        if( days <= day_month[k][i]) break;  
        t.m++;  
        days -= day_month[k][i];  
    }  
    t.d = days;  
	return t;  
}  
// ����һ������n��������  
Time next_Days_after_Time(Time t,int days)
{  
    Time ans(0,0,0);  
    int CntDay =  Cnt_day_of_year( t ); //����ĵڼ��� 
    int leave = 365+leap(t.y) - CntDay ;  
    if( days <= leave )
        ans = Time_of_nTH_day( t.y, CntDay + days );  
    else 
	{  
        days -= leave , t.y++;  
        while( days > days_Of_year[t.y] )  
            days -= days_Of_year[t.y] ,  t.y++;  
        ans = Time_of_nTH_day(t.y,days);  
    }  
    return ans;  
}  


