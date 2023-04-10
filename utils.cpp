#include <vector>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node{
public:
    int val = -1;               //representacion del nodo, la "letra"
    int acum = 0;               //valor de costo acumulado 
    vector<int> route;          //ruta recorrida

    bool operator < (const Node &comp) const{       //operador de comparacion para la prioQueue
        return acum > comp.acum;
    }
};

#endif