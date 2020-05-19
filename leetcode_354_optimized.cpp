class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        if(n<=1) return n;

        sort(envelopes.begin(), envelopes.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});

        int tails[n],size = 1;

        tails[0] = envelopes[0][1];

        for(int i=1;i<n;i++){
            
            if(envelopes[i][1]>tails[size-1]){
                tails[size]=envelopes[i][1];
                size++;
            }

            else{
                int l=0;
                int r=size-1;
                while(l!=r){
                    int m = (l+r)/2;
                    if(tails[m]<envelopes[i][1])
                        l=m+1;
                    else
                        r=m;
                }
                tails[l]=envelopes[i][1];
            }
        }
        return size;
    }
};