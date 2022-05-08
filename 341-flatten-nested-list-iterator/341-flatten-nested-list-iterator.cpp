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
void func(vector<int> &res,vector<NestedInteger>&ns){
    for(auto data : ns){
        if(data.isInteger()){
            res.push_back(data.getInteger());
        }
        else{
            func(res,data.getList());
        }
    }
}
class NestedIterator {
public:
    vector<int> res;
    int start;
    NestedIterator(vector<NestedInteger> &nestedList) {
        func(res,nestedList);
        start = 0;
    }
    
    int next() {
        return res[start++];
    }
    
    bool hasNext() {
        return start < res.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */