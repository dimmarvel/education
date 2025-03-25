#include "p.hpp"

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
            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;
    
            while(list1 && list2)
            {
                if(list1->val > list2->val)
                {
                    curr->next = list2;
                    list2 = list2->next;
                } else
                {
                    curr->next = list1;
                    list1 = list1->next;
                }
                curr = curr->next;
            }
            curr->next = (list1) ? list1 : list2;
            ListNode* head = dummy->next;
            delete dummy;
            return head;
        }
    };