class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirStack;
        stringstream ss(path);
        string token;

    while (getline(ss, token, '/')) {
        if (token == "" || token == ".") {
            continue; // Skip empty and current directory tokens
        } else if (token == "..") {
            if (!dirStack.empty()) {
                dirStack.pop(); // Go up one directory level
            }
        } else {
            dirStack.push(token); // Add directory to the stack
        }
    }

    string simplifiedPath;
    while (!dirStack.empty()) {
        simplifiedPath = "/" + dirStack.top() + simplifiedPath;
        dirStack.pop();
    }

    return simplifiedPath.empty() ? "/" : simplifiedPath;
    }
};