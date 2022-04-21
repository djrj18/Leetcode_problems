class MyHashSet {
public:
    int tableSize = 139;
    vector<int> Table[139];
    MyHashSet() {
        
    }
    
    void add(int key) {
        int index = key%tableSize;
        if(!contains(key)){
            Table[index].push_back(key);
        }
    }
    
    void remove(int key) {
         int index = key%tableSize;
         for(int i = 0;i<Table[index].size();i++){
             if(Table[index][i] == key){
                 int j = i;
                 while(j < Table[index].size()-1){
                     Table[index][j] = Table[index][j+1];
                     j++;
                 }
                 Table[index].pop_back();
                 break;
             }
         }
    }
    
    bool contains(int key) {
        int index = key%tableSize;
        for(int i = 0;i<Table[index].size();i++){
            if(Table[index][i] == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */