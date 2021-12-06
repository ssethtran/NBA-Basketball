#include "Graph.h"

path::path(double dist)
{
    distance = dist;
}

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
            adj[row][column] = -1;
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
    int z = -1;
    for(int i = 0; i < cityNames.size(); i++){
        if(cityNames[i] == from){
            start = i;
        }
        if(cityNames[i] == to){
            z = i;
        }
    }
    if(start == -1 || z == -1)
        return;

    // Considering a bidirectional edge
    adj[start][z] = distance;
    adj[z][start] = distance;
}







double Graph::DFS(string start, vector<string>& citiesOrder)
{
    int e = -1;
    for(int i = 0; i < cityNames.size(); i++){
        if(cityNames[i] == start){
            e = i;
        }
    }
    if(e==-1)
        return -1;

    citiesOrder.clear();
    citiesOrder = vector<string>(0, "");
    vector<bool> visited = vector<bool>(v, 0);
    return actualDFS(e, visited, citiesOrder);
}

double Graph::actualDFS(int start, vector<bool>& visited, vector<string>& citiesOrder)
{

    double distance = 0;
    // Print the current node
    citiesOrder.push_back(cityNames[start]);
    // Set current node as visited
    visited[start] = true;

    // For every node of the graph
    vector<int> makeOrdered;
    vector<int> ordered;

    for (int i = 0; i < v; i++) {

        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adj[start][i] != -1 && (!visited[i])) {

            makeOrdered.push_back(i);
        }
    }


    if(makeOrdered.size() > 0)
        ordered.push_back(makeOrdered[0]);
    for(int i = 1; i < makeOrdered.size(); i++){

        int j = 0;
        while(adj[start][makeOrdered[i]] > adj[start][makeOrdered[j]] && j < ordered.size()){
            j++;
        }
            ordered.insert(ordered.begin() + j, makeOrdered[i]);




    }
    for(int i = 0; i < ordered.size(); i++){
        if(!visited[ordered[i]]){
        distance += adj[start][ordered[i]];
        distance += actualDFS(ordered[i], visited, citiesOrder);
        }
    }


    return distance;
}







double Graph::BFS(string start, vector<string>& passedCityNames)
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
        return -1;


    double distance = 0;
    vector<bool> visited(v, false);

    vector<int> q;
    vector<int> s;
    q.push_back(e);
    passedCityNames.clear();

    // Set source as visited
    visited[e] = true;

    int vis;
    while (!q.empty()) {
        vis = q[0];

        // Print the current node
        passedCityNames.push_back(cityNames[vis]);
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < v; i++) {
            if (adj[vis][i] != -1 && (!visited[i])) {
                s.push_back(i);
                // // Push the adjacent node to the queue
                // q.push_back(i);
                // discoveryEdge.push_back("From " + cityNames[vis] + " to " + cityNames[i]);

                // Set
                visited[i] = true;
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
        }
        s.clear();


    }
    return distance;
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
        for (int i = 0; i < v; ++i) {
            // Get vertex label and weight of current adjacent
            // of u.
            if (adj[uIndex][i] != -1) {
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


double Graph::MST(string cityIndex, vector<string>& returnedVectorOfNames)
{

    int e = -1;
    for(int i = 0; i < cityNames.size(); i++){
        if(cityNames[i] == cityIndex){
            e = i;
        }
    }
    if(e==-1)
        return -1;

    returnedVectorOfNames.clear();
    returnedVectorOfNames.push_back("");
    vector<bool> inMST(v, false);

    // Include first vertex in MST
    inMST[e] = true;

    // Keep adding edges while number of included
    // edges does not become V-1.
    int edge_count = 0;
    double mincost = 0;
    while (edge_count < v - 1) {

        // Find minimum weight valid edge.
        double min = INT_MAX;
        int a = -1;
        int b = -1;
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (adj[i][j] < min && adj[i][j] != -1) {
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
            returnedVectorOfNames.push_back(std::to_string(min));
            edge_count++;
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    return mincost;

}


void Graph::printGraph(){
    for(int i = 0; i < v; i ++){
        for(int j = 0; j < v; j++){
            std::cout << adj[i][j] << " ";
        }
        std::cout << "\n";


    }


}
