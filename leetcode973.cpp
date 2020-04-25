class Solution {
public:
    class Compare{
    public:
        bool operator()(vector<int> &a, vector<int> &b){
            int x = a[0] * a[0] + a[1] * a[1];
		    int y = b[0] * b[0] + b[1] * b[1];
            
            return x < y;
        }
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        
        for(vector<int> point:points){
            pq.push(point);
        }
        
        while(pq.size() > K){
            pq.pop();
        }
        
        vector<vector<int>> res;
        
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        
        return res;
    }
};