class Solution {
public:
    // Helper function to calculate minimum stickers
int helper(vector<vector<int>>& stickerCounts, vector<int>& targetCount, unordered_map<string, int>& memo) {
    string key = "";
    for (int i = 0; i < 26; ++i) {
        if (targetCount[i] > 0) {
            key += string(targetCount[i], 'a' + i);
        }
    }
    if (key.empty()) return 0;
    if (memo.count(key)) return memo[key];

    int minStickers = INT_MAX;
    for (auto& sticker : stickerCounts) {
        if (sticker[key[0] - 'a'] == 0) continue; // Skip stickers that don't contribute
        vector<int> remainingTarget(26, 0);
        for (int i = 0; i < 26; ++i) {
            remainingTarget[i] = max(0, targetCount[i] - sticker[i]);
        }
        int result = helper(stickerCounts, remainingTarget, memo);
        if (result != -1) {
            minStickers = min(minStickers, 1 + result);
        }
    }

    memo[key] = (minStickers == INT_MAX) ? -1 : minStickers;
    return memo[key];
}

int minStickers(vector<string>& stickers, string target) {
    vector<vector<int>> stickerCounts(stickers.size(), vector<int>(26, 0));
    for (int i = 0; i < stickers.size(); ++i) {
        for (char c : stickers[i]) {
            stickerCounts[i][c - 'a']++;
        }
    }

    vector<int> targetCount(26, 0);
    for (char c : target) {
        targetCount[c - 'a']++;
    }

    unordered_map<string, int> memo;
    return helper(stickerCounts, targetCount, memo);
}
};