class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> output;
        for (int i = 0; i < asteroids.size(); i++) {
            bool destroyed = false;
            while (!output.empty() && output.back() > 0 && asteroids[i] < 0) {
                if (output.back() < abs(asteroids[i])) {
                    output.pop_back();
                    continue;
                } else if (output.back() == abs(asteroids[i])) {
                    output.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                output.push_back(asteroids[i]);
            }
        }
        return output;
    }
};
