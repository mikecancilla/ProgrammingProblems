/*
This problem was asked by Stripe.

Write a map implementation with a get function that lets you retrieve the value of a key at a particular time.

It should contain the following methods:

set(key, value, time): sets key to value for t = time.
get(key, time): gets the key at t = time.
The map should work like this. If we set a key at a particular time, it will maintain that value forever or until it gets set at a later time. In other words, when we get a key at a time, it should return the value that was set for that key set at the most recent time.

Consider the following examples:

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2
d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2
*/

/*
#include <set>
#include <map>

struct value_time
{
    int value;
    int time;
};

typedef std::map<int, int> kv;
typedef std::map<kv, int> kvt;

class kvt_map
{
    kvt m_mvt;

public:
    void set(int k, int v, int t);
    kv get(int k, int t);
};

void kvt_map::set(int k, int v, int t)
{
    kv insert_me(k, v);

    auto search = m_mvt.find(insert_me);
    //if(search != insert_me.end())

}

kv kvt_map::get(int k, int v)
{
}

void DoKeyValueTime()
{
    kvt_map d;


}
*/