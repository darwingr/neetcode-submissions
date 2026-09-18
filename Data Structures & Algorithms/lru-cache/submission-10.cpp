// need
//  move_to_front(key)
//  evict_last()
//      - track last
class LRUCache {
    struct Node {
        int key = 0;
        int value = 0;
        Node* prev = nullptr;
        Node* next = nullptr;

        void unlink() {
            if (prev)
                prev->next = next;
            if (next)
                next->prev = prev;
            prev = nullptr;
            next = nullptr;
        }
        void append(Node* tail) {
            if (!tail) return;
            Node* body = this;
            while (body->next)
                body = body->next;
            body->next = tail;
            tail->prev = body;
        }
    };
    const int cap = 0;
    unordered_map<int,Node*> cache_map;
    Node* dll = nullptr;

public:
    LRUCache(int capacity) :
        cap(capacity)
    {
    }
    
    int get(int key) {
        if (cache_map.contains(key)) {
            if (cache_map[key] != dll) {
                Node* new_head = cache_map[key];
                new_head->unlink();
                new_head->append(dll);
                dll = new_head;
            }
            return cache_map[key]->value;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if (cache_map.contains(key)) {
            cache_map[key]->value = value;
            // put to front
            if (cache_map[key] != dll) {
                Node* new_head = cache_map[key];
                new_head->unlink();
                new_head->append(dll);
                dll = new_head;
            }
        // NEW KEY
        } else {
            cache_map[key] = new Node();
            cache_map[key]->key = key;
            cache_map[key]->value = value;
            cache_map[key]->append(dll);
            dll = cache_map[key];
            // evict last!
            // O(N)
            if (cache_map.size() > cap) {
                Node* tail = dll;
                while (tail->next)
                    tail = tail->next;
                tail->unlink();
                // remove from cache map
                cache_map.erase(tail->key);
                delete tail;
            }
        }
    }
};
