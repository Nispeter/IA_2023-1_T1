#include <iostream>
#include <vector>
#include <time.h>
#include <map>

using namespace std;

#ifndef DFS_H
#define DFS_H

class DFS{
private:
    int init,goal;              //nodo de inicio y final 
    int cont;                   //contador de costo
    vector<vector<int>> cost;   //matriz de costos
    vector<int> visited;        //vector de nodos visitados
    vector<int> secuence;       //vector de secuencia de busqueda
    map<char,int> exp;          //mapa de nodos expandidos

public: 
    DFS(const int &init,const int &goal, const vector<vector<int>> &cost );
    bool RandomSearch(int node);
    void PrintData();
};

#endif