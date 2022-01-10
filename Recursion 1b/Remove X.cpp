/*
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:


*/

#include <iostream>
using namespace std;

//approach 1

#include<string.h>;
void removeX(char input[]) {
    // Write your code here
    int len=strlen(input);
    if(len==0){
        return;
    }
    
    if(input[0]=='x'){
        int count=0;
        int i=0;
        
        while(input[i]!='\0'){
            count++;
            i++;
        }
        
        for(i=1;i<=count;i++){
            input[i-1]=input[i];
        }
        removeX(input);
    }
    
    removeX(input+1);
}

//approach 2

int len(char input[]){
    int len=0;
    for(int i=0;input[i]!='\0';i++){
        len++;
    }
    return len;
}

void removeX(char input[],int start){
    if(input[start]=='\0'){
        return ;
    }
    removeX(input,start+1){
        int len=length(input);
        int i;
        for(i=start+1;i<len;i++){
            input[i-1]=input[i];
        }
        input[i-1]='\0';
    }
}

void removeX(char input[]){
    removeX(input,0);
}
int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
