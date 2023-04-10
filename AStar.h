#include <iostream>
#include <vector> 
#include <queue>
#include <map>
#include "utils.cpp"

using namespace std;

#ifndef ASTAR_H
#define ASTAR_H

class AStar{
private:
    int init,goal;                  //nodo de inicio y final 
    int cont;                       //contador de costo
    Node optimal;                   //nodo que almacena la secuencia optima de nodos
    priority_queue<Node> p;         //cola de prioridades de costo de secuencia 
    vector<vector<int>> cost;       //vector de nodos visitados 
    vector<int> heur;               //vector de heuristicas 
    vector<int> visited;            //vector de nodos visitados 
    map<char,int> exp;              //cantidad de expanciones de cada nodo 

public: 
    AStar(const int &init, const int &goal, const vector<int> &heur, const vector<vector<int>> &cost);
    void Search(const Node&);
    void PrintData();
    void InitInQueue(Node origin, int next);

};

#endif