class Solution {
public:
    int passThePillow(int n, int time) {
        int mod = time % (n-1);
        if((time/(n-1))%2){
            return n - mod;
        }
        return mod+1;
    }
};
