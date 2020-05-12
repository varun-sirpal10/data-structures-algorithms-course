class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() == 0 or prices.size() == 1){
            return 0;
        }
        
        int minprice = INT_MAX;
        int maxprofit = 0;
        
        for(int i=0;i<prices.size();i++){
            if(prices[i] < minprice){
                minprice = prices[i];
            }
            if(prices[i] - minprice > maxprofit){
                maxprofit = prices[i] - minprice;
            }
        }
        
        return maxprofit;
    }
};