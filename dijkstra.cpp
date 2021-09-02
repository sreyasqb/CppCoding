#include <iostream>
#include <vector>

using namespace std;
unsigned int INF=-1;
int no_vertices;
vector <vector <int>> graph;
void dijkstra(){

}



int main(){
    cout<<"Enter no of vertices :";
    cin>>no_vertices;
    cout<<"format for the graph (distance from each node to other if not connected then enter -1)\nEnter your graph :\n";
    for (int i=0;i<no_vertices;i++){
        cout<<"Enter vertex "<<i<<" :";
        for (int j=0;j<no_vertices;j++){
            int temp;
            cin>>temp;
            graph[i][j]=temp;
        }
    }
    for (vector <int> value : graph)
        cout<<value[0]<<','<<value[1];


}