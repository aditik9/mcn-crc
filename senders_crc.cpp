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
    while(i<m)//-k+1
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
        crc[n]=rem[n];      //assigning the rem to crc
}

int main()
{
    int data[20],gx[20],rem[20]={-1},k,m;
    int codeword[20];

    cout<<"Enter the length of data :  ";
    cin>>m;
    cout<<"Enter the data"<<endl;
    for(int i=0;i<m;i++)
        cin>>data[i];

    cout<<endl<<"Enter the length of G(x) :  ";
    cin>>k;
    cout<<"Enter G(x) :  ";
    for(int i=0;i<k;i++)
        cin>>gx[i];

    for(int i=m;i<m+k-1;i++)       //updated data
        data[i]=0;

    if(data[0]==1)       //first iteration
    {
        for(int i=0;i<k;i++)
            rem[i]=Xor(data[i],gx[i]);
    }

    divide(data,gx,rem,m,k);

    cout<<endl<<"CRC code : ";    //displaying the CRC code
    for(int n=0;n<k-1;n++)
        cout<<crc[n];

    for(int i=0;i<m;i++)
        codeword[i]=data[i];
    for(int i=m,j=0;i<m+k-1;i++)
    {
        codeword[i]=crc[j];
        j++;
    }
    cout<<endl<<"Codeword = ";      //displaying codeword
    for(int i=0;i<m+k-1;i++)
        cout<<codeword[i];


    return 0;
}

