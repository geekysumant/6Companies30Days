int minSubArrayLen(int target, vector<int>& nums) {
    int ans = nums.size() + 1;
    int sum = 0;
    int l = 0, r = 0;
    while (r < nums.size()) {
        sum += nums[r];
        while (l <= r && sum > target) {
            if (sum - nums[l] >= target)
                sum -= nums[l++];
            else break;
        }
        if (sum >= target)
            ans = min(ans, r - l + 1);
        r++;
    }

    return ans == nums.size() + 1 ? 0 : ans;
}