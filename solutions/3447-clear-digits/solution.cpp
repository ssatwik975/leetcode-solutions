class Solution {
public:
    string clearDigits(string s) {
    string res;
    for (char ch : s)
        if (isdigit(ch))
            res.pop_back();
        else
            res += ch;
    return res;
}
};
