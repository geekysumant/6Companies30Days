vector<int> max_of_subarrays(vector<int> nums, int n, int k) {
    // your code here
    deque<int>dq;
    vector<int> ans(n - k + 1);
    for (int i = 0; i < nums.size(); i++) {

        if (!dq.empty() && i - dq.front() == k)dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) {
            ans[i - k + 1] = nums[dq.front()];
        }
    }
    return ans;
}