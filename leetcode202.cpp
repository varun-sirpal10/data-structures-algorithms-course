class Solution {
public:
    bool isHappy(int n) {
        
        unordered_map<int,bool> hp;
        int sum;
        
        if(n==1){
            return true;
        }
        
        while(n != 1){
           sum = 0;
           while(n > 0){
                int rem = n%10;
                sum += rem*rem;
                n = n/10;
            }

            if(hp.count(sum)) return false;
            else {
                hp[sum] = true;
                n = sum;    
            }
            
            if(n==1){
                return true;
            }
        }
        return false;
    }
};