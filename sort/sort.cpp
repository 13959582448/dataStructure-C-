#include<iostream>
#include<vector>

using namespace std;

void print(vector<int> v)
{
    for(auto i:v)
        cout<<i<<" ";
}

vector<int>& bubbleSort(vector<int>& arr) //泡沫排序
{
    int size=arr.size();
    for(int i=0;i<size-1;i++)
    {
        for(int j=size-1;j>i;j--)
        {
            if(arr[j]<arr[j-1])
                {
                    int tmp=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=tmp;
                }
        }
    }
    return arr;
}

int partition(vector<int>& arr,int s,int t) //快速排序的一次划分
{
    int i=s,j=t;
    int tmp=arr[i];
    while(i<j)
    {
        while(i<j&&arr[j]>tmp) j--;
        arr[i]=arr[j];
        while(i<j&&arr[i]<tmp) i++;
        arr[j]=arr[i];
    }
    arr[i]=tmp;
    return i;
}

vector<int>& quickSort(vector<int>& arr,int s,int t) //快排
{
    if(s<t)
    {
        int i=partition(arr,s,t);
        quickSort(arr,s,i-1);
        quickSort(arr,i+1,t);
    }
    return arr;
}

vector<int>& selectionSort(vector<int>& arr) //选择排序
{
    int size=arr.size();
    int min,minIndex;
    for(int i=0;i<size-1;i++)
    {
        min=arr[i];
        minIndex=i;
        for(int j=i;j<size;j++)
        {
            if(arr[j]<min)
            {
                minIndex=j;
                min=arr[j];
            }
        }
        swap(arr[i],arr[minIndex]);
    }
    return arr;
}

vector<int>& insertionSort(vector<int>& arr) //插入排序
{
    int size=arr.size();
    for(int i=0;i<size-1;i++)
    {
        int preIndex=i,tmp=arr[i+1];
        while(preIndex>=0 && tmp<arr[preIndex])
        {
            arr[preIndex+1]=arr[preIndex];
            preIndex--;
        }
        arr[preIndex+1]=tmp;
    }
    return arr;
}

vector<int>& shellSort(vector<int>& arr) //希尔排序
{
    int size=arr.size();
    int gap=size/2;
    while(gap>0)
    {
        for(int i=gap;i<size;i++)
        {
            int preIndex=i-gap;
            int tmp=arr[i];
            while(preIndex>=0 && tmp<arr[preIndex])
            {
                arr[preIndex+gap]=arr[preIndex];
                preIndex-=gap;
            }
            arr[preIndex+gap]=tmp;
        }
        gap/=2;
    }
    return arr;
}

vector<int> merge(vector<int> left,vector<int> right) //合并两个数组
{
    vector<int> ans(left.size()+right.size());
    int size=ans.size();
    
    for(int i=0,j=0,index=0;index<size;index++)
    {
        if(i>=left.size()) ans[index]=right[j++];
        else if(j>=right.size()) ans[index]=left[i++];
        else if(left[i]<right[j]) ans[index]=left[i++];
        else ans[index]=right[j++];
    }
    return ans;
}

vector<int> mergeSort(vector<int>& arr) //归并排序
{
    if(arr.size()<2) return arr;
    int mid=arr.size()/2;
    auto it=arr.begin();
    for(int i=0;i<mid;i++) it++;
    //找到中间的点

    vector<int> left(arr.begin(),it);
    vector<int> right(it,arr.end());
    return merge(mergeSort(left),mergeSort(right));
}



int main()
{
    vector<int> arr({12,2,33,0,1,-3,122,6,-6});

    print(mergeSort(arr));

}