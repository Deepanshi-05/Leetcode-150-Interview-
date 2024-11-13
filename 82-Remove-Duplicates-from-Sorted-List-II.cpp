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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* dummy =new ListNode(0); 
        dummy->next = head;
        ListNode* prev = dummy;
        
        ListNode* temp = head;
        ListNode* curr = head->next;
        while (temp != NULL && temp->next != NULL) { // Correct condition
        if (temp->val == temp->next->val) {
            while (temp->next != NULL && temp->val == temp->next->val) {
                temp = temp->next; // Skip all duplicates
            }
            prev->next = temp->next; // Remove duplicates
        } else {
            prev = prev->next; // Move prev forward only if no duplicates
        }
        temp = temp->next; // Move temp forward
    }
    
    return dummy->next; // Return the actual head
    }
};