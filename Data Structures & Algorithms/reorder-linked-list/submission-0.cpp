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
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        int size = st.size()/2;
        temp = head;
        ListNode* top = NULL;
        while(size--){
            top = st.top();
            st.pop();
            top->next = temp->next;
            temp->next = top;
            temp = top->next;
        }
        if(temp)temp->next = NULL;
    }
};
