/**
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
**/

#include<iostream>
using namespace std;

/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/

int partition(int input[],int start,int end){
    int pivot=input[start],smallCount=0;
    
    for(int i=start+1;i<=end;i++){
        if(input[i]<=pivot){
            smallCount++;
        }
    }
    int temp=input[smallCount+start];
    input[smallCount+start]=pivot;
    input[start]=temp;
    
    int i=start,j=end;
    
    for(;i<j;){
        if(input[i]>pivot&&input[j]<=pivot){
            int temp1=input[i];
            input[i]=input[j];
            input[j]=temp1;
            i++;
            j--;
           
        }
        if(input[j]>pivot){
            j--;
        }
        if(input[i]<=pivot){
             i++;
        }
    }
    return smallCount+start;
}

    void quickSort1(int input[], int start, int end)
	{
    		// your code goes here 
        if(start>=end){
        return ;
       }
    
    int c=partition(input,start,end);
    
    
    quickSort1(input,start,c-1);
    quickSort1(input,c+1,end);
     return;
        
	}
	void quickSort(int input[], int size)
	{
    		quickSort1(input, 0, size - 1);
        return;
	}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


