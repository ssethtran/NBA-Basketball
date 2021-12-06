#include <iostream>
#include <string>
//#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

struct path{
    double distance;
    vector<string> cities;

    path(double dist);
};

class Graph {
  
    // Number of vertex
    int v;
  
    // Number of edges
    int e;
  
    // Adjacency matrix
    double** adj;

    vector<string> cityNames;
  
public:
    // To create the initial adjacency matrix
    Graph(vector<string> iN);
    Graph();
  
    // Function to insert a new edge
    void addEdge(string start, string e, double input);
  
    double DFS(string start, vector<string>& citiesOrder);
    double actualDFS(int start, vector<bool>& visited, vector<string>& citiesOrder);
    double BFS(string start, vector<string>& input);
    void dijkstra(string start);
    vector<path*> dist;
    string dijkstraStart;
    double MST(string cityIndex, vector<string>&);
    void printGraph();
};
