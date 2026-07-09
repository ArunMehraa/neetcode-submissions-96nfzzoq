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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nodes = 0;
        ListNode* temp = head;
        while(temp){
            nodes++;
            temp = temp->next;
        }
        int start = nodes-n-1;
        int count=0;
        temp = head;
        while(start>0 && count!=start){
            temp = temp->next;
            count++;
        }
        if(start<0)return head->next;
        if(temp->next)temp->next = temp->next->next;
        else temp->next = NULL;
        return head;
    }
};
