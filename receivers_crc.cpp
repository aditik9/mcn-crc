#include<iostream>
using namespace std;
int Xor(int a,int b)
{
    if(a==b)
        return 0;
    else
        return 1;
}

int divide(int dividend[],int divisor[],int rem[], int m, int k)
{
    int temp[20],i=0,chk=0;
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
    for(int n=0;n<k;n++)
        if(rem[n]==0)
            chk++;
    return chk;
}

int main()
{
    int codeword[20],gx[20],rem[20]={-1},k,m;

    cout<<"Enter the length of codeword :  ";
    cin>>m;
    cout<<"Enter the codeword"<<endl;
    for(int i=0;i<m;i++)
        cin>>codeword[i];

    cout<<endl<<"Enter the length of G(x) :  ";
    cin>>k;
    cout<<"Enter the G(x) :  ";
    for(int i=0;i<k;i++)
        cin>>gx[i];

    if(codeword[0]==1)       //first iteration
    {
        for(int i=0;i<k;i++)
            rem[i]=Xor(codeword[i],gx[i]);
    }
    cout<<endl;

    int x=divide(codeword,gx,rem,m,k);

    if(x==k)
    {
        cout<<"No error present"<<endl;
        cout<<"The actual data is : ";
        for(int n=0;n<m-k+1;n++)
            cout<<codeword[n]<<" ";
    }
    else
        cout<<"The received codeword contains an error! Retransmission required"<<endl;

    return 0;
}
