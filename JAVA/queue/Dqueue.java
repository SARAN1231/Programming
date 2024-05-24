package queue;
//queue solution using doubly linked list

class que2
{
	int top=0;
	int max=5;
	class Node 
	{
		int data;
		Node next;
		Node prev;
		Node(int d)
		{
			data=d;
			next=null;
			prev=null;
		}
	}
	Node head=null;
	Node tail=null;
	boolean isfull()
	{
		if(top==max)
		{
			System.out.println("overflow");
			return false;
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
			top=0;
			return false;
		}
		else 
		{
			return true;
		}
	}
	void enqueue(int d)
	{
		if(isfull())
		{
		Node newnode=new Node(d);
		if(head==null)
		{
			head=newnode;
			tail=newnode;
			System.out.println("data enqued"+head.data);
			top++;
		}
		else 
		{
			tail.next=newnode;
			newnode.prev=tail;
			tail=newnode;
			top++;
			System.out.println("data enqued"+tail.data);
		}}
	}
	void dequeue()
	{
		if(isempty())
		{
			if(head!=null)
			{
			System.out.println("data dequed=>"+head.data);
		head=head.next;
		top--;
			}
		}
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
public class Dqueue {
public static void main(String args[])
{
	que2 s1=new que2();
	s1.enqueue(4);
	s1.enqueue(5);
	s1.enqueue(8);
	s1.display();
	s1.dequeue();
	s1.display();
	s1.dequeue();
	s1.dequeue();
	s1.display();
	s1.dequeue();
}
}

