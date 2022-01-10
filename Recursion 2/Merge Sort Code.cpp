/****
Sort an array A using Merge Sort.
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
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
********/
#include <iostream>
using namespace std;


void merge(int input[],int size,int mid){
    int array[size];
    int i,j,k;
    for(i=0,j=mid,k=0;i<mid&&j<size;k++){
        if(input[i]<input[j]){
            array[k]=input[i];
            i++;
        }
        else{
            array[k]=input[j];
            j++;
        }
    }
    if(i<mid){
        for(;i<mid;i++,k++){
            array[k]=input[i];
        }
    }

    if(j<size){
        for(;j<size;j++,k++){
            array[k]=input[j];
        }
    }
    for(int i=0;i<size;i++){
        input[i]=array[i];
    }
    return;
}

void mergeSort(int input[], int size){
	// Write your code here
    if(size==0||size==1){
        return;
    }
    
    int mid=size/2;
    mergeSort(input,mid);
    mergeSort(input+mid,size-mid);
    
    merge(input,size,mid);
    return;
    
}


int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}