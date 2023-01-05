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
 // 876. Middle of the Linked List
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* middle = head;
        while(head->next != NULL) {
            head = head->next;
            if(count%2 == 0 ) {
                middle = middle->next;
            }            
            count++;
        }
        return middle;
    }
};