class Solution {
public:
    long long cnt[16] = {};
    long long dfs(int i, char limit, const string& n, const string& s) {
        if (n.size() < s.size())
            return 0;
        if (i == n.size() - s.size())
            return n.substr(i) >= s;
        int digits = min(limit, n[i]) - '1' + (i > 0);
        return cnt[n.size() - i - 1] * digits +
               (n[i] < limit ? dfs(i + 1, limit, n, s) : 0);
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  const string& s) {
        string hi = to_string(finish), lo = to_string(start - 1);
        for (int i = s.size(); i < hi.size(); ++i)
            cnt[i] = i == s.size() ? 1 : cnt[i - 1] * (limit + 1);
        return cnt[hi.size() - 1] + dfs(0, '1' + limit, hi, s) -
               (cnt[lo.size() - 1] + dfs(0, '1' + limit, lo, s));
    }
};
