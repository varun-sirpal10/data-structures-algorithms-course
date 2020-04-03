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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == NULL) {
            return NULL;
        }
        
        ListNode* head1 = NULL;
        ListNode* head2 = NULL;
        ListNode* tail1;
        ListNode* tail2;
        ListNode* temp = head;
        
        while(temp!=NULL){
            
            if(temp->val < x){
                
                if(head1==NULL){
                    head1 = temp;
                    tail1 = temp;
                }
                
                else{
                    tail1->next = temp;
                    tail1 = tail1->next;
                }
            }
            
            else{
                
                if(head2 == NULL){
                    head2 = temp;
                    tail2 = temp;
                }
                
                else{
                    tail2->next = temp;
                    tail2 = tail2->next;
                }
            }
            
            temp = temp->next;
        }
        if(head1==NULL){
            tail2->next = NULL;
            return head2;
        }
        if(head2 == NULL){
            tail1->next=NULL;
            return head1;
        }
        
        tail1->next = head2;
        tail2->next = NULL;
        
        return head1;
    }
};