class MyHashMap {
public:
    int Table[1000005];
    MyHashMap() {
        memset(Table,-1,sizeof(Table));
    }
    
    void put(int key, int value) {
      Table[key] = value;
    }
    
    int get(int key) {
        return Table[key];
    }
    
    void remove(int key) {
        Table[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */