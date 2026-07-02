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
    Node* copyRandomList(Node* head) {
        // 1) Create and insert new node bwtween existing ones

        Node* curr = head;

        while(curr){
            Node* temp = new Node(curr->val);

            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;

        }

        // 2) fix the random pointers

        curr = head;

        while(curr){
            if(!curr->random){
                curr->next->random = nullptr;
                curr = curr->next->next;
                continue;
            }

            curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3) detach BOTH the linked lists

        curr = head;
        Node* dummy = new Node(0);
        Node* temp = dummy;

        while(curr){
            temp->next = curr->next;
            curr->next = curr->next->next;
            temp = temp->next;
            curr = curr->next;
        }

        return dummy->next;

    }
};