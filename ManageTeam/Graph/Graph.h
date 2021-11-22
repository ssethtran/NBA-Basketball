#include <iostream>
#include <string>
//#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

struct path{
    double distance;
    vector<string> cities;

    path(double dist)
    {
        distance = dist;
    }
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
  
    void BFS(string start);
    void dijkstra(string start);
    vector<path*> dist;
    string dijkstraStart;
};