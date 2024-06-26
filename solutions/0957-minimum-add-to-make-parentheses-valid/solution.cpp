class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> ss;
        int count = 0;
        for(char c: s){
            if(ss.empty()){
                if(c=='('){
                    ss.push(c);
                }else{
                    count++;
                }
                
            }else if(ss.top() != c){
                ss.pop();
            }else{
                ss.push(c);
            }
        }
        count += ss.size();
        return count;
    }
};
