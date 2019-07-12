/*
    This problem was asked by Google.

    Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:

    set(key, value): sets key to value. If there are already n items in the cache and we are adding a new item, then it should also remove the least recently used item.
    get(key): gets the value at key. If no such key exists, return null.

    Each operation should run in O(1) time.
*/

// We can use stl container list as a double 
// ended queue to store the cache keys, with 
// the descending time of reference from front 
// to back and a set container to check presence 
// of a key. But to fetch the address of the key 
// in the list using find(), it takes O(N) time. 
// This can be optimized by storing a reference 
//     (iterator) to each key in a hash map. 

#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <string>

struct KV
{
    int key;
    std::string value;

    KV(int key, std::string value) :
        key(key) ,
        value(value)
    {}
};

class LRUCache { 
    // store keys of cache 
    std::list<KV> m_dq; 
  
    // store references of key in cache 
    std::unordered_map<int, std::list<KV>::iterator> m_hashTable; 
    int m_cacheSize; // maximum capacity of cache 
  
public: 
    LRUCache(int); 
    void refer(int); 
    void display(); 
    void set(int key, std::string value);
    std::string get(int key);
}; 
  
// Declare the size 
LRUCache::LRUCache(int n) 
{ 
    m_cacheSize = n; 
}

void LRUCache::set(int key, std::string value)
{
    KV kv(key, value);

    // not present in cache 
    if (m_hashTable.find(key) == m_hashTable.end()) { 
        // cache is full 
        if (m_dq.size() == m_cacheSize) { 
            // delete least recently used element 
            KV last = m_dq.back(); 
  
            // Pops the last elmeent 
            m_dq.pop_back(); 
  
            // Erase the last 
            m_hashTable.erase(last.key); 
        } 
    } 
    else // present in cache 
        m_dq.erase(m_hashTable[key]); 
  
    // update reference 
    m_dq.push_front(kv); 
    m_hashTable[kv.key] = m_dq.begin(); 
}

std::string LRUCache::get(int key)
{
    std::unordered_map<int, std::list<KV>::iterator>::iterator i = m_hashTable.find(key);
    if (i == m_hashTable.end())
        return "";

    KV kv = *(i->second);
    m_dq.erase(m_hashTable[key]);

    // update reference 
    m_dq.push_front(kv); 
    m_hashTable[key] = m_dq.begin();

    return kv.value;
}
  
// Function to display contents of cache 
void LRUCache::display() 
{ 
  
    // Iterate in the deque and print 
    // all the elements in it 
    for (auto it = m_dq.begin(); it != m_dq.end(); it++) 
        std::cout << "Key:" << it->key << " Value:" << it->value << std::endl; 
} 
  
void DoLRUCache() 
{ 
    LRUCache ca(4); 
  
    ca.set(1, "foo"); 
    ca.set(3, "bar"); 
    ca.set(5, "baz"); 
    ca.set(9, "pop");
    std::string s = ca.get(3);
    ca.display(); 
} 