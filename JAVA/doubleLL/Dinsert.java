package doubleLL;

import java.util.*;

class insert {
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

    void dinsert(int b,int c)
    {
        Node current = head;
        Node newnode = new Node(c);
        while(current!=null)
        {
            if(b==current.data)
            {
                Node temp = current.prev;
                temp.next.prev = newnode;
                newnode.next = temp.next;
                newnode.prev = temp;
                temp.next = newnode;

            }
            current=current.next;
        }

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
public class Dinsert {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            insert s1 = new insert();
            for(int i=0;i<a;i++)
            {
                s1.adddata(sc.nextInt());
            }
            s1.dinsert(b, c);
            s1.display();
        }
    }
}
