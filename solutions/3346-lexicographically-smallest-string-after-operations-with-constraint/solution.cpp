class Solution
{
public:
    string getSmallestString(string s, int k)
    {
        ios::sync_with_stdio(0); cin.tie(0);
        string ans = s;
        for (char &ch : s)
        {
            int left = ch - 'a';
            int right = 'z' - ch + 1;
            int minm = min(left, right);
            if (k >= minm)
            {
                k -= minm;
                ch = 'a';
            }
            else
            {
                ch = ch - k;
                break;
            }
        }
        return s;
    }
};
