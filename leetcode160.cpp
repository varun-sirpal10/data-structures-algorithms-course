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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = length(headA);
        int len2 = length(headB);
        
        int diff = fabs(len1-len2);
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        if(len1>len2){
            while(diff--){
                temp1 = temp1->next;
            }
        }
        else{
            while(diff--){
                temp2 = temp2->next;
            }
        }
        
        while(temp1!=NULL){
            if(temp1 == temp2){
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
    
    int length(ListNode* head){
        ListNode* temp = head;
        int len=0;
        
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        
        return len;
    }
};