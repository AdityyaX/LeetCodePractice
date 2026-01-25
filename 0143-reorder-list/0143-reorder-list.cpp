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
        ListNode* temp = head;
        vector<ListNode*> res;
        while (temp) {
            res.push_back(temp);
            temp = temp->next;
        }
        ListNode* newNode = NULL;
        int i = 0;
        int n = res.size() - 1;
        while (i < n) {
            res[i]->next = res[n];
            i++;
            if (i >= n) {
                break;
            }
            res[n]->next = res[i];
            n--;
        }
        res[i]->next = NULL;
    }
};