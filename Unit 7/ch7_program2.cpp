// Audrey Wang
// 05/15/2024
// Unit 7 Program
// This program finds the shortest path from a designated point to another.

#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

// initialize Graph struct with empty 2d matrix
struct Graph {
    int num_verts;
    int adj_matx[20][20];
    int inc_matx[20][20];
};

// initialize struct with vertex distance, previous vertex, and whether it has been visited
struct Vertex_info {
    int distance;  
    int predecessor; 
    bool visited;   
};

// create adjacency matrix with 0's
void init_adj_matx(Graph& gr) {
    for (int i = 0; i < gr.num_verts; ++i) {
        for (int j = 0; j < gr.num_verts; ++j) {
            gr.adj_matx[i][j] = 0;
        }
    }
}

// create new point in matrix
void add_edge(Graph& gr, int vertex1, int vertex2) {
    gr.adj_matx[vertex1][vertex2] = 1;
    gr.adj_matx[vertex2][vertex1] = 1;
}

// create graphs with edge points of the graph added
void create_graph_p382_n10(Graph& gr) {
    gr.num_verts = 6;
    init_adj_matx(gr);
    add_edge(gr, 0, 1);
    add_edge(gr, 0, 2);
    add_edge(gr, 1, 0);
    add_edge(gr, 1, 3);
    add_edge(gr, 1, 4);
    add_edge(gr, 2, 0);
    add_edge(gr, 2, 5);
    add_edge(gr, 3, 1);
    add_edge(gr, 3, 4);
    add_edge(gr, 4, 1);
    add_edge(gr, 4, 2);
    add_edge(gr, 4, 3);
    add_edge(gr, 4, 5);
    add_edge(gr, 5, 2);
    add_edge(gr, 5, 4);
};

void create_graph_p404_n5(Graph& gr) {
    gr.num_verts = 10;
    init_adj_matx(gr);
    add_edge(gr, 0, 1);
    add_edge(gr, 0, 5);
    add_edge(gr, 1, 0);
    add_edge(gr, 1, 2);
    add_edge(gr, 1, 6);
    add_edge(gr, 2, 1);
    add_edge(gr, 2, 3);
    add_edge(gr, 3, 2);
    add_edge(gr, 3, 4);
    add_edge(gr, 3, 6);
    add_edge(gr, 4, 3);
    add_edge(gr, 4, 7);
    add_edge(gr, 5, 0);
    add_edge(gr, 5, 6);
    add_edge(gr, 6, 1);
    add_edge(gr, 6, 3);
    add_edge(gr, 6, 5);
    add_edge(gr, 6, 7);
    add_edge(gr, 6, 8);
    add_edge(gr, 6, 9);
    add_edge(gr, 7, 4);
    add_edge(gr, 7, 6);
    add_edge(gr, 8, 6);
    add_edge(gr, 8, 9);
    add_edge(gr, 9, 6);
    add_edge(gr, 9, 8);
}

void create_graph_p403_n1(Graph& gr) {
    gr.num_verts = 10;
    init_adj_matx(gr);
    add_edge(gr, 0, 1);
    add_edge(gr, 0, 3);
    add_edge(gr, 0, 4);
    add_edge(gr, 0, 8);
    add_edge(gr, 1, 0);
    add_edge(gr, 1, 2);
    add_edge(gr, 1, 4);
    add_edge(gr, 1, 6);
    add_edge(gr, 2, 1);
    add_edge(gr, 2, 6);
    add_edge(gr, 2, 7);
    add_edge(gr, 3, 1);
    add_edge(gr, 3, 8);
    add_edge(gr, 4, 0);
    add_edge(gr, 4, 1);
    add_edge(gr, 4, 5);
    add_edge(gr, 4, 8);
    add_edge(gr, 5, 4);
    add_edge(gr, 5, 6);
    add_edge(gr, 5, 8);
    add_edge(gr, 5, 9);
    add_edge(gr, 6, 1);
    add_edge(gr, 6, 2);
    add_edge(gr, 6, 5);
    add_edge(gr, 6, 7);
    add_edge(gr, 7, 2);
    add_edge(gr, 7, 6);
    add_edge(gr, 7, 9);
    add_edge(gr, 8, 0);
    add_edge(gr, 8, 3);
    add_edge(gr, 8, 4);
    add_edge(gr, 8, 5);
    add_edge(gr, 8, 9);
    add_edge(gr, 9, 5);
    add_edge(gr, 9, 7);
    add_edge(gr, 9, 8);
}

// traverse through adjacency matrix and print
void print_adj_matx(Graph& gr) {
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < gr.num_verts; ++i) {
        for (int j = 0; j < gr.num_verts; ++j) {
            cout << gr.adj_matx[i][j] << " ";
            // printf("%6d", gr.adj_matx[i][j]);
        }
        cout << endl;
    }
}

