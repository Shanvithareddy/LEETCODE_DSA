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
    int getSize(ListNode* head){
        int i=0;
        while(head!= nullptr){
            head = head->next;
            i++;
        }
        return i;
    }
    ListNode* giveAddr(ListNode * head, int i){
        if(i < 1) return nullptr;
        while(i > 1 && head!= nullptr){
            head = head->next;
            i--;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = getSize(head);
        if(k-n == 0){
            head = head->next;
            return head;
        }
        ListNode* prev = head;
        ListNode* curr = head->next;
        int i =1;
        while(i!= k-n){
            prev = prev->next;
            curr = curr->next;
            i++;
        }
        prev->next = curr->next;

        // ListNode* elbef = giveAddr(head,k-n);
        // ListNode* el = giveAddr(head,k-n+1);
        // if(elbef == nullptr){
        //     head = head->next;
        // }
        // else{
        //     elbef->next = el->next;
        // }
        return head;
    }
};