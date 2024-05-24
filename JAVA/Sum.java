import java.util.* ;

class List {
    class Node {
        int data;
        Node next ;
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
        }
        else
        {
           tail.next = newnode;
           tail = newnode;
        }
    }
    void display()
        {
            int sum1=0,sum2=0;
            Node current = head;
            while(current !=null) {
            if(head == null)
            {
                System.out.println("empty");
            }
            else if(current.data %2 == 0)
            {
                sum1+=current.data;
            }
            else
            {
                sum2+=current.data;
            }
            current = current.next;
            } 
            int ans = (sum1>sum2)?sum1-sum2:sum2-sum1;
            System.out.print(ans);
        }
}





class Sum {
    public static void main (String args[]) {
        try (Scanner sc = new Scanner(System.in)) {
            int a = sc.nextInt();
            List s1 = new List();
            for (int i=0;i<a;i++)
            {
                s1.adddata(sc.nextInt());
            }
              s1.display();
        }    


    }
}