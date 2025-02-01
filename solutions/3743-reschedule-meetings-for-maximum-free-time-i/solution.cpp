class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = (int)startTime.size();
        if(n == 0) return eventTime;

        vector<long long> durations(n);
        for(int i = 0; i < n; i++) {
            durations[i] = (long long)endTime[i] - startTime[i];
        }
        vector<long long> pref(n+1, 0LL);
        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + durations[i];
        }

        vector<long long> A(n), B(n);
        for(int j = 0; j < n; j++) {
            A[j] = (long long)startTime[j] - pref[j];
            B[j] = (long long)endTime[j] - pref[j+1];
        }

        long long bestGap = 0;

        for(int i = 0; i < min(n, k+1); i++){
            long long cand = (long long)startTime[i] - pref[i];
            bestGap = max(bestGap, cand);
        }

        for(int j = 0; j < n; j++){
            if((n - j - 1) <= k){
                long long cand = (long long)eventTime - endTime[j] - (pref[n] - pref[j+1]);
                bestGap = max(bestGap, cand);
            }
        }

        // Deque approach to combine movements.
        deque<int> dq;
        for(int j = 1; j < n; j++){
            int L = max(0, j - k - 1);
            while(!dq.empty() && dq.front() < L) {
                dq.pop_front();
            }
            int idxNew = j - 1;
            while(!dq.empty() && B[dq.back()] >= B[idxNew]) {
                dq.pop_back();
            }
            dq.push_back(idxNew);
            long long cand = A[j] - B[dq.front()];
            bestGap = max(bestGap, cand);
        }

        // If we can move all meetings.
        if(n <= k){
            bestGap = max(bestGap, (long long)eventTime - pref[n]);
        }

        // Original maximum gap if we don't move any meetings.
        long long origGap = 0;
        if(n > 0){
            origGap = max((long long)startTime[0], (long long)eventTime - endTime[n-1]);
            for(int i = 1; i < n; i++){
                origGap = max(origGap, (long long)startTime[i] - endTime[i-1]);
            }
        } else {
            origGap = eventTime;
        }
        bestGap = max(bestGap, origGap);

        return (int)max(bestGap, 0LL);
    }
};
