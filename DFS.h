#include <iostream>
#include <vector>
#include <time.h>
#include <map>

using namespace std;

#ifndef DFS_H
#define DFS_H

class DFS{
private:
    int init,goal;
    int cont;
    vector<vector<int>> cost;
    vector<int> visited;
    vector<int> secuence;
    map<char,int> exp;

public: 
    DFS(const int &init,const int &goal, const vector<vector<int>> &cost );
    bool RandomSearch(int node);
    void PrintData();
};

#endif