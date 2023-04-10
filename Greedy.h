#include <iostream>
#include <vector> 
#include <queue>
#include <map>
#include <limits.h>

using namespace std;

#ifndef GREEDY_H
#define GREEDY_H

class Greedy{
private:
    int init,goal;              //nodo de inicio y final 
    int cont;                   //contador de costo
    vector<int> heur;           //vector de heuristicas 
    vector<int> visited;        //vector de secuencia de busqueda
    vector<int>secuence;        //secuencia completa de la busqueda 
    vector<vector<int>>cost;    //vector de nodos visitados 
    map<char,int>exp;           //mapa de nodos expandidos

public: 
    Greedy(const int &init, const int &goal, const vector<int> &heur, const vector<vector<int>> &cost);
    void Search(int node);
    int NextNode(int);
    void PrintData();

};

#endif