#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

//construct a struct for vertex. store the x, y coordinate on each.
struct Vertice {
    double x_coordinate;
    double y_coordinate;
    bool blue = true;
};
//construct a struct for edge. store start, end point on each.
struct Edge {
    Vertice start_point;
    Vertice end_point;;
};
class Graph {
public:
    void initialize ();
    void approx_cal();
    uint32_t edge_checker(vector<Vertice> &input, Vertice &input2);
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
}

// yield 2 approximate output
void Graph:: approx_cal() {
    for (int i =0; i < vertex.size(); i++) {
        vector<Vertice> input;
        input.resize(vertex.size());
        double value = edge_checker(input, vertex[i]);
        double blue_count = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i].blue == false) {
                blue_count++;
            }
        }
        if (blue_count > ((0.5) * value)) {
            vertex[i].blue = true;
        }
    }
}

// check if the designated vertex covers edge.
uint32_t Graph:: edge_checker(vector<Vertice> &input, Vertice &input2) {
    uint32_t value = 0;
    for (int i = 0; i < edge.size(); i++) {
        bool include = false;
        if (edge[i].start_point.x_coordinate == input2.x_coordinate && edge[i].start_point.y_coordinate == input2.y_coordinate) {
            include = true;
            value++;
            input2.x_coordinate = edge[i].end_point.x_coordinate;
            input2.y_coordinate = edge[i].end_point.y_coordinate;
        }
        else if (edge[i].end_point.x_coordinate == input2.x_coordinate && edge[i].end_point.y_coordinate == input2.y_coordinate) {
            include = true;
            value++;
            input2.x_coordinate = edge[i].start_point.x_coordinate;
            input2.y_coordinate = edge[i].start_point.y_coordinate;
        }
    }
    return value;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
