#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<float> Cc;  // for storing Capital Cost
vector<float> Oc;  // for storing Operating Cost
vector<float> R;   // for storing Revenue
vector<int> id;    // for storing time in year
vector<int> bt;    // for storing government decision of taking taxes
float d, t;        // for storing discount rate and Govt Taxes
int n=11;


vector<float> CashFlow(){

    // Utility function to calculate Cashflow
    //it will used in calculating in NPV and IRR
    vector<float> GP;
    vector<float> NP;
    vector<float> CF;
    float gp, np, cf;
    for(int i=0; i<n;i++){
        gp= R[i]-Oc[i];
        GP.push_back(gp);

        if(bt[i]==1){
            if(GP[i]>0){
                np=GP[i]*(1-t);
                NP.push_back(np);

            }
            else{
                np=GP[i];
                NP.push_back(np);
            }
        }
        else{
            np=GP[i];
            NP.push_back(np);
        }

        cf= NP[i]-Cc[i];
        CF.push_back(cf);
    }
    return CF;
}
float NPV (vector<float> CF){
    //will return NPV Value
    // Takes Cashflows as input
    float res=0;
    float npv;
    for(int i=0; i< n; i++){
        npv= CF[i]/(pow((1+d), i));
        res+=npv;
    }
    // Calculated NPV and stored it in variable res
    return res;
}
float Fx(vector<float> CF, float x){
    // utility function to calculate function value
    float fx=0.0;
    for(int i=0; i< n; i++){
        fx+=CF[i]*(pow(x, i));

    }
    return fx;
}
float dFx(vector<float> CF, float x){
    //utility function to calculate derivate of function
    float dfx=0.0;
    for(int i=n-1; i>0; i--){
        dfx+=i*CF[i]*(pow(x, i-1));
    }
    return dfx;
}
float IRR(vector<float>CF){
    //Will return IRR
    //Input is CashFLow
    float xn= 1/(1+0.15);      // x= 1/(1+r) Assuming Initial IRR to 15%
    float error = 0.001;
    float xn1;
    for(int i=0; i<500; i++){
        xn1=xn-(Fx(CF, xn)/dFx(CF, xn));
        if(abs(xn1-xn)<error){
            break;

        }
        xn=xn1;
    }
    float irr= (1/xn1)-1;
    return irr;




}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin>>n>>d>>t;
    d=d/100;
    t=t/100;

    int ID, cc, oc, r, BT;
    for(int i=0; i< n; i++){
        cin>>ID;
        id.push_back(ID);
        cin>>cc;
        Cc.push_back(cc);
        cin>>oc;
        Oc.push_back(oc);
        cin>>r;
        R.push_back(r);
        cin>>BT;
        bt.push_back(BT);
        }

    vector<float> CF;
    CF= CashFlow();           // Cashflows
    cout<<NPV(CF)<<" ";       // NPV for project
    cout<<IRR(CF);            // IRR for a project

}
