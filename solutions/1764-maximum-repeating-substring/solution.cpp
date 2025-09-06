class Solution {
public:
    int maxRepeating(string& sequence, string& word) {
        int res{}; // short form of res = 0
        string check = word;

        while(sequence.find(check) != string::npos){

            ++res;
            check += word;
        }

        return res;
    }
};
