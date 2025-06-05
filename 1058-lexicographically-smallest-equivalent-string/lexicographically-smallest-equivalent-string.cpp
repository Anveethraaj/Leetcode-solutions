class Solution {
public:
    int parent[26];

    // Find function with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union function to link two characters
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        // Always attach the larger to the smaller to keep lex smallest
        if (px < py) parent[py] = px;
        else parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // Initialize parent array
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // Union equivalent characters
        for (int i = 0; i < s1.length(); i++) {
            unite(s1[i] - 'a', s2[i] - 'a');
        }

        // Build the smallest equivalent string
        string result = "";
        for (char c : baseStr) {
            result += (char)(find(c - 'a') + 'a');
        }

        return result;
    }
};
