class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
       int start = 0, max = 0;
        for(int end=0 ; end<A.size() ; end++){
            if(A[end]==0){
                K--;
            }
            while(0>K){
                if(A[start]==0){
                    K++;
                }
                start++;
            }
            max = std::max(max,end-start+1);
        }
        
        return max;
    }
};
