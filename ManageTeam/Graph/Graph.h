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
  
    int DFS(string start, vector<string>& citiesOrder);
    int actualDFS(int start, vector<bool>& visited, vector<string>& citiesOrder);
    int BFS(string start, vector<string>& input);
    void dijkstra(string start);
    vector<path*> dist;
    string dijkstraStart;
    int MST(string cityIndex, vector<string>&);
    void printGraph();
};
