int *findTwoElement(int *arr, int n) {
    // code here
    int rep = -1, miss = -1;
    for (int i = 0; i < n; i++) {
        arr[abs(arr[i]) - 1] *= -1;
        if (arr[abs(arr[i]) - 1] > 0 && rep == -1) {
            rep = arr[i];
        }

    }
    arr[abs(rep) - 1] *= -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 ) {
            miss = i + 1;
            break;
        }
    }
    int *ans = new int[2];
    ans[0] = abs(rep);
    ans[1] = miss;

    return ans;

}