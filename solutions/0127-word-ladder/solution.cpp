class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //make a set
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        // push first word in queue with 1 step and remove word from set so as to not repeat
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(endWord == word) return steps;
            
            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                //replacing ith char with every letter;
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                //putting it back to original
                word[i] = original;
            }
        }

        return 0;

    }
};
