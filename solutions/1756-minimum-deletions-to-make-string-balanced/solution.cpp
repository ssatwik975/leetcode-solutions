class Solution {
public:
    int minimumDeletions(string s) {
        int as = 0, bs = 0, bl = 0, temp = 0;
        int fault = INT_MAX;

        for(char c : s){
            if(c == 'a') as++;
            else bs++;
        }

        if(as == 0 || bs == 0) return 0;

        for(char c : s){
            if(c == 'b') bl++;
            else temp++;
            int ar = as - temp;
            fault = min(fault, ar + bl);
        }
        
        // Final check if all 'b's are left as is
        fault = min(fault, as);

        return fault;
    }
};

