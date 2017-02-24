class Solution {
    string path;
    int index;
    bool hasNextToken() {
        while (index < path.size() && path[index] == '/') //skip forward slashes
            index++;
        return index < path.size();
    }
    
    // always call after call to hasNextToken has returned true
    string getNextToken() {
        int low = index;
        int high = index;
        while (high < path.size() && path[high] != '/')
            high++;
        string s(path.begin() + low, path.begin() + high);
        index = high;
        return s;
    }
public:

    string simplifyPath(string p) {
        path = p;
        index = 0;
        string res = "";
        stack<string> path;
        while (hasNextToken()) {
            string token = getNextToken();
            
            if (token == ".") {
                continue;
            }
            else if (token == "..") {
                if (!path.empty())
                    path.pop();
            }
            else {
                path.push(token);
            }
        }
        while (!path.empty()) {
            string pathComponent = path.top(); path.pop();
            res = pathComponent + "/" + res;
        }
        if (res.size())
            res = res.substr(0, res.size() - 1);
            
        return "/" + res;
    }
};