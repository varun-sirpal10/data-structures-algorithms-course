class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int evenptr = 0;
        
        for(int i=0;i<A.size();i++){
            if(A[i]%2==0){
                if(evenptr<A.size()){
                    int temp = A[evenptr];
                    A[evenptr] = A[i];
                    A[i] = temp;
                    evenptr++;       
                }
            }
        }
        
        return A;
    }
};