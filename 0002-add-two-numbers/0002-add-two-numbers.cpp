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
        ListNode * head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while( l1 != nullptr || l2 != nullptr){
            int sum ;
            if(l1 != nullptr && l2 != nullptr){
                sum = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 == nullptr){
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else{
                sum = l1->val + carry;
                l1 = l1->next;
            }
            if(sum > 9){
                carry = 1;
                sum = sum - 10;
            }
            else carry = 0;
            if(head == nullptr && tail==nullptr){
                head = new ListNode(sum);
                tail = head;
            }
            else {
                // cout<<tail->next<<endl;
                tail->next = new ListNode(sum);
                tail = tail->next;
            }

        }
        if(carry == 1){
            tail->next = new ListNode(1);
        }
        return head;
    }
};