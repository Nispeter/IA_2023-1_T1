#include <vector>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node{
public:
    int val = -1;
    int acum = 0;
    vector<int> route;

    bool operator < (const Node &comp) const{
        return acum > comp.acum;
    }
};

#endif