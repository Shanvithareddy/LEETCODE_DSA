/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int min = -1 * (pow(10,5)+1);
    bool hasCycle(ListNode *head) {
        ListNode * ptr;
        ptr = head;
        while(ptr != NULL){
            if(ptr->val == min) return true;
            ptr->val = min;
            ptr = ptr->next;
        }
        return false;
    }
};