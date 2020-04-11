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
        
        ListNode* temp1 = head;
        ListNode* temp2;
        int flag;
        
        vector<int> result;
        
        while(temp1 != NULL){
            temp2 = temp1->next;
            flag = 0;
            while(temp2 != NULL){
                if(temp2->val > temp1->val){
                    result.push_back(temp2->val);
                    flag = 1;
                    break;
                }
                temp2 = temp2->next;
            }
            if(flag == 0){
                result.push_back(0);
            }
            temp1 = temp1->next;
        }
        
    return result;
    }
};