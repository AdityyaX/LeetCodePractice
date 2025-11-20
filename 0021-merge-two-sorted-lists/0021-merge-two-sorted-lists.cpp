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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* HeadMain = &dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                HeadMain->next = list1;
                list1 = list1->next;
                HeadMain = HeadMain->next;
            } else {
                HeadMain->next = list2;
                list2 = list2->next;
                HeadMain = HeadMain->next;
            }
        }
        if (list1 != NULL) {

            HeadMain->next = list1;
        }
        if (list2 != NULL) {

            HeadMain->next = list2;
        }
        return dummy.next;
    }
};