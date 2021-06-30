#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
float a1, a2, a3, a4, a5, a6;
// Given 5 degree polynomial
float func(float x){
    
    float f = a1*(x*x*x*x*x)+a2*(x*x*x*x)+a3*(x*x*x)+a4*(x*x)+a5*(x)+a6;
    return f;
    
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    float a, b, n;
    cin>>a>>b>>n;
    
    
    float fa = func(a);                     // for f(x0)
    
    float f, del, fi, xi;
    f=0;
    del = 1.0*(b-a)/n;
    for(int i=1; i< n; i++){                // for f(x1)....... f(xn-1)
        xi=a+ 1.0*i*(del);
        fi= func(xi);
        f+=2.0*fi;   
    }
     
    float fb=  func(b);                     // for f(xn)
    
    int res= (1/2.0)*del*(fa+f+fb);                // farmula for trapeziodal                  
    cout<<res<<endl;
    return 0;
}