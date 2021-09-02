#include <iostream>
#include <vector>

int n;
int Search(int key,int *p)
{
    for (int i=0;i<n;i++)
    {
        if (*(p+i)==key)
        {
            return i;
        }
    }
    return -1;
}
void Insert(int index,int element,int *p)
{
    int temp,temp2;
    for (int i=0;i<n;i++)
    {
        if (i==index)
        {
            temp=*(p+i);
            
            *(p+i)=element;
        }
        else if (i>index)
        {
            temp2=*(p+i);
            *(p+i)=temp;
            temp=temp2;
            
        }

    }

}
void Delete(int index, int *p)
{
    for (int i=0;i<n-1;i++)
    {
        if (i==index)
        {
            *(p+i)=*(p+i+1);
        }
    }
}
int main()
{
    
    std::cout<<"enter the size of the array : ";
    std::cin>>n;
    int array[n];    
    for (int i=0;i<n;i++)
    {
        std::cout<<" Enter element "<< i+1<<" :"; 
        std::cin>>array[i];
    }
    
    
    int choice=0;
    while (1)
    {
        std::cout<<"\n 1-Search \n 2-Insert \n 3-Delete --->";
        std::cin>>choice;
        switch (choice)
        {
            case 1:
                int key;
                std::cout<<"\nEnter the value of element :";
                std::cin>>key;
                std::cout<<"The index of the element "<<key<<" is "<<Search(key,array)<<std::endl;
                break;
            case 2:
                int index;
                std::cout<<"Enter the value of element :";
                std::cin>>key;
                std::cout<<"Enter the index of element :";
                std::cin>>index;
                n+=1;
                Insert(index,key,array);
                for (int i=0;i<n;i++)
                    std::cout<<array[i]<<" ,";
            case 3:
                std::cout<<"Enter the index you want to delete :";
                std::cin>>index;
                
                Delete(index,array);
                n--;
                for (int i=0;i<n;i++)
                    std::cout<<array[i]<<" ,";
                break;
            default:
                break;
        } 
        if (choice==0)
        {
            break; 
        }
          
    }
    
}