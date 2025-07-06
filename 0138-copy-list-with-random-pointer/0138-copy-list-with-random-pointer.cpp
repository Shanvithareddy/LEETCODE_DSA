/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    int giveIndex(Node * head, Node* addr){
        int i = 1;
        while(head != NULL){
            if(head == addr) return i;
            head = head->next;
            i++;
        }
        return -1;
    }

    Node* giveAddr(Node * head, int i){
        while(i!=1){
            // cout<<i<<endl;
            head = head->next;
            i--;
        }
        return head;
    }
    void print(Node * head){
        while(head!= nullptr){
            cout<<head->val<<",";
            head = head->next;
        }
        cout<<endl;
        return;
    }

    Node* copyRandomList(Node* head) {
        // cout<<giveIndex(head, head->next->next->random)<<endl;
        if(head == nullptr) return nullptr;
        Node* headc = nullptr;
        Node* tail = nullptr;
        //copying with values and nexts is done
        Node * head1 = head;
        while(head != NULL){
            if(headc == NULL){
                headc = new Node(head->val);
                tail = headc;
                head = head->next;
            }
            else{
                tail->next = new Node(head->val);
                tail = tail->next;
                head = head->next;
            }
        }
        // print(headc);
        head = head1;
        tail = headc;
        //now copying randoms
        while(head != NULL){
            if(head->random == NULL) {
                tail->random = NULL;
                tail = tail->next;
                head = head->next;
                continue;
            }
            int i = giveIndex(head1,head->random);
            tail->random = giveAddr(headc,i);
            tail = tail->next;
            head = head->next;
            // cout<<"done"<<endl;
        }
        return headc;

    }
};