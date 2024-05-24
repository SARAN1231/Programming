package graph;

import java.util.*;

class adjList 
    {
        private int V;
        private List<List<Integer>> adjList;
        
        public adjList(int vertices)
        {
            V = vertices;
            adjList =new ArrayList<>(V);
            for(int i =0;i<V;i++)
            {
                adjList.add(new LinkedList<>());
            }
        }
        public void addEdge(int source, int destination)
        {
            adjList.get(source).add(destination);
            adjList.get(destination).add(source);
        }
        public  void printGraph()
        {
            for(int i=0;i<V;i++)
            {
                System.out.println("\nVertex "+i+":");
                for(Integer neighbor : adjList.get(i))
                {
                    System.out.print(" -> "+neighbor);
                }
                System.out.println();
            }
        }
        public static void main(String args[])
        {
            int V = 4;
            adjList graph = new adjList(V);
            graph.addEdge(0,1);
            graph.addEdge(0,2);
            graph.addEdge(0,3);
            graph.addEdge(1,2);
            graph.printGraph();
        }
    }
