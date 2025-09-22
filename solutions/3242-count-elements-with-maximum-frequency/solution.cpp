class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencies;
        int maxFrequency = 0;
        int totalFrequencies = 0;

        // Find the frequency of each element
        // Determine the maximum frequency
        // Calculate the total frequencies of elements with the maximum frequency
        for (int num : nums) {
            frequencies[num]++;
            int frequency = frequencies[num];

            // If we discover a higher frequency element
            // Update maxFrequency
            // Re-set totalFrequencies to the new max frequency
            if (frequency > maxFrequency) {
                maxFrequency = frequency;
                totalFrequencies = frequency;
                // If we find an element with the max frequency, add it to the total
            } else if (frequency == maxFrequency) {
                totalFrequencies += frequency;
            }
        }
        return totalFrequencies;
    }
};
