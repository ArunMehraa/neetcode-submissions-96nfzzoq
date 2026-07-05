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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* first = list1;
        ListNode* second = list2;
        ListNode* res = NULL;
        ListNode* temp = NULL;
        if(!first)return second;
        if(!second)return first;
        if(first->val > second->val){
            res = second;
            second = second->next;
        }
        else{
            res = first;
            first = first->next;
        }
        res->next = NULL;
        temp = res;
        while(first || second){
            if(first==NULL){
                res->next=second;
                break;
            }
            if(second==NULL){
                res->next=first;
                break;
            }
            if(first->val > second->val){
                res->next = second;
                second = second->next;
            }
            else{
                res->next = first;
                first = first->next;
            }
            res = res->next;
            if(res)res->next = NULL;
        }
        return temp;
    }
};
