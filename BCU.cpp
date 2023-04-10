#include "BCU.h"

using namespace std;

BCU::BCU(const int &init,const int &goal, const vector<vector<int>> &cost ){
    this->init = init;
    this->goal = goal;
    this->cost = cost;
    cont = 0;
    optimal.acum = INT_MAX;
    visited = vector<int>(cost[0].size(),INT_MAX);
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
    if(node.val == goal  && node.acum < optimal.acum){
        optimal = node;
    }
    
    //verificacion de finalizacion
    if(p.size() == 0 && optimal.val == goal){
        if(optimal.route.size() < 1){
            cerr<<"no path found"<<endl;
            return;
        }
        optimal.route.push_back(goal);
        PrintData();
        return;
    }

    //marcar el nodo como visitado, ingresando el valor acumulado con el que se visito
    //respecto al costo acumulado 
    if(visited[node.val] >= node.acum)
        visited[node.val] = node.acum;
    else {
        Node tempNode = p.top();
        p.pop();
        Search(tempNode);
        return;
    }
    //incremento de expancion de nodo
    exp[(char)(node.val + 65)]++;

    //recorrido de todos los nodos hijos en forma BFS
    for (int i = 0; i < cost[node.val].size(); i++)
    {
        if(cost[node.val][i]!=0){
            if(node.val == 7)cerr<<"KAJHSDFKJHASDF"<<endl;
            //comparacion si el nodo actual + el costo es menor al registrado anteriormente 
            if((node.acum + cost[node.val][i]) <= visited[i]){
                //if(i == 7)cout<<"H "<<visited[i]<< " vs "<<node.acum + cost[node.val][i]<< ", ";
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