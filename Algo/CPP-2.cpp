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
 // 2. Add Two Numbers represented in linked list
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *last = head;

        int a,b,sum;
        int c = 0;

        while(l1 != NULL || l2 != NULL || c != 0){
            if(l1 == NULL){
                a = 0;
            }
            else{
                a = l1->val;
                l1 = l1->next;
            }
            if(l2 == NULL){
                b = 0;
            }
            else{
                b = l2->val;
                l2 = l2->next;
            }
            
            sum = (a+b+c)%10;
            c = (a+b+c)/10;

            last->next = new ListNode(sum);
            last = last->next;            
        }
        return head->next;
    }
};