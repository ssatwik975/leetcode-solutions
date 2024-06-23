class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0; // Minimum open parentheses needed
        int maxOpen = 0; // Maximum open parentheses possible
        
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--; // Treat '*' as ')'
                maxOpen++; // Treat '*' as '('
            }
            
            // minOpen should not be less than 0
            if (minOpen < 0) {
                minOpen = 0;
            }
            
            // If maxOpen is less than 0, it means we have more ')' than we can handle
            if (maxOpen < 0) {
                return false;
            }
        }
        
        // If minOpen is 0, we can balance all open parentheses
        return minOpen == 0;
    }
};

