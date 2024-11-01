class Solution {
public:
    std::string customSortString(std::string order, std::string s) {
        // Step 1: Create a frequency map for characters in `s`
        std::unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        // Step 2: Build the result using the `order`
        std::string result;
        for (char ch : order) {
            if (freqMap.find(ch) != freqMap.end()) {
                result.append(freqMap[ch], ch);  // Add `ch` freqMap[ch] times
                freqMap.erase(ch);               // Remove from map once added
            }
        }

        // Step 3: Add remaining characters not in `order`
        for (const auto& entry : freqMap) {
            result.append(entry.second, entry.first);  // Add remaining characters
        }

        return result;
    }
};