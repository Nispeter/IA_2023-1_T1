#include <iostream>
#include <vector> 
#include <queue>
#include <map>
#include "utils.cpp"

using namespace std;

class BCU{
private:
    int init,goal;
    int cont;
    Node optimal;
    priority_queue<Node> p;
    vector<vector<int>> cost;
    vector<int> visited;
    map<char,int> exp;

public: 
    BCU(const int &init, const int &goal, const vector<vector<int>> &cost);
    void Search(const Node&);
    void PrintData();
    void InitInQueue(Node origin, int next);

};