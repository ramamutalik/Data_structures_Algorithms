/*

Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S
Output Format :
All permutations (in different lines)
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

int k=0;
int returnPermutations(string input, string output[],string ans=""){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
    */
    
    if(input.length() == 0)
    {
        output[k++]=ans;
        return k;
    }
  
    for(int i=0 ; i<input.length() ; i++)
    {
        char ch = input[i];
        string left_substr = input.substr(0,i);
        string right_substr = input.substr(i+1);
        string rest = left_substr + right_substr;
       int j= returnPermutations(rest , output,ans+ch);
    }
    
    return k;
}


int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

