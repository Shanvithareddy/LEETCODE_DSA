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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return head;
        ListNode* ptr = head;
        ListNode* tail = head;
        int n = 0;
        while(ptr!=nullptr){
            tail = ptr;
            ptr = ptr->next;
            n++;
        }
        int m = k%n;
        if(m==0) return head;
        int i = n;
        ptr = head;
        while(i!=m+1){
            ptr = ptr->next;
            i--;
        }
        ListNode* temp = ptr->next;
        ptr->next = nullptr;
        tail->next = head;
        head = temp;
        return head;
    }
};