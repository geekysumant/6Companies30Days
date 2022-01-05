int longestMountain(vector<int>& arr) {
    if (arr.size() < 3)
        return 0;
    int ans = 0, prev = 0;
    bool mt = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i - 1])
            continue;
        prev = i - 1;
        while (i < arr.size() && arr[i] > arr[i - 1])
            i++;
        if (i >= arr.size())
            continue;
        if (arr[i] < arr[i - 1]) {
            mt = 1;
        }
        while (i < arr.size() && arr[i] < arr[i - 1])
            i++;
        if (mt) {
            ans = max(ans, i - prev);
            mt = 0;
        }
        i--;
    }
    return ans;

}