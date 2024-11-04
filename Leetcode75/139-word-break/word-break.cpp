#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(const std::string& s, const std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
        std::queue<int> queue;
        std::unordered_set<int> visited;

        queue.push(0);

        while (!queue.empty()) {
            int start = queue.front();
            queue.pop();

            if (visited.count(start)) {
                continue;
            }
            visited.insert(start);

            for (int end = start + 1; end <= s.length(); ++end) {
                if (word_set.count(s.substr(start, end - start))) {
                    if (end == s.length()) {
                        return true;
                    }
                    queue.push(end);
                }
            }
        }
        return false;
    }

    
};
