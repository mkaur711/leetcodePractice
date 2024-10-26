class Solution {
public:
    string simplifyPath(string path) {
         std::vector<std::string> stack; // Stack to store valid directory names
    std::stringstream ss(path);
    std::string part;

    // Split path by '/' and process each part
    while (std::getline(ss, part, '/')) {
        if (part == "" || part == ".") {
            // Skip empty parts and current directory (.)
            continue;
        } else if (part == "..") {
            // Go up one level if possible
            if (!stack.empty()) {
                stack.pop_back();
            }
        } else {
            // Valid directory or file name, add to stack
            stack.push_back(part);
        }
    }

    // Construct the simplified path
    std::string result = "/";
    for (size_t i = 0; i < stack.size(); ++i) {
        result += stack[i];
        if (i < stack.size() - 1) {
            result += "/";
        }
    }

    return result;
    }
};