#include <iostream>
#include <map>
#include <vector>
#include "DFS.h"
#include "Greedy.h"
#include "functions.h"
#include "BCU.h"
#include "AStar.h"


using namespace std;

int main(int argc, char const *argv[])
{
    //INICIALIZAR VARIABLES 
    int init ;
    int goal ;
    vector<vector<int>>cost = {
        // {0,11,6,0,0,0,0,0},    //A 0
        // {0,0,0,4,3,0,0,0},      //B 1
        // {0,0,0,0,10,3,0,0},     //C 2
        // {0,0,0,0,0,0,0,3},      //D 3
        // {0,0,0,0,0,0,0,5},      //E 4
        // {0,0,0,0,0,0,1,0},      //F 5
        // {0,0,0,0,4,0,0,0},      //G 6
        // {0,0,0,0,0,0,0,0}       //H 7
    };
    vector<int>heur = {
        //10,7,10,3,1,2,2,0
    };
    //OPCION DE BUSQUEDA
    if(argc == 1){
        cerr<<"No Argument passed, try:"<<endl;
        cerr<<" d : for DFS search."<<endl;
        cerr<<" b : for BCU search."<<endl;
        cerr<<" g : for greedy search."<<endl;
        cerr<<" a : for A* search."<<endl;
        return 0;
    }
    //PARSER DE ARCHIVO
    parse(init,goal,heur,cost);
    string str = argv[1];
    //printParse(init,goal,heur,cost);
    
    if(str == "d"){
        cerr<<"DFS"<<endl;
        DFS d(init,goal,cost);
        d.RandomSearch(init);
    }
    else if(str == "b"){
        cerr<<"BCU"<<endl;
        BCU b(init, goal, cost);
        Node n;
        n.val = init;
        n.acum = 0;
        b.Search(n);
    }
    else if(str == "g"){
        cerr<<"Greedy"<<endl;
        Greedy g(init,goal,heur,cost);
        g.Search(init);
    }
    else if(str == "a"){
         cerr<<"A*"<<endl;
        AStar a(init, goal, heur, cost);
        Node n2;
        n2.val = init;
        n2.acum = 0;
        a.Search(n2);
    }

    return 0;
}
