class LRUCache{
private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v): key(k), value(v) {}
    };
    
    int m_capacity;
    unordered_map<int, list<CacheNode>::iterator> m_cmap;
    list<CacheNode> m_clist;
    
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (m_cmap.find(key) == m_cmap.end()) {
            return -1;
        } else {
            m_clist.splice(m_clist.begin(), m_clist, m_cmap[key]);
            m_cmap[key] = m_clist.begin();
            return m_cmap[key]->value;
        }
    }
    
    void set(int key, int value) {
        if (m_cmap.find(key) == m_cmap.end()) {
            if (m_clist.size() == m_capacity) {
                m_cmap.erase(m_clist.back().key);
                m_clist.pop_back();
            }
            m_clist.push_front(CacheNode(key, value));
            m_cmap[key] = m_clist.begin();
        } else {
            m_cmap[key]->value = value;
            m_clist.splice(m_clist.begin(), m_clist, m_cmap[key]);
            m_cmap[key] = m_clist.begin();
        }
        
    }
};