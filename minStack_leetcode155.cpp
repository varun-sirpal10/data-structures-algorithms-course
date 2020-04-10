class MinStack {
    stack<int> s1;
    stack<int> s2;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {    
        s1.push(x);
        if(s2.empty()){
            s2.push(x);
        }
        else if(x <= s2.top()){
            s2.push(x);
        }
    }
    
    void pop() {
        if(s1.top() == s2.top()){
            s1.pop();
            s2.pop();
        }
        else{
            s1.pop();
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */