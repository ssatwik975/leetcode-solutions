class Solution {
public:
    string longestDiverseString(int a, int b, int c, char aa = 'a',
                                char bb = 'b', char cc = 'c') {
        if (a < b)
            return longestDiverseString(b, a, c, bb, aa, cc);
        if (b < c)
            return longestDiverseString(a, c, b, aa, cc, bb);
        if (b == 0)
            return string(min(2, a), aa);
        auto use_a = min(2, a), use_b = a - use_a >= b ? 1 : 0;
        return string(use_a, aa) + string(use_b, bb) +
               longestDiverseString(a - use_a, b - use_b, c, aa, bb, cc);
    }
};
