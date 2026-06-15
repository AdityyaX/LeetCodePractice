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

// dummy 1 2 3 4 5
// dummy 1 2 3 4

/* here after moving to the center of LL we break and reverse the right half of LL and then use it traver in 1st from start and from reversed second t find the maximum
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* dummy = new ListNode(10);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        while (slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        int ans = 0;
        while (prev && head) {
            ans = max(ans, head->val + prev->val);
            head = head->next;
            prev = prev->next;
        }

        return ans;
    }
};