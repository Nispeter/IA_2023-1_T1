#include "Greedy.h"


using namespace std;

Greedy::Greedy(const int &init,const int &goal, const vector<int> &heur , const vector<vector<int>> &cost){
    this->init = init;
    this->goal = goal;
    this->cost = cost;
    this->heur = heur;
    cont = 0;
    visited = vector<int>(heur.size(),-1);
}

int Greedy::NextNode(int node){
    int minHeur = INT_MAX;
    int temp = node;
    //busqueda del hijo con  la menor heuristica 
    for (int i = 0; i < heur.size(); i++)
    {
        if(heur[i] < minHeur && cost[node][i] > 0){
            minHeur = heur[i];
            temp = i;
        }
    }
    return temp;
}

void Greedy::PrintData(){
    if(secuence.size() < 1){
        cerr<<"no path found"<<endl;
        return;
    }
    secuence.insert(secuence.begin(),init);
    for (int i = 0; i < secuence.size()-1; i++)
    {
        cont+= cost[secuence[i]][secuence[i+1]];
        cerr<<(char)(secuence[i] + 65)<<" -> ";
    }cerr<<(char)(secuence[secuence.size()-1] + 65)<<endl;
    cerr<<"costo: "<<cont<<endl;
    for (map<char,int>::iterator itr = exp.begin(); itr != exp.end(); itr++)
    {
        cerr<<itr->first<<": "<<itr->second<<endl;
    }
}

void Greedy::Search(int node){
    do{
        //evaluar cada nodo, si ya se visito se evita ese nodo
        if(visited[node] > 0)
            continue;
        //marcar nodo como visitado 
        visited[node] = 1;
        //obtener el siguiente nodo e incrementar expancion
        node = NextNode(node);
        exp[node+65]++;
        //agregar a la secuencia 
        secuence.push_back(node);
        //condicion de termino
    }while(node != goal);
    PrintData();
}