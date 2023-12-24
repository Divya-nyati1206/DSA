#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

template <class T>
class graph
{
    public:

    unordered_map<T , list<T> > adj;

    void add_edge(T u , T v , bool direction)
    {
        //To make edge from u to v
        //direction = 0 -> undirected else directed
        adj[u].push_back(v);

        if(direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void print_adj_matrix()
    {
        for(auto i:adj)
        {
            cout<<i.first<<" --> ";
            for(auto j:i.second)
            {
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    graph<int> g;
    int n , m , u , v;
    bool direction;

    cout<<"Enter no. of vertices : ";
    cin>>n;

    cout<<"Graph is directed or not?? (0 for undirected 1 for directed) : ";
    cin>>direction;

    cout<<"Enter the no. of edges : ";
    cin>>m;

    cout<<"Enter both the vertices of edges :";

    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.add_edge(u,v,direction);
    }
    
    g.print_adj_matrix();
    
    return 0;
}