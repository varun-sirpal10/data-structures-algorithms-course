class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.empty()){
            return 0;
        }
        
        int n =  matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j] = matrix[i][j]-'0';
            }
        }
        
        int maxSize = INT_MIN;

        int currVal = histogramArea(arr[0], arr[0].size());

        maxSize = max(currVal, maxSize);

        for (int i = 1; i < arr.size(); i++) {

            for (int j = 0; j < arr[0].size(); j++) {
                if (arr[i][j] == 1) {
                    arr[i][j] = arr[i - 1][j] + 1;
                } else {
                    arr[i][j] = 0;
                }
            }

            currVal = histogramArea(arr[i], arr[0].size());

            maxSize = max(maxSize, currVal);
        }

        return maxSize;
    }
    
    int histogramArea(vector<int>& arr, int n) {

	stack<int> s;

	int maxArea = INT_MIN;

	int i = 0;

	while (i < n) {

		if (s.empty() or arr[s.top()] <= arr[i]) {
			s.push(i);
			i++;
		} else {
			int extractedTop = s.top();
			s.pop();

			int height = arr[extractedTop];

			int currArea;

			if (s.empty()) {
				currArea = height * i;
			} else {
				currArea = height * (i - s.top() - 1);
			}

			maxArea = max(currArea, maxArea);
		}
	}

	while (!s.empty()) {

		int extractedTop = s.top();
		s.pop();

		int height = arr[extractedTop];
		int currArea;

		if (s.empty()) {
			currArea = height * i;
		} else {
			currArea = height * (i - s.top() - 1);
		}

		maxArea = max(currArea, maxArea);
	}

	return maxArea;
  }

};

