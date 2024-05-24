package doubleLL;

class Dinserts {
    int top =0;
    int max = 3;
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

     boolean isfull()
    {
        if(top==max)
        {
            System.out.println("Overflow");
            return false;
        }
        else{
            return true;
        }
    }
    boolean isempty()
    {
        if(top==-1){
            System.out.println("underflow");
            return false;
        }
        else{
            return true;
        }
    }
    public Node head =null;
    public Node tail =null;
    void push (int data)
    {
        if(isfull()){
        Node newnode = new Node(data);
        if(head == null)
        {
            head = newnode;
            tail= newnode;
            head.prev = null;
            tail.next = null;
            System.out.println("pushed");
            top++;
        }
        else {
           head.prev = newnode;
           newnode.next = head;
           head = newnode;
           top++;
            System.out.println("pushed");
        }  
    }
    }
   void pop()
    {
        if(isempty()){
            if(top>=0){
                 head.next.prev = null;
                head = head.next;
                top--;
                 System.out.println("poped");
            }
        }
        
    }
    void display(){
        Node current = head;
        while(current!=null)
        {
            System.out.print(current.data+" ");
            current=current.next;
        }
        System.out.println();
    }
}

class Dstack {
    public static void main(String args[]){
      Dinserts s1 = new Dinserts();
      s1.push(0);
      s1.push(1);
      s1.push(2);
      s1.push(2);
      s1.display();
      s1.pop();
      s1.display();
      
    }
}

