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
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1->val > list2->val){
            ListNode * temp = list2;
            list2 = list1;
            list1 = temp;
        }
        ListNode * head = list1;
        ListNode * tail = list1;
        list1 = list1->next;
        while(list1 != nullptr || list2 != nullptr){
            if(list1 == nullptr){
                head->next = list2;
                head = list2;
                list2 = list2->next;
            }
            else if(list2 == nullptr){
                head->next = list1;
                head = list1;
                list1 = list1->next;
            }
            else if(list1->val < list2->val){
                head->next = list1;
                head= list1;
                list1 = list1->next;
            }
            else{
                head->next = list2;
                head= list2;
                list2 = list2->next;
            }
        }
        return tail;

    }
};