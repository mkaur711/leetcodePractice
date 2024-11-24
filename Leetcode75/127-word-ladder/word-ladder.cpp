class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end()); // Convert wordList to a set for O(1) lookups
        
        if (wordSet.find(endWord) == wordSet.end()) return 0; // If endWord isn't in the wordList, no sequence is possible

        queue<pair<string, int>> q; // BFS queue: stores the current word and transformation depth
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [currentWord, depth] = q.front();
            q.pop();

            // Try changing each character of the current word
            for (int i = 0; i < currentWord.size(); i++) {
                string temp = currentWord;

                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;

                    if (temp == currentWord) continue; // Skip if no change

                    if (temp == endWord) return depth + 1; // Found the shortest path

                    if (wordSet.find(temp) != wordSet.end()) {
                        q.push({temp, depth + 1}); // Add valid neighbor to the queue
                        wordSet.erase(temp); // Mark as visited by removing from the set
                    }
                }
            }
        }

        return 0; // No transformation sequence exists
    }
};