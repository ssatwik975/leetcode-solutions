
class Solution {

public:

    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string, int> frequencyMap;

        // First pass: Populate the frequency map

        for (string& str : arr) {

            frequencyMap[str]++;

        }

        // Second pass: Find the k-th distinct string

        for (string& str : arr) {

            // Check if the current string is distinct

            if (frequencyMap[str] == 1) {

                k--;

            }

            // When k reaches 0, we have found the k-th distinct string

            if (k == 0) {

                return str;

            }

        }

        return "";

    }

};
        


