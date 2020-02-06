#include<iostream>

using namespace std;

void print(int *arr,int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}

int* bubbleSort(int* arr,int size)
{
    for(int i=0;i<size-1;i++)
        for(int j=size-1;j>i;j--)
        {
            if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
        }
    for(int i=0;i<size;i++)
    return arr;
}

int partition(int* arr,int s,int t)
{
    int i=s,j=t;
    int tmp=arr[i];
    while(i<j)
    {
        while(j>i&&arr[j]>tmp) j--;
        arr[i]=arr[j];
        while(i<j&&arr[i]<tmp) i++;
        arr[j]=arr[i];
    }
    arr[i]=tmp;
    return i;
}

int* quickSort(int *arr,int s,int t)
{
    if(s<t)
    {
        int i=partition(arr,s,t);
        quickSort(arr,s,i-1);
        quickSort(arr,i+1,t);
    }
    return arr;
}

int main()
{
    int arr[]={12,2,33,0,1};
    int size=sizeof(arr)/sizeof(int);
    print(quickSort(arr,0,size-1),size);
}