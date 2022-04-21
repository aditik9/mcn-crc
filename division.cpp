#include<iostream>
using namespace std;
int crc[10];
int Xor(int a,int b)
{
    if(a==b)
        return 0;
    else
        return 1;
}

void divide(int dividend[],int divisor[],int rem[], int m, int k)
{
    int temp[20],i=0;
    while(i<m-k+1)
    {
        for(int j=0;j<=k;j++)
            rem[j]=rem[j+1];    //removing the leftmost 0

        rem[k-1]=dividend[k+i];   //appending the next bit

        if(rem[0]==1)
        {
            for(int i=0;i<k;i++)
                temp[i]=Xor(rem[i],divisor[i]);
        }
        else
        {
            for(int i=0;i<k;i++)
                temp[i]=Xor(rem[i],0);
        }

        /*
        cout<<"rem : ";     //printing the remainder value at each iteration
        for(int i=0;i<k;i++)
            cout<<rem[i]<<" ";
        cout<<endl;
        */

        for(int j=0;j<k;j++)
            rem[j]=temp[j];
        i++;
    }
    for(int n=0;n<k-1;n++)
        crc[n]=rem[n];
}

int main()
{
    int dividend[20],divisor[20],rem[20]={-1},k,m;

    cout<<"Enter the length of dividend :  ";
    cin>>m;
    cout<<"Enter the dividend"<<endl;
    for(int i=0;i<m;i++)
        cin>>dividend[i];

    cout<<endl<<"Enter the length of divisor :  ";
    cin>>k;
    cout<<"Enter the divisor :  ";
    for(int i=0;i<k;i++)
        cin>>divisor[i];

    if(dividend[0]==1)       //first iteration
    {
        for(int i=0;i<k;i++)
            rem[i]=Xor(dividend[i],divisor[i]);
    }
    cout<<endl;

    divide(dividend,divisor,rem,m,k);

    cout<<"CRC code : ";    //displaying the CRC code
    for(int n=0;n<k-1;n++)
        cout<<crc[n];

    return 0;
}
