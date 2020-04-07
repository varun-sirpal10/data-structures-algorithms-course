class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0){
            return 0;
        }
        return histogramArea(heights, heights.size());
    }
    
    int histogramArea(vector<int>& arr, int n){
	
	stack<int> s;

	int maxArea = INT_MIN;

	int i=0;

	while(i<n){

		if(s.empty() or arr[s.top()] <= arr[i]){
			s.push(i);
			i++;
		}

		else{

			int extractedTop = s.top();
			s.pop();
			int height = arr[extractedTop];

			int currArea;

			if(s.empty()){
				currArea = height*i;
			}
			else{
				currArea = height*(i - s.top() - 1);
			}
			
			maxArea = max(maxArea,currArea);
		}
	}

	while(!s.empty()){

		int extractedTop = s.top();
		s.pop();
		int height = arr[extractedTop];

		int currArea;

		if(s.empty()){
			currArea = height*i;
		}
		else{
			currArea = height*(i - s.top() - 1);
		}
		
		maxArea = max(maxArea,currArea);
	}

	return maxArea;
}
};