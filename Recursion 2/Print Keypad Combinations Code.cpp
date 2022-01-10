/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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

#include <iostream>
#include <string>
using namespace std;


void printKeypad1(int num,string output){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    
    // printKeypad1(num/10,output);
    int n=num%10;
    if(n==7||n==9){
        if(n==7){
            string input="pqrs";
            printKeypad1(num/10,input[0]+output);
            printKeypad1(num/10,input[1]+output);
            printKeypad1(num/10,input[2]+output);
            printKeypad1(num/10,input[3]+output);
        }
        if(n==9){
            string input="wxyz";
            printKeypad1(num/10,input[0]+output);
            printKeypad1(num/10,input[1]+output);
            printKeypad1(num/10,input[2]+output);
            printKeypad1(num/10,input[3]+output);
        }
        return;
    }
    else{
        if(n==2){
            string input="abc";
            printKeypad1(num/10,input[0]+output);
            printKeypad1(num/10,input[1]+output);
            printKeypad1(num/10,input[2]+output);
        }
        if(n==3){
            string input="def";
            printKeypad1(num/10,input[0]+output);
            printKeypad1(num/10,input[1]+output);
            printKeypad1(num/10,input[2]+output);
        }
        if(n==4){
            string input="ghi";
            printKeypad1(num/10,input[0]+output);
            printKeypad1(num/10,input[1]+output);
            printKeypad1(num/10,input[2]+output);
        }
        if(n==5){
            string input="jkl";
            printKeypad1(num/10,input[0]+output);
            printKeypad1(num/10,input[1]+output);
            printKeypad1(num/10,input[2]+output);
        }
        if(n==6){
            string input="mno";
            printKeypad1(num/10,input[0]+output);
            printKeypad1(num/10,input[1]+output);
            printKeypad1(num/10,input[2]+output);
        }
        if(n==8){
            string input="tuv";
            printKeypad1(num/10,input[0]+output);
            printKeypad1(num/10,input[1]+output);
            printKeypad1(num/10,input[2]+output);
        }
        return;
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output="";
    printKeypad1(num,output);
    return;
}


int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
