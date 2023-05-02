#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

//construct a struct for vertex. store the x, y coordinate on each.
struct Vertice {
    double x_coordinate;
    double y_coordinate;
    bool done = false;
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
    void greedy_approach();
    void approx_cal();
    void reset();
    void edge_initiate(Vertice &input);
    uint32_t edge_checker(Vertice &input);
private:
    vector<Vertice> vertex;
    vector<Edge> edge;
    vector<Vertice> approx_output;
    vector<Vertice> greedy_output;
    uint32_t greedy_value;
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
    approx_cal();
    reset();
    greedy_approach();
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

// Greedy algorithm
void Graph:: greedy_approach() {
    int max_value = 0;
    Vertice max_point;
    for (int i = 0; i <vertex.size() ;i++) {
        // check which vertex has the most edge covered
        for (int i = 0; i < vertex.size(); i++) {
            if (edge_checker(vertex[i]) > max_value) {
                max_value = edge_checker(vertex[i]);
                max_point = vertex[i];
            }
        }
        greedy_output.push_back(max_point);
        edge_initiate(max_point);
    }
    greedy_value = static_cast<uint32_t>(greedy_output.size());
    
}
void Graph:: edge_initiate(Vertice &input) {
    for (int i = 0; i < edge.size(); i++) {
        if (edge[i].start_point.x_coordinate == input.x_coordinate) {
            if (edge[i].start_point.y_coordinate == input.y_coordinate) {
                edge[i].check = true;
            }
        }
        if (edge[i].end_point.x_coordinate == input.x_coordinate) {
            if (edge[i].end_point.y_coordinate == input.y_coordinate) {
                edge[i].check = true;
            }
        }
    }
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
                include = true;
            }
        }
        if (edge[i].end_point.x_coordinate == input.x_coordinate) {
            if (edge[i].end_point.y_coordinate == input.y_coordinate) {
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
    Graph graph;
    graph.initialize();
    std::cout << "Hello, World!\n";
    return 0;
}
