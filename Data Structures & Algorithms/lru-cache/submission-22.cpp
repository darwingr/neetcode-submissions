// DLL/hashmap with dummy head/tail
class LRUCache {
    struct dll {
        int key = -1;
        int val = -1;
        dll* prev = nullptr;
        dll* next = nullptr;
    };

    unordered_map<int,dll*> cache;
    dll* most_recent;
    dll* least_recent;
    const int cap;

public:
    LRUCache(int capacity) :
        cap{capacity}
    {
        most_recent = new dll;
        least_recent = new dll;
        most_recent->next = least_recent;
        least_recent->prev = most_recent;
    }
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;
        if (most_recent->next != cache[key]) {
            moveToFront(cache[key]);
        }
        return most_recent->next->val;
    }
    
    void put(int key, int value) {
        if (!cache.contains(key)) {
            if (cache.size() == cap) {
                dll* tmp = least_recent->prev;
                cache.erase(tmp->key);
                remove(tmp);
                delete tmp;
            }
            dll* node = new dll;
            node->key = key;
            cache[key] = node;
            insert(node);
        } else if (cache[key] != most_recent->next)
            moveToFront(cache[key]);
        
        most_recent->next->val = value;
    }

private:
    void moveToFront(dll* node) {
        remove(node);
        insert(node);
    }

    void insert(dll* node) {
        node->next = most_recent->next;
        most_recent->next->prev = node;
        node->prev = most_recent;
        most_recent->next = node;
    }

    void remove(dll* node) {
        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
    }
};
