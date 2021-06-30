#include<bits/stdc++.h>
using namespace std;
    //4 Functions to printing purpose
    //x: Dimension along x axis
    //y: Dimension along y axis
    //Esize: Element size
void Printnumnodes(int x, int y, int Esize){

        cout<<"No of Nodes:  = "<<(1+x/Esize)*(1+y/Esize)<<endl<<endl;
}

void PrintNode_data(int x, int y, int Esize){
    int xn=1+x/Esize;
    int yn=1+y/Esize;
    cout<<"Node No"<<"\t"<<"X-coordinate"<<"\t"<<"Y-coordinate"<<endl;


    int currnode=0;
    for(int j=0;j<yn;j++)
    {
        for(int i=0;i<xn;i++)
        {
            cout<<currnode<<"\t"<<Esize*i<<"\t\t"<<Esize*j<<endl;
            currnode++;
        }
    }
    cout<<endl;
    cout<<endl;

}
void Printnumelement(int x, int y, int Esize){
    cout<<"No of Elements:  = "<<(x/Esize)*(y/Esize)<<endl<<endl;
}
void PrintElement_data(int x, int y, int Esize ){
    int xn=x/Esize;
    int yn=y/Esize;
    cout<<"Element No"<<"\t"<<"Node 1"<<"\t"<<"Node 2"<<"\t"<<"Node 3"<<"\t"<<"Node 4"<<endl;
    int curelement=0;
    int temp=0;
    for(int j=0;j<yn;j++)
    {
        temp=j*xn;
        for(int i=0;i<xn;i++)
        {
            int n1=i+temp+j;
            int n2=1+i+temp+j;
            int n3=2+i+j+xn+temp;
            int n4=1+i+j+xn+temp;
            cout<<curelement<<"\t\t"<<n1<<"\t"<<n2<<"\t"<<n3<<"\t"<<n4<<endl;
            curelement++;
        }
    }
}
int main()
{
    // int x, y, Esize;
    // cin>>x>>y>>Esize;
    int xdim=270, ydim=170, Esize=10;             // Roll Number : 16MI31022

    Printnumnodes(xdim, ydim, Esize);                //Printing number of nodes
    PrintNode_data(xdim, ydim, Esize);             //Printing Information about the nodes
    Printnumelement(xdim, ydim, Esize);            //Printing number of Element
    PrintElement_data(xdim, ydim, Esize);           //Printing Information about the elements and their connectivity

    return 0;
}
