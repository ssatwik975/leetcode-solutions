class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int size = s1.size();
        if (size != s2.size()) return false;
        int pointer1 = -1;
        int mistakes = 0;
        for (int i = 0; i < size; i++){
            if(s1[i] != s2[i]){
                mistakes++;
                if(pointer1 == -1){
                    pointer1 = i;
                }else{
                    if(s1[pointer1] == s2[i] && s1[i] == s2[pointer1]){
                        continue;
                    }else{
                        return false;
                    }
                }
            }
        }
        if(mistakes == 2 || mistakes == 0) return true;
        return false;
    }
};
