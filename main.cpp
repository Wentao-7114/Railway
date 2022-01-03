
// The simulation of Beijing Railway System is the final project of my 
// Data Structure (CS225) course in Fall 2021 semester 
// at the University of Illinois at Urbana-Champaign.
// Thanks to my co-workers: Xu Gao, Shijie Zhang and Sihan Chen


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
// #include <bits/stdc++.h>
#include "jsoncpp/dist/json/json.h"
#include "jsoncpp/dist/jsoncpp.cpp"
#include <map>
/**
 * @file main.cpp
 * @author Wentao Zhang, Xu Gao, Shijie Zhang, Sihan Chen
 * @brief 
 * @version 0.1
 * @date 2021-12-04
 * @cite clone open-source JSON parser jsoncpp (https://github.com/open-source-parsers/jsoncpp)
 * @copyright Copyright (c) 2021
 * 
 */




// #include "jsoncpp/include/json/reader.h"
// #include "jsoncpp/include/json/value.h"

#include "AdjMatrix.h"


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::map;
using std::getline;





AdjMatrix parsing(vector<string> &allStations, map<string, int> &mapStation) {
    Json::Reader reader;
    Json::Value value;
    //Check whether the json exist in the repo
    ifstream in("JsonFiles/StationData.json", std::ios::binary);


    //reader 1 is used to read the Station data
    Json::Reader reader1;
    Json::Value value1;

    //reader 2 is used to read the Distance
    Json::Reader reader2;
    Json::Value value2;

    ifstream station("JsonFiles/StationData.json", std::ios::binary);
    ifstream distance("JsonFiles/DistanceData.json", std::ios::binary);

    //the containers to store all the stations' name
    //enter an index, get a station name
    // vector<string> allStations;
    // //enter a station name, get its index
    // map<string, int> mapStation;


    //this is the return value;
    AdjMatrix my_graph;

    if (!station.is_open()) {
        cout << "Error opening file" << endl;
    } 
    
    if (reader1.parse(station, value1))
	{   
        //the number of stations
        int stationNumber = value1["stations"].size();
        
        // //the containers to store all the stations' name
        // //enter an index, get a station name
        // vector<string> allStations;
        // //enter a station name, get its index
        // map<string, int> mapStation;

        allStations.resize(stationNumber);

        //initialize the vector
        for (int i = 0; i < stationNumber; i++) {
            string stationName = value1["stations"][i]["name"].asString();
            allStations[i] = stationName;
            mapStation[stationName] = i;
        }
        //introduce an AdjMatrix as implementation of graph
        // AdjMatrix my_graph(stationNumber);
        my_graph.resizeMatrix(stationNumber);

        //read the distances from DistanceData
        if (reader2.parse(distance, value2)) {
            int numberOfDistance = value2["Distance"].size();
            // cout << numberOfDistance << endl;
            for (int i = 0; i < numberOfDistance; i++) {
                // get 2 stations
                string station1 = value2["Distance"][i]["firstStation"].asString();
                string station2 = value2["Distance"][i]["secondStation"].asString();
                //get the distance between these 2 stations
                double distanceNum = value2["Distance"][i]["distance"].asDouble();
                //get the corresponding name
                int num1 = mapStation[station1];
                int num2 = mapStation[station2];

                //change the value of the 2-d vector
                my_graph.changeDistance(num1, num2, distanceNum);
                my_graph.changeDistance(num2, num1, distanceNum);
            }

            


        }
 
	}
    return my_graph;


}


void parseLine(map<string, int> &mapLine) {


    Json::Reader reader;
    Json::Value value;
    //Check whether the json exist in the repo
    ifstream line("JsonFiles/LineData.json", std::ios::binary);

    if (reader.parse(line, value)) {
        int size = value["line"].size();
        for (int i = 0; i < size; i++) {

            string lineName = value["line"][i]["title"].asString();
            int speed = value["line"][i]["designed_speed"].asDouble();
            mapLine[lineName] = speed;
        }

    }
  

}





int main() {

    string first;
    string second;

    cout << "which station is the starting point: ";

    getline(cin, first);
    
    
    

    cout << "which station is the destination: ";
    getline(cin, second);

    

    //enter an index, get a station name
    vector<string> allStations;
    //enter a station name, get its index
    map<string, int> mapStation;

    

    // initialize the graph by calling the function parsings
    AdjMatrix my_graph = parsing(allStations, mapStation);
    
    // the final result of dijkstra or BSF search
    vector<int> stations_in_number;



    int choice;

    cout << "1: least distance " << endl;
    cout << "2: least number of stations " << endl;
    cout << "Which method to choose(enter number): ";
    
    cin >> choice;
    

    while (choice != 1 && choice != 2) {
        cout << "Please enter 1 or 2 !" << endl;

        cout << "1: least distance " << endl;
        cout << "2: least number of stations " << endl;
        cout << "Which method to choose (enter number): ";
        cin >> choice;
    }

    if (choice == 1) {

        int num1 = mapStation[first]; 

        int num2 = mapStation[second];
        




        stack<int> path = my_graph.dijkstra(num1, num2);
        while(!path.empty()) {
            int station = path.top();
            stations_in_number.push_back(station);
            path.pop();

        }
    }
    if (choice == 2) {

        int num1 = mapStation[first]; 

        int num2 = mapStation[second];
        

        stack<int> path = my_graph.bfs(num1, num2);
        while(!path.empty()) {
            int station = path.top();
            stations_in_number.push_back(station);
            path.pop();

        }
    }

    



    int length = stations_in_number.size();

    vector<string> stations_in_string;
    for (int i = 0; i < length; i++) {
        int num = stations_in_number[i];
        string stationName = allStations[num];
        stations_in_string.push_back(stationName);
    }
  
    map<string, int> mapLine;
    parseLine(mapLine);
 

    Json::Reader reader;
    Json::Value value;
    //Check whether the json exist in the repo
    ifstream distance("JsonFiles/DistanceData.json", std::ios::binary);

    if (reader.parse(distance, value)) {
        double time = 0;
  
        int size = value["Distance"].size();
    
    
        for (int i = 0; i < length - 1; i++) {
        
            bool flag = false;
            for (int j = 0; j < size; j++) {
          

                if ((stations_in_string[i] == value["Distance"][j]["firstStation"].asString() && stations_in_string[i + 1] == value["Distance"][j]["secondStation"].asString() )
                 || (stations_in_string[i] == value["Distance"][j]["secondStation"].asString()  && stations_in_string[i + 1] == value["Distance"][j]["firstStation"].asString() ))
                 {  
                    
                     string line = value["Distance"][j]["line"].asString();
                     string first = stations_in_string[i];
                     string second = stations_in_string[i + 1];
                     double length = value["Distance"][j]["distance"].asDouble() / 1000;
                     int speed = mapLine[line];
                     double subTime = length / double(speed);
                     time += subTime;
                     cout << "take line: " << line <<"   from " << first << " to " << second <<  endl;
                     flag = true;
                 }
                 if (flag == true) {
                    
                    break;
                    }
            }

        }
        time *= 60;
        cout << "total time: " << time << " minutes" << endl;
    }







    // string str1;
    // string str2;

	// getline(cin, str1);
	// getline(cin, str2);

	// cout<< str1<<endl;
    
    
    // return 0; 




}