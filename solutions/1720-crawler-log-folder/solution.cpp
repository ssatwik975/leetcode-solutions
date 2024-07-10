class Solution {
public:
    int minOperations(vector<string>& logs) {
        int x = 0;
        for(auto s : logs){
            if(s == "../"){
                if(x){
                    x--;
                }
            }else if(s != "./"){
                x++;
            }
        }
        return x;
        
    }
};
