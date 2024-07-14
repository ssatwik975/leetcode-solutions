int speedup = []{ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;}();

class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string, int> count;
        stack<unordered_map<string, int>> st;
        st.push({}); 

        int i = 0, n = formula.length();
        while (i < n) {
            if (isupper(formula[i])) {
                string element;
                element += formula[i];
                i++;
                while (i < n && islower(formula[i])) {
                    element += formula[i];
                    i++;
                }

                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                if (num == 0) num = 1;
                st.top()[element] += num;

            } else if (formula[i] == '(') {
                st.push({});
                i++;

            } else if (formula[i] == ')') {
                i++;
                int num = 0;
                while (i < n && isdigit(formula[i])) {
                    num = num * 10 + (formula[i] - '0');
                    i++;
                }
                if (num == 0) num = 1;

                auto scope = st.top();
                st.pop();
                for (auto& pair : scope) {
                    st.top()[pair.first] += pair.second * num;
                }

            } else {
                i++;
            }
        }


        vector<pair<string, int>> atoms(st.top().begin(), st.top().end());
        sort(atoms.begin(), atoms.end());

        string answer;
        for (const auto& pair : atoms) {
            answer += pair.first;
            if (pair.second > 1) {
                answer += to_string(pair.second);
            }
        }

        return answer;
    }
};
