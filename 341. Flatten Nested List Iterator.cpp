/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    stack<vector<NestedInteger>> elements;
    stack<int> indices;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        elements.push(nestedList);
        indices.push(0);
    }

    int next() {
        vector<NestedInteger> topVector = elements.top();
        int index = indices.top();
        int val = topVector[index].getInteger();
        
        indices.pop();
        indices.push(index + 1);
        
        return val;
    }

    bool hasNext() {
        while (!elements.empty()) {
            vector<NestedInteger> topVector = elements.top();
            int index = indices.top();
            
            if (index == topVector.size()) {
                elements.pop();
                indices.pop();
            }
            else {
                NestedInteger cur = topVector[index];
                if (!cur.isInteger()) {
                    indices.pop();
                    indices.push(index + 1);
                    
                    elements.push(cur.getList());
                    indices.push(0);
                }
                else {
                    return true;
                }
            }
            
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */