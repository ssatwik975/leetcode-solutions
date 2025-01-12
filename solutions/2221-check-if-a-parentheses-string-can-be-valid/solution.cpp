class Solution {
public:
    bool canBeValid(string s, string locked) {
        auto validate = [&](char op) {
            int bal = 0, wild = 0, sz = s.size();
            int start = op == '(' ? 0 : sz - 1, dir = op == '(' ? 1 : -1;
            for (int i = start; i >= 0 && i < sz && wild + bal >= 0; i += dir)
                if (locked[i] == '1')
                    bal += s[i] == op ? 1 : -1;
                else
                    ++wild;
            return abs(bal) <= wild;
        };
        return s.size() % 2 == 0 && validate('(') && validate(')');
    }
};
