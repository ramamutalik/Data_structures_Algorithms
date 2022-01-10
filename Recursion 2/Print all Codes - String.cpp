/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/
#include <iostream>
using namespace std;

#include <string.h>
using namespace std;

int atoi(char a)
{
    int i=a-'0';
    return i;
}
char atoc(int i)
{
    char c='a'+i-1;
    return c;
}

void printAllPossibleCodes_helper(string input,string output=""){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    // if(size==1){
    //     cout<<atoc(atoi(input[0]))<<endl;
    // }
    char ch1=atoc(atoi(input[0]));
    // string result1[10000],result2[10000];
    printAllPossibleCodes_helper(input.substr(1),output+ch1);
    if(input.size()>=2)
    {
        if((atoi(input[0])*10+atoi(input[1]))>=10&&(atoi(input[0])*10+atoi(input[1])<27))
        {
            int ch2=atoi(input[0]);
            int ch3=atoi(input[1]);
            int x=ch2*10+ch3;
            char ch4=atoc(x);
            printAllPossibleCodes_helper(input.substr(2),output+ch4);
        }

    }
    return;

}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output="";
    printAllPossibleCodes_helper(input,output);
    return;
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
