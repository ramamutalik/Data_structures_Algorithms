/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num==0){
        output[0]="";
        return 1;
    }
    
    int smallAns=keypad(num/10,output);
    int n=num%10;
    
    if(n==7||n==9){
        if(n==7){
        string input="pqrs";
        
        for(int i=1;i<=3;i++){
        for(int j=0;j<smallAns;j++){
            output[j+(smallAns*(i))]=output[j]+input[i];
        }
    	}
        for(int j=0;j<smallAns;j++){
            output[j]=output[j]+input[0];
        }
        }
        
        if(n==9){
        string input="wxyz";
        
        for(int i=1;i<=3;i++){
        for(int j=0;j<smallAns;j++){
            output[j+(smallAns*(i))]=output[j]+input[i];
        }
    	}
            for(int j=0;j<smallAns;j++){
            output[j]=output[j]+input[0];
        }
        }
        
        return smallAns*4;
    }
    else{
        if(n==2){
            string input="abc";
        
        for(int i=1;i<3;i++){
        for(int j=0;j<smallAns;j++){
            output[j+(smallAns*(i))]=output[j]+input[i];
        }
    	}
            for(int j=0;j<smallAns;j++){
            output[j]=output[j]+input[0];
        }
        }
        if(n==3){
            string input="def";
        
        for(int i=1;i<3;i++){
        for(int j=0;j<smallAns;j++){
            output[j+(smallAns*(i))]=output[j]+input[i];
        }
    	}
            for(int j=0;j<smallAns;j++){
            output[j]=output[j]+input[0];
        }
        }
        
        if(n==4){
            string input="ghi";
        
        for(int i=1;i<3;i++){
        for(int j=0;j<smallAns;j++){
            output[j+(smallAns*(i))]=output[j]+input[i];
        }
    	}
            
		for(int j=0;j<smallAns;j++){
            output[j]=output[j]+input[0];
        }
        }
        
        if(n==5){
            string input="jkl";
        
        for(int i=1;i<3;i++){
        for(int j=0;j<smallAns;j++){
            output[j+(smallAns*(i))]=output[j]+input[i];
        }
    	}
            for(int j=0;j<smallAns;j++){
            output[j]=output[j]+input[0];
        }
        }
        
        if(n==6){
            string input="mno";
        
        for(int i=1;i<3;i++){
        for(int j=0;j<smallAns;j++){
            output[j+(smallAns*(i))]=output[j]+input[i];
        }
    	}
            for(int j=0;j<smallAns;j++){
            output[j]=output[j]+input[0];
        }
        }
        
        if(n==8){
            string input="tuv";
        
        for(int i=1;i<3;i++){
        for(int j=0;j<smallAns;j++){
            output[j+(smallAns*(i))]=output[j]+input[i];
        }
    	}
        for(int j=0;j<smallAns;j++){
            output[j]=output[j]+input[0];
        }
        }
        return smallAns*3;
    }
        
    
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
