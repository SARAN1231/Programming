package queue;
//queue solution using singly linked list

class que1 
{
	int top=0,max=5;
	class Node 
	{
		int data;
		Node next;
		Node(int d)
		{
			data=d;
			next=null;
		}
	}
	boolean isfull()
	{
		if(top==max)
		{
			System.out.println("overflow");
			return true;
		}
		else 
		{
			return true;
		}
	}
	boolean isempty()
	{
		if(top==-1)
		{
			System.out.println("underflow");
			return false;
		}
		else 
		{
			return true;
		}
	}
	Node head=null;
	Node tail=null;
	void enqueue(int d)
	{
		if(isfull())
		{
		Node newnode = new Node(d);
		if(head==null)
		{
		head=newnode;
		tail=newnode;
		System.out.println("data enqueued=>"+newnode.data);
		top++;
		}
		else 
		{
			tail.next=newnode;
			tail=newnode;
			System.out.println("data enqueued=>"+newnode.data);
			top++;
		}
		}
	}
	void dequeue()
	{
		
		if(isempty())
		{
			if(head!=null) {
				System.out.println(head.data+" dequed");
			
			head=head.next;
		}}
		top--;
	}
	void display()
	{
		Node crnt=head;
		if(head==null)
		{
			System.out.println("Empty");
		}
		while(crnt!=null)
		{
			System.out.print(crnt.data+" ");
			crnt=crnt.next;
		}
		System.out.println();
	}
}
public class Squeue {
public static void main(String args[])
{
	que1 s1=new que1();
	s1.enqueue(4);
	s1.enqueue(9);
	s1.enqueue(8);
	s1.display();
	s1.dequeue();
	s1.display();
	s1.dequeue();
	s1.dequeue();
	s1.dequeue();
	s1.display();
	s1.enqueue(5);
	s1.display();
}
}
