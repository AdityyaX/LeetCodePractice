class MyHashMap {
    /*
    here i have utilized vector for desigining hashset
    */

public:
    vector<int> map;

    MyHashMap() { map.resize(1000001, -1); }

    void put(int key, int value) {
        map[key] = value;
        return;
    }

    int get(int key) { return map[key]; }

    void remove(int key) {
        map[key] = -1;
        return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */