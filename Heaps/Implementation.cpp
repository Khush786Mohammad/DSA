#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0; 

    void insert(int val)
    {
        size = size + 1;
        int index = size;

        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;
            if(arr[parent] < arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
            return ;
        }
    }
    void print()
    {
        for(int i = 1 ; i<=size ; i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void deletefromHeap()
    {
        if(size == 0)
        return;

        arr[1] = arr[size];
        size = size-1;
        //propogate root node to its correct position
        int i = 1;
        while(i<=size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex <= size && arr[i] < arr[leftIndex])
            {
                swap(arr[i] , arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[i] < arr[rightIndex])
            {
                swap(arr[i] , arr[rightIndex]);
                i = rightIndex;
            }
            else
            return; 
        }
    }
};

void heapify(int arr[] , int size , int i)
    {
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left <= size && arr[largest] < arr[left])
        {
            largest = left;
        }
        if(right <= size && arr[largest] < arr[right])
        {
            largest = right;
        }
        if(largest != i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr , size , largest); 
        }
    }

void heapSort(int arr[] , int n)
{
    for(int i = n ; i>0 ; i--)
    {
        swap(arr[1] , arr[i]);
        heapify(arr,i-1,1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(60);
    h.insert(55);
    // h.print();
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(70);
    h.print();
    h.deletefromHeap();
    cout<<"\n";
    h.print();
    cout<<"\n";

    int arr[6] = {-1,54,53,55,52,50}; 
    int n = 5;
    for(int i = n/2 ; i>0 ; i--)
    {
        heapify(arr , n , i);
    }
    for(int i = 1 ; i<=n ; i++)
    {
        cout<<arr[i]<<" ";
    }

    heapSort(arr , n);

    cout<<"\nHeap Sort\n";
    for(int i = 1 ; i<=n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}