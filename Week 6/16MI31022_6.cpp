#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int func(int x, int y){
    // for getting actual position of data point

    return y-2*x-1;
}
vector<pair<pair<int, int>, int> >  tdata;

float model(float w1, float w2, int x, int y){
    // Our neural network model
    int b=1;
    return w1*x+w2*y+b;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(int i=0; i< 50; i++){
        int x= rand()%10;
        int y= rand()%10;

        if(func(x, y)>=0){
            tdata.push_back({{x, y}, 1});
        }
        else{
            tdata.push_back({{x, y}, -1});
        }


    } // generated the data points for model training and stored in vector tdata

    int itrr=100;
    float w1=-2.0;
    float w2=1.0;
    // initialized the hyperparameters  and the wights of our neural network
    for(int i=0; i< itrr; i++){
        int xt= tdata[i].first.first;
        int yt= tdata[i].first.second;

        int s = model(w1, w2, xt, yt);

        int yp;
        if(s>=0)
            yp=1;
        else
            yp=-1;

        int ya= tdata[i].second;

        int error= abs(ya-yp);

        w1=w1-0.001*error*xt;     //performing gradient descent  for backpropagation
        w2=w2-0.001*error*yt;
    }
    int X, Y;
    cin>>X>>Y;
    float z = model(w1, w2, X, Y);
    if(z>=0){
        cout<<"ABOVE"<<endl;
    }
    else{
        cout<<"BELOW"<<endl;
    }

    return 0;
}
