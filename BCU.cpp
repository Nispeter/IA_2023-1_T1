#include "BCU.h"

using namespace std;

BCU::BCU(const int &init,const int &goal, const vector<vector<int>> &cost ){
    this->init = init;
    this->goal = goal;
    this->cost = cost;
    cont = 0;
    optimal.acum = INT_MAX;
    visited = vector<int>(cost.size(),INT_MAX);
}

void BCU::PrintData(){
    
    for (int i = 0; i < optimal.route.size()-1; i++)
        {
            cont+= cost[optimal.route[i]][optimal.route[i+1]];
            cerr<<(char)(optimal.route[i]+65)<<" -> ";
        }cerr<<(char)(optimal.route[optimal.route.size()-1]+65)<<endl;
        cerr<<"costo: "<<cont<<endl;
        for (map<char,int>::iterator itr = exp.begin(); itr != exp.end(); itr++)
        {
            cerr<<itr->first<<" "<<itr->second<<endl;
        }
}

void BCU::InitInQueue(Node origin, int next){
    //ingresar el nodo actual a la priority queue
    Node temp;
    temp.val = next;
    //incremento del valor de costo del recorrido
    temp.acum = origin.acum + cost[origin.val][next];
    //encadenar el nuevo nodo a la ruta 
    temp.route = origin.route;
    temp.route.push_back(origin.val);
    //ingresar el nuevo nodo a la cola 
    p.push(temp);
}

void BCU::Search(const Node &node){
    //cerr<<node.val<<" "<<node.acum<<endl;
    //Verificacion si el nodo actual contiene en camino optimo
    if(node.val == goal  ){
        if(node.acum < optimal.acum)
            optimal = node;
        p.pop();
        return ;
    }
    //incremento de expancion de nodo
    exp[(char)(node.val + 65)]++;
    //verificacion de finalizacion
    if(p.size() == 0 && optimal.val == goal){
        if(optimal.route.size() < 1){
        cerr<<"no path found"<<endl;
        return;
        }
        optimal.route.push_back(goal);
        PrintData();
    }
    //marcar el nodo como visitado, ingresando el valor acumulado con el que se visito 
    visited[node.val] = node.acum;
    //recorrido de todos los nodos hijos en forma BFS
    for (int i = 0; i < cost[node.val].size(); i++)
    {
        if(cost[node.val][i]!=0){
            //comparacion si el nodo actual + el costo es menor al registrado anteriormente 
            if((node.acum + cost[node.val][i]) <= visited[i]){
                //cerr<<" ->"<<i<<endl;
                InitInQueue(node,i);
            }
        }
    }
    //siguiente nodo expnandido, aquel que tenga menor costo recorrido acumulado
    Node tempNode = p.top();
    //remover el nodo actualmente expandido de la priorotyqueue
    p.pop();
    
    Search(tempNode);

}