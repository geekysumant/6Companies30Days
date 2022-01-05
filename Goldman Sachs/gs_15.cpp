bool canPair(vector<int> nums, int k) {
    // Code here
    if (nums.size() % 2 != 0)
        return 0;
    unordered_map<int, int>map;
    bool zero = 1;
    for (auto &x : nums) {
        x %= k;
        map[x]++;
        if (x != 0)
            zero = 0;
    }
    if (zero)return 1;

    for (auto &x : map) {
        if (x.first == 0 && map[x.first] % 2 != 0)
            return 0;
        if (map[x.first] != map[(k - x.first) % k] )
            return 0;
    }
    return 1;
}