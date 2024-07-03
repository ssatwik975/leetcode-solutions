class Solution {
public:
    bool rotateString(string A, string B) {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }
};



// class Solution {
//     public boolean rotateString(String A, String B) {
//         if(A == null || B == null) {
//             //throw exception on A and B both being null?
//             return false;
//         }
//         if(A.length() != B.length()) {
//             return false;
//         }
//         if(A.length() == 0) {
//             return true;
//         }
//         for(int i = 0; i < A.length(); i++) {
//             if(rotateString(A, B, i)) {
//                 return true;
//             }
//         }
//         return false;
//     }
    
//     private boolean rotateString(String A, String B, int rotation) {
//         for(int i = 0; i < A.length(); i++) {
//             if(A.charAt(i) != B.charAt((i+rotation)%B.length())) {
//                 return false;
//             }
//         }
//         return true;
//     }
// }
