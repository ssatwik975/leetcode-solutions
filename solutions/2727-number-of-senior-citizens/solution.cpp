class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(const string k : details){
            if(k[11]-'6' > 0){
                ++count;
            }else if(k[11]-'6' == 0){
                if(k[12] -'0' > 0){
                    ++count;
                }
            }
        }
        return count;
    }
};
