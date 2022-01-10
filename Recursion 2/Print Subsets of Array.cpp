/*
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Constraints :
1 <= n <= 15
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/

#include <iostream>
using namespace std;

void printSubsetsOfArray_helper(int input[],int size,int output[],int m){
    if(input[0]=='\0'){
        for(int i=0;i<m;i++)
            cout<<output[i]<<" ";
        cout<<endl;
        return;
    }
    int newoutput[1000],i;
    for( i=0;i<m;i++){
        newoutput[i]=output[i];
    }
    newoutput[i]=input[0];
    printSubsetsOfArray_helper(input+1,size-1,newoutput,m+1);
    printSubsetsOfArray_helper(input+1,size-1,output,m);
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[1000];
    int m=0;
    printSubsetsOfArray_helper(input,size,output,m);  
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
