#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution{
    public:
    ListNode* removeElements(ListNode* head, int val){
       ListNode* dummy = new ListNode(-1); 
       dummy->next = head;
       ListNode* p = head;
       ListNode* pre = dummy;

       while(p!=NULL){
        if(p->val == val){
            pre->next = p->next;
            delete p;
            p = pre->next;
        }
        else{
            p = p->next;
            pre = pre->next;
        }
       }
       return dummy->next;
    } 
};

int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    ListNode *newHead = s.removeElements(head,6);
    while(newHead!=NULL){
        cout<<newHead->val<<endl;
        newHead = newHead->next;
    }
    return 0;
}