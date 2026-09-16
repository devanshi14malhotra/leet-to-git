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
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        // find length and the tail node
        int len = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0) return head;

        // make it circular temporarily
        tail->next = head;

        // find the new tail: (len - k - 1) steps from head
        int stepsToNewTail = len - k - 1;
        ListNode* newTail = head;
        for (int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};