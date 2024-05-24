package doubleLL;
class DList {
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
            head.prev = newnode;
            newnode.next= head;
            head = newnode;
        }
    }

    void dellast ()
    {
        tail.prev.next = null;
        tail.prev= tail;
    }
     void delfirst ()
    {
        head.next.prev = null;
       head = head.next;
    }

    void display()
    {
        Node current = head;
        while(current!=null)
        {
            System.out.println(current.data);
            current=current.next;
        }
    }
}

public class Dlistdel {
    public static void main (String[] args){
         DList  s1 = new DList();
         s1.adddata(5);
         s1.adddata(3);
         s1.adddata(2);
         s1.adddata(9);
         s1.dellast();
         s1.display();
         
    }
}
