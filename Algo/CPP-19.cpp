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
 // 19. Remove Nth Node From End of List
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* begin = new ListNode();
        ListNode* temp;
        begin->next = head;
        temp = begin;
        if(head == NULL || (head->next == NULL && n == 1 )) {
            return NULL;
        }

        while(head->next != NULL) {
            if(n!=1){
                head = head->next;
                n--;
            }
            else{
                head = head->next;
                temp = temp->next;
            }
        }
        head = temp->next->next;
        temp->next = head;
        return begin->next;
    }
};