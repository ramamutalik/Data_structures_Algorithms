/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 
Constraints :
1 <= n <= 20
Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output :
3 3
5 1
*/

#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n==0&&k==0){
        return 1;
    }
    else if(n==0){
        return 0;
    }
    int o1[10000][50],o2[10000][50];
    int smallAns1=subsetSumToK(input+1,n-1,o1,k);
    int smallAns2=subsetSumToK(input+1,n-1,o2,k-input[0]);
    
    int i,j;
     for(int i=0;i<smallAns1;i++){
        for(int j=0;j<=o1[i][0];j++){
            output[i][j]=o1[i][j];
        }
    }
    
    for( i=0;i<smallAns2;i++){
        for( j=1;j<=o2[i][0];j++){ 
        output[smallAns1+i][j+1]=o2[i][j];
        }
        output[smallAns1+i][0]=o2[i][0]+1;
        output[smallAns1+i][1]=input[0];
    }
    
   
    
    return smallAns1+smallAns2;
}


int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
