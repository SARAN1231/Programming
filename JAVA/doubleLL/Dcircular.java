package doubleLL;

import java.util.*;

class cdlist {
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
            head.prev = tail;
            tail.next = head;

        }
        else {
           tail.next = newnode;  
           newnode.prev = tail;
           tail = newnode;
           tail.next = head;
           head.prev = tail;
        }
    }
    void insertB(int b){
        Node newnode = new Node(b);
        head.prev = newnode;
        newnode.next = head;
        head = newnode;
        head.prev = tail;
        tail.next = head;
    }

    void insertA(int b)
    {
        Node newnode = new Node(b);
        Node current = head;
        while(current.next!=head)
        {
            tail.next = newnode;
            newnode.prev = tail;
            tail = newnode;
            newnode.next = head;
            head.prev = tail;
            current = current.next;
        }
    }
    void deleteB()
    {
         head.next.prev = tail.next;
         head = head.next;
         tail.next = head;

    }

    void deleteA()
    {
        tail.prev.next = head;
        tail = tail.prev;
        head.prev = tail.next;
    }
    
    void display()
    {
        Node current1 = head;
        do {
                   System.out.print(current1.data+" ");
                   current1=current1.next;
        }while(current1.next!=head);
        System.out.println(current1.data);
    }
}
public class Dcircular {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            // int c = sc.nextInt();
            cdlist s1 = new cdlist();
            for(int i=0;i<a;i++)
            {
                s1.adddata(sc.nextInt());
            }
            s1.display();
            s1.insertB(b);
            s1.display();
            s1.deleteB();
            s1.display();
            s1.deleteA();
            s1.display();
            s1.insertA(b);
            s1.display();
        }
    }
}
