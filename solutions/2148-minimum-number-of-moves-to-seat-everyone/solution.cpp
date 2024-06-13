class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = seats.size();
        vector<int> seatCount(101, 0);
        vector<int> studentCount(101, 0);
        
        for(const int& seat : seats) {
            seatCount[seat]++;
        }
        for(const int& student : students) {
            studentCount[student]++;
        }

        
        int seatIndex = 0, studentIndex = 0;
        for(int i = 0; i < 101; ++i) {
            while(seatCount[i] > 0) {
                seats[seatIndex++] = i;
                seatCount[i]--;
            }
            while(studentCount[i] > 0) {
                students[studentIndex++] = i;
                studentCount[i]--;
            }
        }

        
        int minMoves = 0;
        for(int i = 0; i < n; ++i) {
            minMoves += abs(seats[i] - students[i]);
        }

        return minMoves;
    }
};
