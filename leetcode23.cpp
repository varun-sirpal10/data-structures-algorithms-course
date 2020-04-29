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
    
    class Compare{
    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }    
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        
        for(ListNode* head:lists){
            if(head != NULL){
                pq.push(head);   
            }
        }
        
        if(pq.empty()){
            return NULL;
        }
        
        ListNode* head = pq.top();
        pq.pop();
        
        ListNode* temp = head;
        if(temp->next != NULL){
            pq.push(temp->next);
        }
        
        while(!pq.empty()){
            temp->next = pq.top();
            pq.pop();
            
            temp = temp->next;
            
            if(temp->next != NULL){
                pq.push(temp->next);
            }
        }
        
        return head;
    }
};