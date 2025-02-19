class Solution {
public:
    string getHappyString(int n, int k) {
        stack<string> stringsStack;
        int indexInSortedList = 0;
        stringsStack.push("");  // Start with an empty string

        while (stringsStack.size() > 0) {
            string currentString = stringsStack.top();
            stringsStack.pop();

            // If we have built a string of length n, count it
            if (currentString.size() == n) {
                indexInSortedList++;
                // If we reach the k-th happy string, return it
                if (indexInSortedList == k) {
                    return currentString;
                }
                continue;
            }

            // Expand the current string by adding 'a', 'b', or 'c'
            // Ensuring lexicographic order by pushing in reverse
            for (char currentChar = 'c'; currentChar >= 'a'; currentChar--) {
                // Avoid consecutive identical characters
                if (currentString.size() > 0 &&
                    currentString.back() == currentChar)
                    continue;
                stringsStack.push(currentString + currentChar);
            }
        }
        return "";
    }
};
