# Railway

# sihan5-xugao2-wentaoz4-shijie6
Final project for sihan5-xugao2-wentaoz4-shijie6. Presentation link: https://www.youtube.com/watch?v=Ibptunm0WvM


##  The location of all major code, data, and results.
We use json as our type of data. **StationData.json** stores the information of every station in the Beijing Metro system. **DistanceData.json** stores the distances between 2 adjacent stations. **LineData.json** stores the total length and expected speed of each metro line.
We use the adjacency matrix to represent our graph. The class **AdjMatrix** shows how an adjacency matrix is implemented. In this class, the method **bfs** is used to find the unweighted shortest path between 2 nodes, that is, a path between 2 stations which contains the least number of stations. The method **dijkstra** is used to find the weighted shortest path between 2 nodes, that is, a path between 2 stations which has the shortest length. The **tests** folder contains the test cases of our project.

## Full instructions on how to build and run your executable, including how to define the input data and output location for each method.
Our code uses *jsoncpp*, an open-source public C++ library to parse json files into C++ codes (https://github.com/open-source-parsers/jsoncpp). To use it, clone the repository, run:
```
git clone https://github.com/open-source-parsers/jsoncpp.git
```
then a directory **jsoncpp** will appear under the  root directory.

enter the directory by:
```
cd jsoncpp
```
run:
```
python amalgamate.py
```
then you can use the jsoncpp parser to read json files in the project.

To compile our code, run:
```
make
```
under the root directory.
To run the executable, type in:
```
./cs_final
```

The program will ask you to enter the name of starting station and the destination station. For example,  **Gucheng** and **Qian Men** can be used for station names.
The program will the ask you to choose which method to create a path.
If you enter **1**, you choose the dijkstra algorithm.
If you enter **2**, you choose the BFS algorithm.
After choosing which method, you will get a full list of plan, specifing which line to take and from where to where.
The estimated time, based on the expected speed of each line, will also be shown.

This is an example of the output:

input **Gucheng** :
```
which station is the starting point: Gucheng
```
input **Qian Men** :
```
which station is the destination: Qian Men
```
input **1** ：
```
1: least distance 
2: least number of stations 
Which method to choose(enter number): 1
```

output:
```
which station is the starting point: Gucheng
which station is the destination: Qian Men
1: least distance 
2: least number of stations 
Which method to choose(enter number): 1
take line: 1   from Gucheng to Bajiao Amusement Park
take line: 1   from Bajiao Amusement Park to Babaoshan
take line: 1   from Babaoshan to Yuquan Lu
take line: 1   from Yuquan Lu to Wukesong
take line: 1   from Wukesong to Wanshou Lu
take line: 1   from Wanshou Lu to Gongzhufen
take line: 1   from Gongzhufen to Military Museum
take line: 1   from Military Museum to Muxidi
take line: 1   from Muxidi to Nanlishi Lu
take line: 1   from Nanlishi Lu to Fuxing Men
take line: 2   from Fuxing Men to Changchun Jie
take line: 2   from Changchun Jie to Xuanwu Men
take line: 2   from Xuanwu Men to Heping Men
take line: 2   from Heping Men to Qian Men
total time: 13.869 minutes
```




## Full instructions and description of our test cases
To run the test cases, just use:
```
make test    
./test
```
In the test cases, we will test:
1. whether the data is correctly parsed to our algorithm
2. whether the adjacency matrix is correctly created
3. when entering data to our adjacency matrix, whether data is inputed correctly

