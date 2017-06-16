/*
6/16/17

Task Sort Problem
Topological Sort Method

Authors: Mathew Schaffrath
         Guthrie Price

*/

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct Node{
  int numIncomingNodes;
  char label;
  vector<char> outgoingEdges;
  
};

vector<Node> buildGraph(vector<char>&, vector<pair <char, char> >&);
bool topologicalSort(vector<Node>&);
Node newNode(char);
int findMin(vector<Node>&);

int main(){

  vector<char> tasks;
  vector<pair <char, char> > dependencies;

  for (char i = 'a'; i <= 'g'; i++)
  {
    tasks.push_back(i);
  }
  
  dependencies.push_back(make_pair('a','c'));
  dependencies.push_back(make_pair('b','c'));
  dependencies.push_back(make_pair('c','e'));
  dependencies.push_back(make_pair('c','f'));
  dependencies.push_back(make_pair('f','e'));
  dependencies.push_back(make_pair('e','g'));
  dependencies.push_back(make_pair('d','g'));
//  dependencies.push_back(make_pair('g','a')); //introduction of loop

  vector<Node> taskGraph = buildGraph(tasks, dependencies);
  topologicalSort(taskGraph);
 
  return 1;
}

bool topologicalSort(vector<Node>& taskGraph){

  vector<Node> workGraph = taskGraph;
  /*
  for(unsigned int i = 0; i < taskGraph.size(); i++)
  {
    cout << "Node label" <<  taskGraph[i].label << endl;
    cout << "num incoming" << taskGraph[i].numIncomingNodes << endl;    
  }
  */

  while(!workGraph.empty()){
    int minTask = findMin(workGraph);
    if(minTask == -1)
    {
      cout << "LOOP FOUND... maybe" << endl;
      return false; 
    }
  
    for(unsigned i = 0; i < workGraph[minTask].outgoingEdges.size(); i++)
    { 
      char workLabel = workGraph[minTask].outgoingEdges[i];
      for (unsigned i = 0; i < workGraph.size(); i++)
      {
        if(workGraph[i].label == workLabel)
        {
          workGraph[i].numIncomingNodes -= 1;
        }
      }
    }
    cout << workGraph[minTask].label << ' ';
    workGraph.erase(workGraph.begin() + minTask); 
  }
  cout << endl;
  return true;
}

int findMin(vector<Node>& taskGraph)
{
  for(unsigned int i = 0; i < taskGraph.size(); i++)
  {
    if(taskGraph[i].numIncomingNodes == 0)
      return i;
  }
  return -1;
}

vector<Node> buildGraph(vector<char>& tasks, vector< pair<char, char> >& dependencies)
{
  vector<Node> taskGraph;
  for (unsigned int i = 0; i < tasks.size(); i++)
  {
    taskGraph.push_back(newNode(tasks[i]));
  }

  for (unsigned int i = 0; i < dependencies.size(); i++)
  {
    taskGraph[dependencies[i].first - 'a'].outgoingEdges.push_back(dependencies[i].second);
    taskGraph[dependencies[i].second - 'a'].numIncomingNodes += 1; 
  }

  return taskGraph;
}

Node newNode(char label){
  Node node;
  node.numIncomingNodes = 0;
  node.label = label;
  return node;
}



