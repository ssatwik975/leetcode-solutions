class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n + 1, 0); // Difference array, size n+1 for boundary handling
        
        // Build the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            if (direction == 1) {
                arr[start] += 1;
                arr[end + 1] -= 1;
            } else {
                arr[start] -= 1;
                arr[end + 1] += 1;
            }
        }
        
        // Compute the prefix sum to get the net shifts
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }
        
        // Apply the shifts to the string
        string result = s;
        for (int i = 0; i < n; i++) {
            int shift = arr[i] % 26; // Reduce shift to range [-25, 25]
            if (shift < 0) shift += 26; // Ensure positive shift
            result[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        
        return result;
    }
};



// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(nullptr);
//         int n = s.size();
//         vector<int> arr(n, 0);
//         for (int i = 0; i < shifts.size(); i++) {
//             for (int j = shifts[i][0]; j <= shifts[i][1]; j++) {
//                 if (shifts[i][2] == 1)
//                     arr[j]++;
//                 else
//                     arr[j]--;
//             }
//         }

//         string k = s;
//         for (int i = 0; i < n; i++) {
//             char c = k[i];
//             int dist = c - 'a';
//             dist = (dist + arr[i]) % 26;
//             if (dist < 0)
//                 dist += 26;
//             k[i] = 'a' + dist;
//         }

//         return k;
//     }
// };

// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         string k = s;
//         int n = shifts.size();
//         for(int i = 0; i < n; i++){
//             for(int j = shifts[i][0]; j <= shifts[i][1]; j++){
//                     char c = k[j];
//                     int dist = c - 'a';
//                     dist += 26;
//                 if(shifts[i][2] == 1){
//                     k[j] = 'a' + ((dist+1)%26);
//                 }else{
//                     k[j] = 'a' + ((dist-1)%26);
//                 }
//             }
//         }
//         return k;
//     }
// };
