#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;







float Wp(float var[], float wp)
{
    // Function for wp for four A1, A2, A3,, A4 parameter
    //return value of pillar width
    //Var[] : array containing A1, A2,A3, A4;
    //wp: value of wp
    float fx=0.0;
    for(int i=0; i<4; i++)
        fx+= var[i]* pow(wp, 3-i);
    return fx;
}

float dWp(float var[], float wp){
    //return derivative of wp
    //Var[] : array containing A1, A2,A3, A4;
    //wp: value of wp
    return 3*var[0]*pow(wp,2)+2*var[1]*wp+ var[3];
}





float s(float len[], float sl[])
{
    // return constant sl for bienawski farmula
    //len[]: array containing pillar size
    //sl[]: array containing pillar strength
    float Y=0.0, X2= 0.0, X=0.0, XY=0.0;
    float a1,a2;
    for(int i=0; i<4; i++)
    {
        a2= log(sl[i]);
        a1= log(len[i]);

        Y+= a2;
        X2+= a1*a1;
        X+= a1;
        XY+= a1*a2;

    }
    float k= exp((Y*X2-X*XY)/(4*X2-pow(X, 2)));
    float minusA= (4*XY-X*Y)/(4*X2-pow(X, 2));

    float s1= k*pow(1000, minusA);
    return s1;
}
int main() {
    float fos;
    cin>>fos;






    float len[]= {25, 50,75,100};
    float sl[]= {18,10,7,6};
    float s1= s(len, sl);



    //Calulation of four constants for G(wp)
    float A1= 0.36*s1/3.0;
    float gamma= 2.6*1000*9.81/1000000.0;
    float A2= 0.64*s1-gamma*200.0*fos;
    float A3= -2.0*fos*gamma*200.0*4.5;
    float A4= -fos*gamma*200.0*4.5*4.5;


    // Performing Newtons Rapsons method for approximating wp
    float var[]= {A1, A2, A3, A4};
    float wp = 100.0;
    int i=1;
    while(i<=100)
    {
        float wpn= wp-Wp(var, wp)/dWp(var, wp);
        if(abs(wpn-wp)<0.01)
            break;
        wp= wpn;
        i++;
    }



    //Returning integer part of Wp
    cout<<(int)wp;

    return 0;
}
