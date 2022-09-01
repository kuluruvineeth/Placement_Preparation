#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
    public:
        bool hasCycle(ListNode *head){
            if(head==NULL){
                return false;
            }
            ListNode *slow = head;
            ListNode *fast = head;
            while(fast->next!=NULL && fast->next->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast){
                    return true;
                }
            }
            return false;
        }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    if(s.hasCycle(head)){
        cout<<"Linked list has cycle"<<endl;
    }else{
        cout<<"Linked list has no cycle"<<endl;
    }
    return 0;
}