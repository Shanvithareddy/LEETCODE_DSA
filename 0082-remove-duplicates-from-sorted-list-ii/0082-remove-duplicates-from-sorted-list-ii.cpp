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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* ptr = head;
        if(ptr->next == nullptr) return head;
        ListNode* prev = head;
        while(ptr != nullptr){
            ListNode* mptr = ptr;
            while(mptr->val == ptr->val){
                mptr = mptr->next;
                if(mptr == nullptr) break;
            }
            if(ptr->next == mptr) {
                prev = ptr;
                ptr = mptr;
            }
            else{
                if(ptr == head){
                    head = mptr;
                    ptr = mptr;
                }
                else{
                    prev->next = mptr;
                    ptr = mptr;
                }
            }
        }
        return head;
    }
};