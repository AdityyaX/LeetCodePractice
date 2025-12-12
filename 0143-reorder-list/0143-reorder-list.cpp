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
 /*STORE ALL VALUES IN VECTOR FIRST ADD J TO I THEN I++ AND THEN ADD J TO ITS BACK
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        ListNode* curr = head;
        while (curr) {
            list.push_back(curr);
            curr = curr->next;
        }
        int i = 0;
        int j = list.size() - 1;
        while (i < j) {
            list[i]->next = list[j];
            i++;
            if (i >= j)
                break;
            list[j]->next = list[i];
            j--;
        }
        list[i]->next = NULL;
    }
};