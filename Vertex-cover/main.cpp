//
//  main.cpp
//  Vertex-cover
//
//  Created by Hyung Min Ji on 4/30/23.
//
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

//construct a struct for vertex. store the x, y coordinate on each.
struct Vertice {
    double x_coordinate;
    double y_coordinate;
    bool check = false;
};
//construct a struct for edge. store start, end point on each.
struct Edge {
    Vertice start_point;
    Vertice end_point;;
    bool check = false;
};
class Graph {
public:
    void initialize ();
    void Optimal_cal(Vertice &vertex, uint32_t &value);
    void approx_cal();
    void reset();
    uint32_t edge_checker(Vertice &input);
private:
    vector<Vertice> vertex;
    vector<Edge> edge;
    vector<Vertice> approx_output;
    vector<Vertice> Optimal_output;
    uint32_t optimal_value;
    uint32_t approximate_value;
};

void Graph:: initialize() {
    string junk;
    Vertice temp;
    // in a form of (X-coordinate, Y-coordinate)
    cin >> junk >> temp.x_coordinate >> junk >> temp.y_coordinate>> junk;
    vertex.push_back(temp);
    
    Edge temp2;
    // in a form of ((Start_point), (End-point))
    cin >> junk>> junk>> temp2.start_point.x_coordinate >> junk >> temp2.start_point.y_coordinate>> junk >> junk>> junk>> temp2.start_point.x_coordinate >> junk>> temp2.start_point.y_coordinate>> junk>> junk;
    edge.push_back(temp2);
}

// yield 2 approximate output
void Graph:: approx_cal() {
    for (int i = 0; i < edge.size(); i++) {
        if (edge[i].check != true) {
            approx_output.push_back(edge[i].start_point);
            approx_output.push_back(edge[i].end_point);
            edge[i].check = true;
        }
    }
    approximate_value = static_cast<uint32_t>(approx_output.size());
}
void Graph:: reset() {
    for (int i = 0; i <edge.size(); i++) {
        edge[i].check = false;
    }
}
// check if the designated vertex covers edge.
uint32_t Graph:: edge_checker(Vertice &input) {
    uint32_t value = 0;
    for (int i = 0; i < edge.size(); i++) {
        bool include = false;
        if (edge[i].start_point.x_coordinate == input.x_coordinate) {
            if (edge[i].start_point.y_coordinate == input.y_coordinate) {
                edge[i].check = true;
                include = true;
            }
        }
        if (edge[i].end_point.x_coordinate == input.x_coordinate) {
            if (edge[i].end_point.y_coordinate == input.y_coordinate) {
                edge[i].check = true;
                include = true;
            }
        }
        if (include) {
            value++;
        }
    }
    return value;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
