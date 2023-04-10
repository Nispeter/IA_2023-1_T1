#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void parse(int &init,int &goal, vector<int> &heur, vector<vector<int>> &cost){
    
    freopen("input.txt","r",stdin);

    string input;
    int lineCount = 0;
    vector<string>c;

    while(getline(cin, input)){  
        istringstream iss(input);  
        vector<string> words;
        string  word;
        while (iss >> word) { 
            words.push_back(word);
        }
        //init & goal
        if(lineCount == 0){
            init = words[1][0] - 65;
        }
        else if (lineCount == 1){
            goal = words[1][0] - 65;
        }
        //heuristicas
        else if (words.size()==2){
            heur.push_back(stoi(words[1])) ;
        }
        //lineas de costo 
        else {
            c.push_back(words[0]);
        }
        lineCount++;
    }

    //inicializacion de matriz de costo en base a la cantidad de  heuristicas 
    for (int i = 0; i < heur.size(); i++){
        cost.push_back(vector<int>());
        for (int j = 0; j < heur.size(); j++)
            cost[i].push_back(0);
    }
    //ingreso de valores de costo 
    for (int i = 0; i < c.size(); i++)
    {
        string input = c[i];
        stringstream ss(input);
        vector<string> tokens;
        string token;

        while(getline(ss, token, ',')) {
            tokens.push_back(token);
        }
        cost[tokens[0][0]-65][tokens[1][0]-65] = stoi(tokens[2]);
    }
    
}

void printParse(int &init,int &goal, vector<int>& heur, vector<vector<int>> &cost){
    cerr<<init<<" "<<goal<<endl;
    for (int i = 0; i < heur.size(); i++)
        cerr<<heur[i]<<" ";
    cerr<<endl;
    for (int i = 0; i < heur.size(); i++)
    {
       for (int j = 0; j < heur.size(); j++)
       {
            cerr<<cost[i][j]<< " ";
       }cerr<<endl;
       
    }
}