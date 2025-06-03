class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, 
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> hasKey(n, false);
        vector<bool> hasBox(n, false);
        vector<bool> opened(n, false);
        queue<int> q;

        // Initially, mark the boxes we have
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) {
                q.push(box);
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();

            if (opened[box]) continue;
            opened[box] = true;

            totalCandies += candies[box];

            // Collect keys
            for (int key : keys[box]) {
                if (!hasKey[key]) {
                    hasKey[key] = true;
                    if (hasBox[key] && !opened[key]) {
                        q.push(key);
                    }
                }
            }

            // Collect contained boxes
            for (int contained : containedBoxes[box]) {
                if (!hasBox[contained]) {
                    hasBox[contained] = true;
                }
                if ((status[contained] == 1 || hasKey[contained]) && !opened[contained]) {
                    q.push(contained);
                }
            }
        }

        return totalCandies;
    }
};
