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

/* 1->2->3->4->5
1->3->5->2->4
odd 1
even 2
odd->next = even->next
odd = odd->next
even->next =odd->next
even = even->next
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        int pos = 1;
        while (even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};