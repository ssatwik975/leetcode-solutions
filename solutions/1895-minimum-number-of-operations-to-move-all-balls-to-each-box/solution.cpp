class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>position;
        for(int i =0;i<boxes.size();i++){
            if(boxes[i]=='1'){
                position.push_back(i);
            }
        }
        vector<int>minoperations;
        for(int i =0;i<boxes.size();i++){
            int operations=0;
            for(int j =0;j<position.size();j++){
                operations+=abs(position[j]-i);
            }
            minoperations.push_back(operations);
        }
        return minoperations;
    }
};
