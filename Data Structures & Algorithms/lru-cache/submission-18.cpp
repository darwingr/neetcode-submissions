class LRUCache {
    struct dll {
        int key = -1;
        int val = -1;
        dll* prev = nullptr;
        dll* next = nullptr;
    };

    unordered_map<int, dll*> cache;
    dll* most_recent = nullptr;
    dll* least_recent = nullptr;
    const int cap;

public:
    LRUCache(int capacity) :
        cap{capacity}
    {}
    
    int get(int key) {
        if (!cache.contains(key))
            return -1;

        if (cache[key] != most_recent) {
            remove(cache[key]);
            insert(cache[key]);
        }
        
        return most_recent->val;
    }
    
    void put(int key, int value) {
        if (!cache.contains(key)) {
            // remove last?
            if (cache.size() == cap) {
                dll* tmp = least_recent;
                cache.erase(tmp->key);
                remove(tmp);
                //if (most_recent == least_recent) {
                //    most_recent = nullptr;
                //    least_recent = nullptr;
                //} else {
                //    least_recent->prev->next = nullptr;
                //    least_recent = least_recent->prev;
                //}
                delete tmp;
            }
            // create new
            dll* node = new dll;
            node->key = key;
            cache[key] = node;
            insert(cache[key]);
        } else if (cache[key] != most_recent) {
            remove(cache[key]);
            insert(cache[key]);
        }
        
        // update front values
        most_recent->val = value;
    }
private:
    // assumes node has nullptr next/prev
    void insert(dll* node) {
        if (!least_recent) {
            least_recent = node;
            least_recent->next = nullptr;
        }
        node->prev = nullptr;
        if (most_recent) {
            most_recent->prev = node;
            node->next = most_recent;
        }
        most_recent = node;
    }

    void remove(dll* node) {
        if (node->next) 
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;
        
        if (node == least_recent) {
            if (most_recent == least_recent) {
                most_recent = nullptr;
                least_recent = nullptr;
            } else {
                //node->prev->next = nullptr;
                least_recent = least_recent->prev;
            }
            return;
        }
        
        //if (node == most_recent) {
        //    most_recent = node->next;
        //    if (most_recent)
        //        most_recent->prev = nullptr;
        //}
    }
};
