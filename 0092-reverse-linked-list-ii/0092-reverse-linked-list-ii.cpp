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
            cout<<"enterd\n";
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
    // void print(ListNode * head){
    //     while(head!= nullptr){
    //         cout<<head->val<<",";
    //         head = head->next;
    //     }
    //     cout<<endl;
    //     return;
    // }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // print(head);
        ListNode* lft = giveAddr(head,left);
        ListNode* rgt = giveAddr(head,right);
        ListNode* lftbef = giveAddr(head,left-1);
        ListNode* rgtaft = giveAddr(head,right+1);
        // cout<<lft<<"...";
        reverse(lft,rgt);
        // cout<<lft<<"..\n";
        // print(rgt);
        lft->next = rgtaft;
        if(lftbef != nullptr) lftbef->next = rgt;
        else head = rgt;
        return head;
    }
};