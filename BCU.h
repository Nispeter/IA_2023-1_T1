#include <iostream>
#include <vector> 
#include <queue>
#include <map>
#include "utils.cpp"

using namespace std;

#ifndef BCU_H
#define BCU_H

class BCU{
private:
    int init,goal;              //nodo de inicio y final 
    int cont;                   //contador de costo
    Node optimal;               //nodo que almacena la secuencia optima de nodos
    priority_queue<Node> p;     //cola de prioridades de costo de secuencia 
    vector<vector<int>> cost;   //matriz de costos
    vector<int> visited;        //vector de nodos visitados
    map<char,int> exp;          //mapa de nodos expandidos

public: 
    BCU(const int &init, const int &goal, const vector<vector<int>> &cost);
    void Search(const Node&);
    void PrintData();
    void InitInQueue(Node origin, int next);

};

#endif