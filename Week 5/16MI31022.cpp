#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
float cheap(float price){
    if(price<=8000)
        return 1.0;
    else if(price>8000 && price<=35000)
        return (35000-price)/(35000-8000);
    else
        return 0.0;
}
float medium(float price){
    if(price<=8000)
        return 0.0;
    else if(price>8000 && price<=21500)
        return (price-8000)/(21500-8000);
    else if(price>21500 && price <=35000)
        return (35000-price)/(35000-21500);
    else
        return 0.0;
}
float expensive(float price){
    if(price<=8000)
        return 0.0;
    else if(price>8000 && price<=35000)
        return (price-8000)/(35000-8000);
    else
        return 1.0;
}

vector<float> mat(float x){
    vector<float> mat;
    mat.push_back(cheap(x));
    mat.push_back(medium(x));
    mat.push_back(expensive(x));
    return mat;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    float A, B, C;
    cin>>A>>B>>C;
    
    vector<vector<float> > R3;
    vector<float> M1= mat(A);
    R3.push_back(M1);
    vector<float> M2= mat(B);
    R3.push_back(M2);
    vector<float> M3= mat(C);
    R3.push_back(M3);
    
//     for(int i=0; i<3; i++){
//         for(int j=0; j< 3; j++){
//             cout<<R3[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
  
    float R1[3][3]={{0.62,0.32,0.33},{0.36,0.82,0.35},{0.18,0.31,0.76}};
    float R2[3][3]={{0.12,0.31,1.0},{0.22,0.61,0.56},{0.82,0.45,0.43}}; 
    float R4[3][3];
    float R5[3][3];
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            float x1,x2,x3;
            x1=R3[i][0];
            x2=R3[i][1];
            x3=R3[i][2];
            float y1,y2,y3;
            y1=R1[0][j];
            y2=R1[1][j];
            y3=R1[2][j];
            float x,y,z;
            x=min(x1,y1);
            y=min(x2,y2);
            z=min(x3,y3);
            R4[i][j]=max(x,max(y,z));
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            float x1,x2,x3;
            x1=R4[i][0];
            x2=R4[i][1];
            x3=R4[i][2];
            float y1,y2,y3;
            y1=R2[0][j];
            y2=R2[1][j];
            y3=R2[2][j];
            float x,y,z;
            x=min(x1,y1);
            y=min(x2,y2);
            z=min(x3,y3);
            R5[i][j]=max(x,max(y,z));
        }
    }

    if(R5[0][0] >R5[1][0] && R5[0][0]>R5[2][0])
    {
        cout<<"A"<<endl;
        return 0;
    }
  else  if(R5[1][0]>R5[2][0] && R5[1][0]>R5[0][0])
  {
      cout<<"B"<<endl;
      return 0;
    }
    else
    {
        cout<<"C"<<endl;
        return 0;
    }
    
    
    
    return 0;
}