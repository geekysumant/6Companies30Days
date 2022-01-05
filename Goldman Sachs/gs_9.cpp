string printMinNumberForPattern(string s) {
    // code here
    int n = s.length();
    string ans = "";
    stack<int>st;
    int mn = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D') {
            st.push(mn);
            mn++;
        } else {
            st.push(mn);
            mn++;
            while (!st.empty()) {
                ans += (st.top() + '0');
                st.pop();
            }
        }
    }
    st.push(mn);
    while (!st.empty()) {
        ans += (st.top() + '0');
        st.pop();
    }

    return ans;

}