import java.util.* ;

class CList {
    class Node {
        int data;
        Node next;
      Node (int d) {
        data = d;
        next = null;
      }
    }
    public Node head = null;
    public Node tail = null;
    void adddata(int data)
    {
        Node newnode = new Node(data);
        if(head == null)
        {
            head = newnode;
            tail = newnode;
            head.next = head;
        }
        else
        {
           tail.next = newnode;
           tail = newnode;
           tail.next = head;
        }
        
    }
    void display()
        {
            
            Node current = head;
            if(head == null)
            {
                System.out.println("empty");
            }
            do{
                 System.out.print(current.data + " ");
                 current=current.next;
            }while(current.next != head);
             
            System.out.println(current.data);
        }
        void insertA(int b) {
                Node newnode = new Node(b);
                tail.next = newnode;
                tail = newnode;
                tail.next = head;

            }
            void insertB(int b){
                Node newnode = new Node(b);
               newnode.next = head;
               head= newnode;
               tail.next = head;
            }
            void deleteB(){
                Node temp = head;
                head = temp.next;
                tail.next=head;
             }
             void deleteA()
             {
                Node current = head;
                Node prev = null;
                while(current.next!=head)
                {
                    prev = current;
                    current = current.next;
                }
                tail= prev;
                tail.next = head; 

            
                
             }
        
}
class Circular {
    public static void main (String args[]) {
        try (Scanner sc = new Scanner(System.in)) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            CList s1 = new CList();
            for (int i=0;i<a;i++)
            {
                s1.adddata(sc.nextInt());
            }
              s1.display();
              s1.insertB(b);
              s1.display();
              s1.insertA(b);
              s1.display();
              s1.deleteB();
              s1.display();
              s1.deleteA();
              s1.display();
              
        }    


    }
}