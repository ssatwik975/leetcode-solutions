int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstcrit = -1;
        int lastcrit = -1;
        int tempcrit1 = -1;
        int tempcrit2 = -1;

        ListNode* prev = head;
        ListNode* temp = head->next;
        ListNode* forward = head->next->next;

        if (!forward) {
            return {-1, -1};
        }
        
        int mindis = INT_MAX;
        bool crit = false;
        int count = 2;

        while (forward) {
            if ((prev->val < temp->val && temp->val > forward->val) ||
                (prev->val > temp->val && temp->val < forward->val)) {
                crit = true;
            }

            if (crit) {
                if (firstcrit == -1) {
                    firstcrit = count;

                } else {
                    tempcrit1 = tempcrit2;
                    tempcrit2 = lastcrit;
                    lastcrit = count;
                }

                int dist1 = (tempcrit1 > 0) ? (tempcrit1 - firstcrit) : INT_MAX;
                int dist2 = (tempcrit1 > 0 && tempcrit2 > 0) ? (tempcrit2 - tempcrit1) : INT_MAX;
                int dist3 = (lastcrit > 0 && tempcrit2 > 0) ? (lastcrit - tempcrit2) : INT_MAX;
                int dist4 = (lastcrit > 0 && firstcrit > 0) ? (lastcrit - firstcrit) : INT_MAX;
                mindis = min({mindis, dist1, dist2, dist3, dist4});
            }

            count++;
            prev = temp;
            temp = forward;
            forward = forward->next;
            crit = false;
        }

        if (firstcrit == -1 || lastcrit == -1 || firstcrit == lastcrit) {
            return {-1, -1};
        }

        int maxdis = lastcrit - firstcrit;
        return {mindis,maxdis};
    }
};
