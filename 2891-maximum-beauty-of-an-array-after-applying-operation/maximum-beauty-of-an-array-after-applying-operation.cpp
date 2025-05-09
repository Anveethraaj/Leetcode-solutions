class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> events;

        for (int num : nums) {
            events[num - k]++;      // interval starts
            events[num + k + 1]--;  // interval ends
        }

        int maxBeauty = 0, current = 0;
        for (auto& [pos, change] : events) {
            current += change;
            maxBeauty = max(maxBeauty, current);
        }

        return maxBeauty;
    }
};
