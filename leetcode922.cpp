class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        for(int i=0;i<A.size();i++){
            
            if((A[i]%2==0 and i%2==0) or (A[i]%2!=0 and i%2!=0)){
                continue;
            }
            
            else{
                for(int j=i;j<A.size();j++){
                    if((A[i]%2==0 and i%2!=0) and (A[j]%2!=0 and j%2==0)){
                        swap(A[i],A[j]);
                        break;
                    }
                    
                    else if((A[i]%2!=0 and i%2==0) and (A[j]%2==0 and j%2!=0)){
                        swap(A[i],A[j]);
                        break;
                    }
                }    
            }
        }
        
        return A;
    }
};