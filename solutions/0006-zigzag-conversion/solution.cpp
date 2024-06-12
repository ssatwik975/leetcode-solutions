class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows > s.size()) return s;
                
        vector<string> rows(numRows);
        
        int currentrow = 0;
        bool neeche = false;
        
        for (char c : s) {
            rows[currentrow] += c;
            if (currentrow == 0 || currentrow == numRows - 1) neeche = !neeche;
            currentrow += neeche ? 1 : -1;
        }
                
        string result;
        for (const string& c : rows) {
            result += c;
        }
        return result;
    }
};
