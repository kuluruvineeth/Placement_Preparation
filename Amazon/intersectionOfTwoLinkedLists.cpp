#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
            ListNode *p = headA, *q = headB;
            int m = 0, n = 0, k;
            while(p) m++, p = p->next;
            while(q) n++, q = q->next;
            k = m < n ? n-m : m-n;
            p = m < n ? headA : headB;
            q = m < n ? headB : headA;
            while(k>0) k--, q = q->next;
            while(p&&q){
                if(p==q) return p;
                p = p->next;
                q = q->next;
            }
            return NULL;
        }
};

int main(){
    Solution s;
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    headB->next->next->next->next = new ListNode(4);
    headB->next->next->next->next->next = new ListNode(5);

    ListNode *res = s.getIntersectionNode(headA,headB);
    cout<<"The intersection point is : "<<res->val<<endl;
    return 0;
}