/*
Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.
*/
#include <iostream>
using namespace std;

#include<vector>
class PriorityQueue {
    // Declare the data members here
	vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
        
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int childindex=pq.size()-1;
        while(childindex>0){
        	int parentindex=(childindex-1)/2;
        	if(pq[parentindex]<pq[childindex]){
                int temp=pq[childindex];
                pq[childindex]=pq[parentindex];
                pq[parentindex]=temp;
            }
            else{
                break;
            }
            childindex=parentindex;
        }
        
    }

    int getMax() {
        // Implement the getMax() function here
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        int lastindex=pq.size()-1;
        int temp=pq[lastindex];
        pq[lastindex]=pq[0];
        pq[0]=temp;
        
        int ans=pq[lastindex];
        // pq.erase(pq.end());
        pq.pop_back();
        lastindex=pq.size()-1;
        int parentindex=0;
        while(parentindex<lastindex){
            int lchildindex=2*parentindex+1;
            int rchildindex=2*parentindex+2;
            if(lchildindex>=lastindex){
                break;
            }
            if(pq[parentindex]<pq[lchildindex]||pq[parentindex]<pq[rchildindex]){
                int mx=max(pq[lchildindex],pq[rchildindex]);
                if(mx==pq[lchildindex]){
                    int t=pq[parentindex];
                    pq[parentindex]=pq[lchildindex];
                    pq[lchildindex]=t;
            		parentindex=lchildindex;
                }
                else{
                    int t=pq[parentindex];
                    pq[parentindex]=pq[rchildindex];
                    pq[rchildindex]=t;
                    parentindex=rchildindex;
                }
            }
            else{
                break;
            }
        }
        // while()
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}