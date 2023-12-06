#include <iostream>

using namespace std;

int partition(int *arr,int s,int e){
    //step1. choose pivot element  
    int pivotindex=s;
    int pivotelement=arr[s];
    // step2. find right position for pivot element and place it there  

    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivotelement){
            count++;
        }
    }


    // jab loop se bahar aya 
    int rightindex=s+count;
    swap(arr[pivotindex],arr[rightindex]);
    pivotindex=rightindex;
     // step3. left me chhote and right me bade  
     int i=s;
     int j=e;
     while(i<pivotindex&&j>pivotindex){
        while(arr[i]<=pivotelement){
            i++;
        }while(arr[j]>pivotelement){
            j--;
        }

        if(i<pivotindex&&j>pivotindex){
            swap(arr[i],arr[j]);
        }
     }

     return pivotindex;
}
void quicksort(int *arr,int s,int e){
  // base case 
  if(s>=e){
    return ;
  }

  //a. partition logic ,return pivot index
 int p= partition(arr,s,e);

  //b.rec logic  
  // left  
  quicksort(arr,s,p-1);

  // right  
  quicksort(arr,p+1,e);
}
int main()
{
    int arr[]={8,1,3,4,20,50,30};
    int n=7;
    int s=0;
    int e=n-1;
    quicksort(arr,s,e);
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
     }
    return 0;
}
