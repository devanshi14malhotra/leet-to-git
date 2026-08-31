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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> pos;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int idx = 1;

        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                pos.push_back(idx);
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }

        vector<int> result(2);
        result[0] = -1;
        result[1] = -1;

        if (pos.size() >= 2) {
            int minDist = INT_MAX;
            for (int i = 1; i < pos.size(); i++) {
                minDist = min(minDist, pos[i] - pos[i - 1]);
            }
            int maxDist = pos.back() - pos.front();

            result[0] = minDist;
            result[1] = maxDist;
        }

        return result;
    }
};