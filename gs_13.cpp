string repeat(string s, int times) {
    string temp = "";
    while (times--)
        temp += s;
    return temp;

}
string help(string str, int &i) {
    string ans = "";
    while (i < str.length() && str[i] != ']') {
        for (; i < str.length() && isalpha(str[i]); i++)
            ans += str[i];

        if (i >= str.length() || str[i] == ']')
            continue;
        string n = "";
        for (; i < str.length() && isdigit(str[i]); i++)
            n += str[i];
        i++;
        string rep = help(str, i);
        ans += repeat(rep, stoi(n));
        i++;
    }
    return ans;
}
string decodeString(string s) {
    int i = 0;
    return help(s, i);
}