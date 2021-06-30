#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
float a1, a2, a3, a4, a5, a6;
// Given 5 degree polynomial
float func(float x, vector<float> arr){

    float f = arr[0]*(x*x*x)+arr[1]*(x*x)+arr[2]*(x)+arr[3];
    return f;


}
float actual(float a, float b, vector<float> arr){
    float ans=0.0;
    for(int i=0; i< arr.size(); i++){
        ans+= (arr[i]/(4-i))*pow(b,(4-i))- (arr[i]/(4-i))*pow(a, (4-i));

    }
    return ans;
}

vector<float> simson(float a, float b, vector<float>arr){
    vector<float> sims;
    for(int n=1; n<=100; n=n+2){

        float fa = func(a,arr);                      // for f(x0)

        float f, del, fi, xi;
        f=0;
        del = 1.0*(b-a)/n;
        for(int i=1; i< n; i++){
            xi=a+ 1.0*i*(del);
            fi= func(xi, arr);
            if(i%2==1){
                f+=4.0*fi;                      // for f(xj) where j is odd
            }
            else{
                f+=2.0*fi;                       // for f(xj) where j is even
            }

        }

        float fb=  func(b, arr);                       // for f(xn)

        float res= (1/3.0)*del*(fa+f+fb);

        sims.push_back(res);
        res=0.0;
    }
    return sims;

}

vector<float>  trapzoidal(float a, float b, vector<float >arr){
    vector<float>trap;
    for(int n=1; n<=100; n++){

        float fa = func(a, arr);                     // for f(x0)

        float f, del, fi, xi;
        f=0;
        del = 1.0*(b-a)/n;
        for(int i=1; i< n; i++){                // for f(x1)....... f(xn-1)
            xi=a+ 1.0*i*(del);
            fi= func(xi, arr);
            f+=2.0*fi;
        }

        float fb=  func(b, arr);                     // for f(xn)

    float res= (1/2.0)*del*(fa+f+fb);

    trap.push_back(res);
    res=0.0;
    }
    return trap;

}
vector<float> error(vector<float> arr, float act){
    vector<float> err;
    for(int i=1; i<=arr.size();i++){
        err.push_back(abs(act-arr[i-1]));

    }
    return err;

}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //cin>>a1>>a2>>a3>>a4>>a5>>a6;
    //float a, b, n;
    vector<float>arr;
    arr.push_back(7.0);
    arr.push_back(2.0);
    arr.push_back(22.0);
    arr.push_back(22.0);
    float a=5.0 , b=7.0;

    //cin>>a>>b>>n;
    float act= actual(a, b, arr);
    vector<float> sim= simson(a, b, arr);
    vector<float> simerr= error(sim, act);
    vector<float> trap= trapzoidal(a, b, arr);
    vector<float> traperr= error(trap, act);
    for(int i=1; i<=traperr.size(); i++){
        cout<<i<<"\n";
    }

    return 0;
}
