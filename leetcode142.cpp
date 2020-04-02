/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        
        while(true){
            if(fast!=NULL and fast->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;   
            }
            else{
                return NULL;
            }
            if(slow == fast){
                break;
            }
        }
        
        while(slow != temp){
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
};