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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        vector<int> result;
        stack<int> s;
        
        while(prev != NULL){
            
            while(!s.empty() and prev->val >= s.top()){
                s.pop();
            }
            
            if(s.empty()){
                result.push_back(0);
            }
            
            else{
                result.push_back(s.top());
            }
            
            s.push(prev->val);
            prev = prev->next;
        }
        
        reverse(result.begin(),result.end());
        
        return result;
    }
};