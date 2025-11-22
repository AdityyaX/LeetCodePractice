
class LRUCache {
    struct Node {
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };
    unordered_map<int, Node*> mpp;
    int capacity;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.count(key)) {
            Node* node = mpp[key];
            int res = node->val;
            deletenode(node);
            insertAtHead(node);
            return res;
        }
        return -1;
    }
    void insertAtHead(Node* node) {
        Node* first = head->next;
        node->next = first;
        node->prev = head;
        head->next = node;
        first->prev = node;
    }

    void deletenode(Node* node) {
        Node* currentPrev = node->prev;
        Node* currentNext = node->next;
        currentPrev->next = currentNext;
        currentNext->prev = currentPrev;
    }

    void put(int key, int value) {
        if (mpp.count(key)) {
            Node* node = mpp[key];
            node->val = value;

            deletenode(node);
            insertAtHead(node);
            return;
        }

        if (mpp.size() == capacity) {
            Node* last = tail->prev;
            mpp.erase(last->key);
            deletenode(last);
            delete last;
        }

        Node* node = new Node(key, value);
        insertAtHead(node);
        mpp[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */