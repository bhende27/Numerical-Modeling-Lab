#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin>>n;
    //Reading discount rate(d) and Govt taxes(t)
    float d, t;
    cin>>d>>t;
    d=d/100;
    t=t/100;
    vector<float> Cc;
    vector<float> Oc;
    vector<float> R;
    vector<int> id;
    vector<int> bt;
    //Reading Capital Cost in vector: Cc
    //Reading Operating cost Cost in vector: Oc
    //Reading Revenue in vector: R
    //Reading time in year in vector: id
    //Reading Govt tax applicable or not for  x year  in vector: bt

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


    vector<float> GP;
    vector<float> NP;
    vector<float> CF;
    // Calculated Gross Profit in vector GP
    // Calculated Net Profit in vector NP
    // Calculated Cash Flow in vector CF
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
    float NPV=0;
    float npv;
    for(int i=0; i< n; i++){
        npv= CF[i]/(pow((1+d), i));
        NPV+=npv;
    }
    // Calculated NPV and stored it in variable NPV
    cout<<int(NPV);

}
