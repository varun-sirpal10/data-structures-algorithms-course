class Solution {
public:
    bool isPossible(int si, vector<int> &nums, int sum, int total) {
	if (sum == total) return true;

	if (sum > total or si == nums.size()) {
		return false;
	}

	bool include = isPossible(si + 1, nums, sum + nums[si], total);
	bool exclude = isPossible(si + 1, nums, sum, total);

	if (include or exclude) {
		return true;
	}

	return false;
}

bool canPartition(vector<int>& nums) {
	int total = 0;

	for (int i = 0; i < nums.size(); i++) {
		total += nums[i];
	}

	if (total % 2 == 1) return false;

	total = total / 2;

	return isPossible(0, nums, 0, total);
}

};