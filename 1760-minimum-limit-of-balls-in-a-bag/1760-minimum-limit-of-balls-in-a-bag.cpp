class Solution {
public:
	int operations(vector<int>& nums, int mid) {
		int requiredOps = 0;
		for (int n : nums) {
			// no. of operations required to bring n less than or eq to curr assumed penalty
			int x = n / mid;
			// if n is divisible by penalty, need to subtract 1
			if (n % mid == 0) x--;
			requiredOps += x;
		}
		return requiredOps ;
	}
	int minimumSize(vector<int>& nums, int maxOperations) {
		int start = 1, end = *max_element(nums.begin(), nums.end());
		int ans;
		// binary search on possible range
		while (start <= end) {
			int mid =(start + end)>>1;
			if (operations(nums, mid)<=maxOperations){
				ans = mid;
                end = mid-1;
            }
			else
				start = mid+1;
		}

		return ans;
	}


};