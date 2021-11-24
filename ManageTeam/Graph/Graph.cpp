#include "Graph.h"

// Function to fill the empty adjacency matrix
Graph::Graph(vector<string> inputNames)
{
    cityNames = inputNames;
    this->v = inputNames.size();
    this->e = inputNames.size();
    adj = new double*[v];
    for (int row = 0; row < v; row++) {
        adj[row] = new double[v];
        for (int column = 0; column < v; column++) {
            adj[row][column] = 0;
        }
    }
}

Graph::Graph()
{
    v = 0;
    e = 0;
    adj = new double*[v];
}

// Function to add an edge to the graph
void Graph::addEdge(string from, string to, double distance)
{
    int start = -1;
    int e = -1;
    for(int i = 0; i < cityNames.size(); i++){
        if(cityNames[i] == from){
            start = i;
        }
        if(cityNames[i] == to){
            e = i;
        }
    }
    if(start == -1 || e == -1)
        return;

    // Considering a bidirectional edge
    adj[start][e] = distance;
    adj[e][start] = distance;
}


void Graph::BFS(string start)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    int e = -1;
    for(int i = 0; i < cityNames.size(); i++){
        if(cityNames[i] == start){
            e = i;
        }
    }
    if(e==-1)
        return;


    int distance = 0;
    vector<bool> visited(v, false);
    vector<string> discoveryEdge;
    vector<string> CrossEdge;

    vector<int> q;
    vector<int> s;
    q.push_back(e);

    // Set source as visited
    visited[e] = true;

    int vis;
    cout << "Breadth First Search:" << endl << endl;
    while (!q.empty()) {
        vis = q[0];

        // Print the current node
        cout << cityNames[vis] << endl;
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < v; i++) {
            if (adj[vis][i] != 0 && (!visited[i])) {
                s.push_back(i);
                // // Push the adjacent node to the queue
                // q.push_back(i);
                // discoveryEdge.push_back("From " + cityNames[vis] + " to " + cityNames[i]);

                // Set
                visited[i] = true;
            }else if(adj[vis][i] != 0 && (visited[i])){
                CrossEdge.push_back("From " + cityNames[vis] + " to " + cityNames[i]);
            }
        }

        vector<int> temp;
        if(s.size() > 0)
            temp.push_back(s[0]);

        for(int i = 1; i < s.size(); i++){
            int j = 0;
            while(j < temp.size() && adj[vis][s[i]] > adj[vis][temp[j]]){
                j++;
            }
            temp.insert(temp.begin() + j, s[i]);
        }

        s = temp;
        for(int i = 0; i < s.size(); i++){
            distance += adj[vis][s[i]];
            q.push_back(s[i]);
            discoveryEdge.push_back("From " + cityNames[vis] + " to " + cityNames[s[i]]);
        }
        s.clear();


    }

    cout << endl << endl << "Discovery Edges: " << endl;
    for(int i = 0; i < discoveryEdge.size(); i++){
        cout << discoveryEdge[i] << endl;
    }
    cout << endl << endl << "Cross Edges: " << endl;
    for(int i = 0; i < CrossEdge.size(); i++){
        cout << CrossEdge[i] << endl;
    }

    cout << endl << endl << "Distance Traveled: " << distance << endl;
}

void Graph::dijkstra(string start) {
    cout << "Finding shortest paths from " << start << endl;
    this->dijkstraStart = start;
    double INF = std::numeric_limits<int>::max();

// Create a set to store vertices that are being
    // processed
    set<pair<double, string> > setds;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    for (int i = 0; i < v; i++)
    {
        path* newPath = new path(INF);
        dist.push_back(newPath);
    }

    // Insert source itself in Set and initialize its
    // distance as 0.
    int startIndex = -1;
    setds.insert(make_pair(0, start));
    for (int i = 0; i < cityNames.size(); i++) {
        if (cityNames[i] == start) {
            startIndex = i;
        }
    }
    if (startIndex == -1) {
        cout << "ERROR: invalid starting city";
    }

    dist[startIndex]->distance = 0;

    /* Looping till all shortest distance are finalized
       then setds will become empty    */
    while (!setds.empty()) {
        // The first vertex in Set is the minimum distance
        // vertex, extract it from set.
        pair<double, string> tmp = *(setds.begin());
        setds.erase(setds.begin());

        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        string u = tmp.second;
        int uIndex;
        for (int i = 0; i < cityNames.size(); i++) {
            if (cityNames[i] == u) {
                uIndex = i;
            }
        }

        // 'i' is used to get all adjacent vertices of a vertex
        for (int i = 1; i < v; ++i) {
            // Get vertex label and weight of current adjacent
            // of u.
            if (adj[uIndex][i] != 0) {
                string z = cityNames[i];
                int index = i;
                double weight = adj[uIndex][i];

                //    If there is shorter path to k through u.
                if (dist[index]->distance > dist[uIndex]->distance + weight) {
                    /*  If distance of k is not INF then it must be in
                        our set, so removing it and inserting again
                        with updated less distance.
                        Note : We extract only those vertices from Set
                        for which distance is finalized. So for them,
                        we would never reach here.  */
                    if (dist[index]->distance != INF)
                        setds.erase(setds.find(make_pair(dist[index]->distance, cityNames[index])));

                    // Updating distance of k
                    dist[index]->distance = dist[uIndex]->distance + weight;
                    dist[index]->cities = dist[uIndex]->cities;
                    dist[index]->cities.push_back(cityNames[i]);
                    setds.insert(make_pair(dist[index]->distance, cityNames[index]));
                }
            }
        }
    }

    // Print shortest distances stored in dist[]
    for (int i = 1; i < v; ++i) {
        cout << "Shortest path to " << cityNames[i] << ": " << start;
        for (int c = 0; c < dist[i]->cities.size(); c++)
            cout << " ---> " << dist[i]->cities[c];
        cout << "     Path distance: " << dist[i]->distance << endl;
    }
}



bool isValidEdge(int u, int v, vector<bool> inMST)
{
    if (u == v){
        return false;
    }
    if (inMST[u] == false && inMST[v] == false){
        return false;
    }
    else if (inMST[u] == true && inMST[v] == true){
        return false;
    }
    return true;
}

int Graph::MST(int cityIndex, vector<string> returnedVectorOfNames)
{
    returnedVectorOfNames.clear();
    vector<bool> inMST(v, false);

    // Include first vertex in MST
    inMST[cityIndex] = true;

    // Keep adding edges while number of included
    // edges does not become V-1.
    int edge_count = 0;
    int mincost = 0;
    while (edge_count < v - 1) {

        // Find minimum weight valid edge.
        int min = INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (adj[i][j] < min && adj[i][j] != 0) {
                    if (isValidEdge(i, j, inMST)) {
                        min = adj[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            returnedVectorOfNames.push_back(cityNames[a]);
            returnedVectorOfNames.push_back(cityNames[b]);
            returnedVectorOfNames.push_back("");
            edge_count++;
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    return mincost;

}
