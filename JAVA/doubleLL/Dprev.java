package doubleLL;
class Dlist {
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

public class Dprev {
    public static void main (String args[]){
         Dlist  s1 = new Dlist();
         s1.adddata(5);
         s1.adddata(3);
         s1.adddata(2);
         s1.adddata(9);
         s1.display();
    }
}
