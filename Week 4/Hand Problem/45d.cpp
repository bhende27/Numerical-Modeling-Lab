#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int H[5]={1, 2, 3, 4, 5};
int rows= 6;
int columns= 9;
//Given data of grades in grid 
int grades[][9]={{44,-1,40,42,40,39,37,36,-1}, {42,-1,43,42,39,39,41,40,36}, {37,37,37,35,38,37,37,33,34}, {35,38,-1,35,37,36,36,35,-1}, {36,35,36,35,39,33,32,29,28}, {38,37,35,-1,30,-1,29,30,32}};

pair<float, float> semivar(int h){
    //utility function which will give N(h) and Sigma part of farmula
    //takes h=H/100 distance between two points
    float temp, sum=0.0;
    int pairs=0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            float g1= grades[i][j];
            int k1= i+h;
            int k2= j+h;
            if(k1<rows && k2<columns){
                int g2= grades[k1][k2];
                if(g1==-1 || g2==-1){
                    continue;
                }
                temp=(g2-g1)*(g2-g1);
                sum+=temp;
                pairs++;
            }
            
        }
    }
    pair<float, float> res= {pairs, sum};
    return res;
}

int main() {
    int h;
    cin>>h;
    h=h/100;
    // pair<float, float> param= semivar(h);
    // float ans= param.second/(2*param.first);  //calculating as per the farmula
    // cout<<int(ans);                 //returning the integer part
    vector<float> S;
    for(int i=0; i<5; i++){
        pair<float, float> param= semivar(H[i]);
        float ans= param.second/(2*param.first);
        S.push_back(ans);
        cout<<ans<<" ";
    }
    return 0;
}
