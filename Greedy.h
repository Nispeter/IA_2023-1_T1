#include <iostream>
#include <vector> 
#include <queue>
#include <map>
#include <limits.h>

using namespace std;

class Greedy{
private:
    int init,goal;
    int cont;
    vector<int> heur;
    vector<int> visited;
    vector<int>secuence;
    vector<vector<int>>cost;
    map<char,int>exp;

public: 
    Greedy(const int &init, const int &goal, const vector<int> &heur, const vector<vector<int>> &cost);
    void Search(int node);
    int NextNode(int);
    void PrintData();

};