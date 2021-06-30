#include <bits/stdc++.h>
using namespace std;

double f(double r,vector<double>cashs)
{
	int i;int s=0;
	for(i=0;i<11;i++)
	{
	   s=s+cashs[i]/pow((1+r),i);	
	}
	return s;
}
double f_dash(double r,vector<double>cashs)
{
	int i;int s=0;
	for(i=1;i<11;i++)
	{
	   s=s-(i*cashs[i]/pow((1+r),i+1));	
	}
	return s;
}

double rate_of_return(vector<double>cashs)
{
	double r0=0.05;double ri;
	int i;
	for(i=0;;i++)
	{
		ri=r0-(f(r0,cashs))/f_dash(r0,cashs);
		if((ri-r0)<=0.1)
		{
			break;
		}
		r0=ri;
	}
	return ri;
}

int main() {
	double n,d1,t;
    n=11.0;
    d1=12.7;
    t=33.8;
    double f=(1+(d1/100));
    
    double b[11]={150	,65,	0,	0,	0,	0,	0,	0,	0,	0,	0
};
    double c[11]={0,	0,	35,	30,	18,	33,	36,	37,	38,	34,	35

};
double d[11]={0,	0,	79,	65,	109,	62,	76,	85,	88,	63,	94
};
    double e[11]={0,	0,	1,	1,	0,	1,	1,	0,	0,	1,	0
};
    
    
    for(int i=0;i<n;i++)
	
	{
		cout<<b[i]<<"  ";
	}
	
int i;
double npv=0.0;
vector<double>cashs;
for(i=0;i<n;i++)
    {
        //double a,b,c,d,e;
        //cin>>a>>b>>c>>d>>e;
        double g=d[i]-c[i];
        if(g>0 && e[i]==1)
        {
            g=g*(1-(t/100));
}
        double cash=g-b[i];
        cashs.push_back(cash);
        //cout<<"Cash  "<<cash<<endl;
        //cout<<1+d<<endl;
        double x=pow(f,i);
           // cout<<"X   "<<x<<endl;
        double disc=(cash)/x;
         //cout<<"Disc   "<<disc<<endl;
        npv+=disc;
        //cout<<"Npv  "<<npv<<endl;
}
double irr=rate_of_return(cashs);
cout<<"IRR   "<<irr*100<<endl;
    cout<<(int)npv<<endl;
return 0;
}
