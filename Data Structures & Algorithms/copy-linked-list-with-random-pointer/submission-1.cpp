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
        if (!head) return nullptr;

        Node* curr = head;
        while (curr) {
            Node* copied = new Node(curr->val);
            copied->next = curr->next;
            curr->next = copied;
            curr = copied->next;
        }

        Node* copiedHead = head->next;

        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;

        while (curr) {
            Node* copied = curr->next;
            curr->next = copied->next;
            if (copied->next) {
                copied->next = copied->next->next;
            }
            curr = curr->next;
        }

        return copiedHead;
    }
};

