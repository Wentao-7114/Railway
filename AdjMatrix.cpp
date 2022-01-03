#include "AdjMatrix.h"





AdjMatrix::AdjMatrix() {
      _size = 0; 
}




AdjMatrix::AdjMatrix(int num_of_stations) {

      //enter the size of the AdjMatrix
      _size = num_of_stations;


      //resize the 2d vector 
      _matrix.resize(_size);

      for (int i = 0; i < _size; i++) {
            _matrix.at(i).resize(_size);
      }

      //initialize the 2d vector to -1
      for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                  _matrix[i][j] = INT_MAX;
            }
      }


}



void AdjMatrix::resizeMatrix(int num) {
      _size = num;


      //resize the 2d vector 
      _matrix.resize(_size);

      for (int i = 0; i < _size; i++) {
            _matrix.at(i).resize(_size);
      }

      //initialize the 2d vector to -1
      for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                  _matrix[i][j] = INT_MAX;
            }
      }

}


void AdjMatrix::changeDistance(int first, int second, double distance) {
      _matrix[first][second] = distance;
      _matrix[second][first] = distance;
}

double AdjMatrix::distanceBetween(int first, int second) {
      return _matrix[first][second];
}

stack<int> AdjMatrix::bfs(int start, int destination) {
      vector<bool> visited(_size, false);
      queue<int> q;
      stack<int> path;
      vector<int> prev(_size);
      
      visited[start] = true;
      int current;
      q.push(start);
      prev[start] = start;
      
      while(!q.empty()) {
            current = q.front();
            
            for(int i = 0; i < _size; i++) {
                  if(!visited[i] && _matrix[current][i] != INT_MAX) {
                        q.push(i);
                        visited[i] = true;
                        prev[i] = current;
                  }
            }

            if(current == destination) {
                  break;
            }

            q.pop(); 

      }
      while(current != start) {
            path.push(current);
            current = prev[current];
      }

      

      path.push(start);
      return path;
}

// int AdjMatrix::mindistance(int start, vector<bool> visited) {
//       int min = INT_MAX;
//       int min_index;
//       for(int i = 0; i < _size; i++) {
//             if(_matrix[start][i] < min && visited[i]) {
//                   min = _matrix[start][i];
//                   min_index = i;
//             }
//       }
//       return min_index;
// }

stack<int> AdjMatrix::dijkstra(int start, int destination) {
      vector<double> distance(_size);
      vector<int> set(_size);
      vector<int> prev(_size);
      stack<int> path;
      vector<bool> visited;
      if(start == destination) {
            path.push(start);
            return path;
      }
      for(int i = 0; i < _size; i++) {
            distance[i] = INT_MAX;
            visited.push_back(false);
            set.push_back(i);
      }
      int u;
      distance[start] = 0;
      prev[start] = start;
      while(!set.empty()) {
            int minIndex;
            int min = INT_MAX;
            for(size_t i = 0; i < set.size(); i++) {
                  if(distance[set[i]] < min && !visited[i]) {
                        min = distance[set[i]];
                        minIndex = i;
                  }
            }
            u = set[minIndex];
            set.erase(set.begin() + minIndex);
            if(u == destination) {
                  break;
            }
            
            for(int i = 0; i < _size; i++) {
                  double cur = distance[u] + _matrix[u][i];
                  if(cur < distance[i]) {
                        distance[i] = cur;
                        prev[i] = u;
                  }
            }
      }
      while(u != start) {
            path.push(u);
            u = prev[u];
      }
      path.push(start);
      return path;
}