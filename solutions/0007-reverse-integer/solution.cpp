class Solution {
public:
    int reverse(int x) {
        
        int lastdigit = 0;
        while(x){
            if( lastdigit>INT_MAX/10 || lastdigit<INT_MIN/10) return 0;
            lastdigit = lastdigit*10 + x%10;
            x = x/10;
        }
        return lastdigit;
    }
};
