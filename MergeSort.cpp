#include <iostream>
const int n=8;
int arr[]={8,1,2,3,6,5,4,7};
void MergeSort(int arr[],int l,int r)
{
    if (l>=r)
    {
        return;
    }
    int m=l+(r-1)/2;
    MergeSort(arr,l,m);
    MergeSort(arr,m+1,r);
    int larr[m-l+1],rarr[r-m];
    for (int i=0;i<m-l+1;i++)
        larr[i]=arr[l+i];
    for (int i=0;i<r-m;i++)
        rarr[i]=arr[m+1+i];
    int i=0,j=0,k=l;
    while (i<m-l+1 && j<r-m)
    {
        if (larr[i]<=rarr[j])
        {
            arr[k]=larr[i];
            i++;
        }
        else
        {
            arr[k]=rarr[j];
            j++;
        }
        k++;
    }
    while (i<m-l+1)
    {
        arr[k]=rarr[j];
        i++;
        k++;
        
    }
    while (j<r-m)
    {
        arr[k]=rarr[j];
        j++;
        k++;
    }
        
}
int main()
{

    MergeSort(arr,0,7);
    for (int i=0;i<7;i++)
    {
        std::cout<<arr[i];
    }
    
}