void create_and_print_inc_matx(Graph& gr) {
    // set temporary matrix
    int num_edges = 0;
    int temp_inc_matx[20][20];

    // count number of edges from adjacency matrix
    for (int i = 0; i < gr.num_verts; ++i) {
        for (int j = 0; j < gr.num_verts; ++j) {
            if (gr.adj_matx[i][j] == 1) {
                num_edges++;
            }
        }
    }

    // set 0's in incidental matrix
    for (int i = 0; i < gr.num_verts; ++i) {
        for (int j = 0; j < num_edges; ++j) {
            temp_inc_matx[i][j] = 0;
        }
    }

    int edge_index = 0; 
    // match adjacency matrix to incidental matrix
    for (int i = 0; i < gr.num_verts; ++i) {
        for (int j = 0; j < gr.num_verts; ++j) {
            if (gr.adj_matx[i][j] == 1) {
                temp_inc_matx[i][edge_index] = 1;
                temp_inc_matx[j][edge_index] = 1;
                edge_index++;
            }
        }
    }

    // copy temporary matrix to incidental matrix
    for (int i = 0; i < gr.num_verts; ++i) {
        for (int j = 0; j < num_edges; ++j) {
            gr.inc_matx[i][j] = temp_inc_matx[i][j];
        }
    }

    // print incidental matrix
    cout << "Incidence Matrix:" << endl;
    for (int i = 0; i < gr.num_verts; ++i) {
        for (int j = 0; j < num_edges; ++j) {
            cout << gr.inc_matx[i][j] << " ";
            // printf("%6d", gr.inc_matx[i][j]);
        }
        cout << endl;
    }
}

// print coordinates of edge list
void print_edge_list(Graph& gr) {
    cout << "Edge List:" << endl;
    for (int i = 0; i < gr.num_verts; ++i) {
        for (int j = 0; j < gr.num_verts; ++j) {
            if (gr.adj_matx[i][j] == 1) {
                cout << "(" << i << ", " << j << ")" << endl;
            }
        }
    }
}

// prints shortest path between 2 given vertices
void find_shortest_path(Graph& gr, int start_vert, int end_vert) {
    int num_vertices = gr.num_verts;

    bool done = false;
    // initialize array of vertex_info    
    Vertex_info vertices[20]; 
    // initialize queue of unprocessed vertices
    queue<int> unprocessed; 

    // set verticies to default (haven't visited, there's no previous vertex)
    for (int i = 0; i < num_vertices; ++i) {
        vertices[i].distance = -1; 
        vertices[i].predecessor = -1;
        vertices[i].visited = false;
    }

    // start verticies path and values at 0
    vertices[start_vert].distance = 0;
    unprocessed.push(start_vert);

    // loop until last vertex
    while (!done && !unprocessed.empty()) {
        // use the closest vertex that hasn't been processed
        int front_vertex = unprocessed.front();
        unprocessed.pop();

        // once vertex is visited, set visited property to true
        if (vertices[front_vertex].visited)
            continue;
        vertices[front_vertex].visited = true;

        // move to the next vertex while marking the previous one as visited
        for (int next_neighbor = 0; next_neighbor < num_vertices; next_neighbor++) {
            if (gr.adj_matx[front_vertex][next_neighbor] == 1 && !vertices[next_neighbor].visited) {
                int new_distance = vertices[front_vertex].distance + 1;
                if (vertices[next_neighbor].distance == -1 || new_distance < vertices[next_neighbor].distance) {
                    vertices[next_neighbor].distance = new_distance;
                    vertices[next_neighbor].predecessor = front_vertex;
                    unprocessed.push(next_neighbor);
                }
            }
        }
        // finish after all vertices have been processed
        if (front_vertex == end_vert) 
            done = true;
    }

    if (done) {
        int path_length = vertices[end_vert].distance;

        // set up values to reverse
        int from_posn = end_vert;
        int shortest_path[20]; 
        int to_posn = path_length;

        // reversing array
        while (from_posn != -1) {
            shortest_path[to_posn--] = from_posn;
            from_posn = vertices[from_posn].predecessor;
        }

        // print out path
        cout << "Path: ";
        for (int i = 0; i <= path_length; ++i) 
            cout << shortest_path[i] << " -> ";
        cout << endl;
        cout << "Shortest distance: " << path_length << endl;
    } else {
        cout << "Shortest path from " << start_vert << " to " << end_vert << " does not exist." << endl;
    }
}


int main() {
    Graph gr;
    // print adjacency and incidental matrix as well as edge list
    create_graph_p382_n10(gr);
    cout << "Graph 1: " << endl;
    print_adj_matx(gr);
    create_and_print_inc_matx(gr);
    print_edge_list(gr);
    cout << endl;

    // find shortest path between starting (0) and ending (5) vertex
    int start_vert = 0;
    int end_vert = 5;
    find_shortest_path(gr, start_vert, end_vert);

    create_graph_p404_n5(gr);
    cout << "Graph 2: " << endl;
    print_adj_matx(gr);
    create_and_print_inc_matx(gr);
    print_edge_list(gr);
    cout << endl;

    start_vert = 0;
    end_vert = 9;
    find_shortest_path(gr, start_vert, end_vert);

    create_graph_p403_n1(gr);
    cout << "Graph 3: " << endl;
    print_adj_matx(gr);
    create_and_print_inc_matx(gr);
    print_edge_list(gr);
    cout << endl;

    start_vert = 0;
    end_vert = 9;
    find_shortest_path(gr, start_vert, end_vert);
}
