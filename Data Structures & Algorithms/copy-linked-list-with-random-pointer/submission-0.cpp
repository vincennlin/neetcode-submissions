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
        unordered_map<Node*, Node*> nodeToCopiedMap;

        Node* curr = head;
        Node* dummy = new Node(0);
        Node* copiedPrev = dummy;

        while (curr) {
            copiedPrev->next = new Node(curr->val);
            nodeToCopiedMap[curr] = copiedPrev->next;
            curr = curr->next;
            copiedPrev = copiedPrev->next;
        }

        curr = head;
        Node* copiedCurr = dummy->next;

        while (curr) {
            copiedCurr->random = nodeToCopiedMap[curr->random];
            curr = curr->next;
            copiedCurr = copiedCurr->next;
        }

        Node* res = dummy->next;
        delete dummy;

        return res;
    }
};