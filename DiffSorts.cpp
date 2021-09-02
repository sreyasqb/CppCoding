#include <iostream>
const int n=10;
int arr[]={6,9,7,8,1,3,2,5,4};
void BubbleSort()
{
    for(int i = 0; i<n; i++) 
    {
        int c = 0;   
        for(int j = 0; j<n-i-1; j++) 
        {
            if(arr[j] > arr[j+1]) 
            {       
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                c = 1;    
            }
        }
        if(!c)
            break;
    }
    std::cout<<"sorting using bubble sort gives :"<<std::endl;
    for (int i=0;i<n;i++)
        std::cout<<arr[i]<<",";
}
void InsertSort()
{  
    for (int i=1;i<n;i++) 
    {  
        int pos=arr[i];  
        int j =i-1;  
        while (j >-1 && arr[j]>pos) 
        {  
            arr[j+1]=arr[j];  
            j-=1;  
        }  
        arr[j+1]=pos;  
 
    }
    std::cout<<"sorting using insert sort gives :"<<std::endl;
    for (int i=0;i<n;i++)
        std::cout<<arr[i]<<",";

}
void SelectionSort()
{
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n-1;j++)
        {
            if (arr[i]>arr[j])
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    std::cout<<"sorting using selection sort gives :"<<std::endl;
    for (int i=0;i<n-1;i++)
        std::cout<<arr[i]<<",";
}

int main()
{
    int n;
    std::cout<<"1-Bubble,2-insert,3-Selection :";
    std::cin>>n;
    switch (n)
    {
        case 1:
            BubbleSort();
            break;
        case 2:
            InsertSort();
            break;
        case 3:
            SelectionSort();
            break;
        

    }
   
}