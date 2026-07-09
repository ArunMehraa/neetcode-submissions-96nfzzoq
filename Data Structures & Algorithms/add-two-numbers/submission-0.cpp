/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* a = l1;
        ListNode* b = l2;
        int carry = 0;
        ListNode* temp = res;
        while(a || b){
            int aa = a ? a->val : 0;
            int bb = b ? b->val : 0;
            int neww = (aa+bb+carry)%10;
            carry = (aa+bb+carry)/10;
            temp->next = new ListNode(neww);
            temp = temp->next;
            if(a)a=a->next;
            if(b)b=b->next;
        }
        if(carry)temp->next = new ListNode(carry);
        return res->next;
    }
};
