#include "DFS.h"

using namespace std;


DFS::DFS(const int &init, const int &goal, const vector<vector<int>> &cost ){

    srand (time(NULL));
    cont = 0;
    this->init = init;
    this->goal = goal;
    this->cost = cost;
    visited = vector<int>(cost.size(),0);
}

void DFS::PrintData(){
    if(secuence.size() < 1){
        cerr<<"no path found"<<endl;
        return;
    }
    secuence.insert(secuence.begin(),init);
    for (int i = 0; i < secuence.size()-1; i++)
    {
        cont += cost[secuence[i]][secuence[i+1]];
        cerr<<(char)(secuence[i] + 65)<<" -> ";
    }cerr<<(char)(secuence[secuence.size()-1] + 65)<<endl;
    cerr<<"costo: "<<cont<<endl;
    for (map<char,int>::iterator itr = exp.begin(); itr != exp.end(); itr++)
    {
        cerr<<itr->first<<": "<<itr->second<<endl;
    }
    
}


bool DFS::RandomSearch(int node){
    if(visited[node] != 0){
        secuence.pop_back();
        return false;
    }
    else if(node == goal){
        exp[node + 65]++;
        PrintData();
        return true;
    }
    
    exp[node + 65]++;
    visited[node] = 1 ;

    for (int i = 0; i < cost[node].size(); i++)
    {
        int nextNode = rand() % cost[node].size();
        while(cost[node][nextNode] == 0) nextNode = rand() % cost[node].size();     //Seccion ineficiente
        secuence.push_back(nextNode);
        if(RandomSearch(nextNode)){
            return true;
        }
    }

    secuence.pop_back();
    return false;
}
