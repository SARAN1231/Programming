package doubleLL;

import java.util.*;

class Dsums {
    class Node {
        int data;
        Node next;
        Node prev;
        Node (int d){
            data = d;
            next = null;
            prev = null;
        }
    }
    public Node head =null;
    public Node tail =null;
    void adddata (int data)
    {
        Node newnode = new Node(data);
        if(head == null)
        {
            head = newnode;
            tail= newnode;
            head.prev = null;
            tail.next = null;

        }
        else {
           tail.next = newnode;  
           newnode.prev = tail;
           tail = newnode;
        }
    }
      
    void sum()
    {
        
       int tot = head.next.data + tail.prev.data; 
       System.out.println(tot);
    }
    
    void display()
    {
        Node current1 = head;
        while(current1!=null)
        {
            System.out.print(current1.data+" ");
            current1=current1.next;
        }
        
    }
}
public class Dsum {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int a = sc.nextInt();
            
            Dsums s1 = new Dsums();
            for(int i=0;i<a;i++)
            {
                s1.adddata(sc.nextInt());
            }
            
            s1.display();
            s1.sum();
        }
    }
}
