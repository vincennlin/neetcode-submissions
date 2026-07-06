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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            n += 2;
        }

        if (fast) n++;

        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = dummy;

        for (int i = 0; i < n / 2; i++) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* root = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;

        return root;
    }
};
