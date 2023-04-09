#include "AStar.h"

using namespace std;

AStar::AStar(const int &init,const int &goal,const vector<int> &heur ,const vector<vector<int>> &cost ){
    this->init = init;
    this->goal = goal;
    this->cost = cost;
    this->heur = heur;
    cont = 0;
    optimal.acum = INT_MAX;
    visited = vector<int>(cost.size(),INT_MAX);
}

void AStar::PrintData(){
    
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

void AStar::InitInQueue(Node origin, int next){
    Node temp;
    temp.val = next;
    temp.acum = origin.acum + cost[origin.val][next];
    temp.route = origin.route;
    temp.route.push_back(origin.val);
    p.push(temp);
}

void AStar::Search(const Node &node){
    // cerr<<node.val<<" "<<node.acum<<endl;
    // for (int i = 0; i < node.route.size(); i++)
    // {
    //     cerr<<(char)(node.route[i]+65)<< " ";
    // }
    
    if(node.val == goal && node.acum < optimal.acum){
        // cerr<<"optimal!"<<endl;
        optimal = node;
     }//cerr<<endl;
    exp[(char)(node.val + 65)]++;

    if(p.size() == 0 && node.val != init){
        if(optimal.route.size() < 1){
        cerr<<"no path found"<<endl;
        return;
        }
        optimal.route.push_back(goal);
        PrintData();
    }
        
    visited[node.val] = node.acum;
    for (int i = 0; i < cost[node.val].size(); i++)
    {
        if(cost[node.val][i]!=0){
            if((node.acum + cost[node.val][i] + heur[i]) <= visited[i]){
                // cerr<<" ->"<<i<<endl;
                InitInQueue(node,i);
            }
        }
    }

    Node tempNode = p.top();
    
    p.pop();
    
    Search(tempNode);

}