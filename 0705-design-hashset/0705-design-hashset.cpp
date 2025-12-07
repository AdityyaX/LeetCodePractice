class MyHashSet {
    /*
    this one is brute force approach to solve the question of hashset*/
public:
    vector<int> arr;
    MyHashSet() {}

    void add(int key) {
        if (find(arr.begin(), arr.end(), key) == arr.end()) {
            arr.push_back(key);
        }
    }

    void remove(int key) {
        auto it = find(arr.begin(), arr.end(), key);
        if (it != arr.end()) {
            arr.erase(it);
        }
    }

    bool contains(int key) {
        return find(arr.begin(), arr.end(), key) != arr.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */