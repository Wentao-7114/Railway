#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <stack>

#include <queue>
#include "limits.h"

using namespace std;



/**
 * @brief  We choose to use Adjacency matrix to represent our graph
 * @todo Remember (0,1)'s distance == (1,0)'s distance!!!
 */
//     0    1     2
// 0  -1   80    -1           0 --- 1 --- 2
// 1  80   -1    10
// 2  -1   10    -1
class AdjMatrix {
      public:
            AdjMatrix();
            AdjMatrix(int num_of_stations);
            //resize a matrix's size
            //basically the same as customized constructor
            void resizeMatrix(int num);
            void changeDistance(int first, int second, double distance);
            double distanceBetween(int first, int second);
            stack<int> bfs(int start, int destination);
            stack<int> dijkstra(int start, int destination);
            //int mindistance(int start);

      private:
            //size of the Adjmatrix
            //also represent the number of stations 
            int _size;

            //2d vector storing stations
            //values of the vector represent distance between adjacent stations
            vector<vector<double>> _matrix;

            //vector<bool> visited;

};