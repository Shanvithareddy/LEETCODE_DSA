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

    void reverse(ListNode* head, ListNode* tail){
        if(head == nullptr) return;
        ListNode* prev = head;
        ListNode* curr = prev->next;
        prev->next = nullptr;
        while(prev != tail){
            // cout<<"enterd\n";
            ListNode* after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return;
    }
    ListNode* giveAddr(ListNode * head, int i){
        if(i < 1) return nullptr;
        while(i > 1 && head!= nullptr){
            head = head->next;
            i--;
        }
        return head;
    }
   
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i =0;
        while(true){
            ListNode* lft = giveAddr(head,i+1);
            ListNode* rgt = giveAddr(head,k+i);
            if(rgt == nullptr) break;
            ListNode* lftbef = giveAddr(head,i);
            ListNode* rgtaft = giveAddr(head,k+1+i);
           
            reverse(lft,rgt);
            
            lft->next = rgtaft;
            if(lftbef == nullptr) head = rgt;
            else lftbef->next = rgt;
            i += k;
        }
        return head;
    }
};