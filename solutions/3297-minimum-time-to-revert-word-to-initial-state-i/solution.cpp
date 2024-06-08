class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        
        int n = word.length();
        int count = 1;
        for(int i = k; i < n; i+=k){
            if (word.compare(i, n-i, word, 0, n-i) == 0)
                break;
            count++;
        }
        return count;
    }
};
