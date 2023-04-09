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
        cerr<<itr->first<<" "<<itr->second<<endl;
    }
}

void Greedy::Search(int node){
    do{
        if(visited[node] > 0)
            continue;
        visited[node] = 1;
        node = NextNode(node);
        exp[node+65]++;
        secuence.push_back(node);
    }while(node != goal);
    PrintData();
}