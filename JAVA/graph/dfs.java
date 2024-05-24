package graph;

import java.util.*;
class dfs
{
    LinkedList<Integer>adj[];
    boolean visited[];
    
    dfs(int V)
    {
        adj = new LinkedList[V];
        visited = new boolean[V];
        
        for(int i =0;i<V;i++)
        {
            adj[i] = new LinkedList<Integer>();
        }
        void insertEdge(int src,int dest)
        {
            adj[src].add(dest);
        }
        void DFS(int vertex)
        {
            visited[vertex] = true;
            System.out.print(vertex + " ");
            Iterator<Integer> it = adj[vertex].listIterator();
            while(it.hasNext())
            {
                int n = it.next();
                if(!visited[n])
                DFS(n);
            }
        
    }
}
    public static void main(String args[])
    {
        dfs g = new dfs(8);
        g.insertEdge(0,1);
        g.insertEdge(0,2);
        g.insertEdge(0,3);
        g.insertEdge(1,3);
        g.insertEdge(2,4);
        g.insertEdge(3,5);
        g.insertEdge(3,6);
        g.insertEdge(4,7);
        g.insertEdge(4,5);
        g.insertEdge(5,2);
        
        System.out.println("Depth first traversal for the graph ");
    }
}
