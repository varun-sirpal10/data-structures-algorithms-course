/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> hp;
        return helper(head,hp);
    }
    
    Node* helper(Node* head, unordered_map<Node*,Node*>& hp){
        if(head==NULL){
            return NULL;
        }
        
        if(hp.count(head)){
            return hp[head];
        }
        
        Node* copied_head = new Node(head->val);
        hp[head] = copied_head;
        
        copied_head->next = helper(head->next,hp);
        copied_head->random = helper(head->random,hp);
        
        return copied_head;
    }
};