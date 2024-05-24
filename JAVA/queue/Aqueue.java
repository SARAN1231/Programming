package queue;
// Queue solution with using of arrays 


class que 
{
	int top=0;
	int max=5;
	int ar[]=new int[max];
	boolean isfull()
	{
		if(top==max)
		{
			System.out.println("queue is overflow");
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
			System.out.println("Queue is Underflow");
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
			ar[top++]=d;
			System.out.println("data enqueud=>"+d);
		}
		
	}
	void dequeue()
	{
		if(isempty())
		{top--;
			System.out.println("data dequed=>"+ar[0]);
		
			for(int i=0;i<=top;i++)
			{
				ar[i]=ar[i+1];
			}
			
		}
	}
	void display()
	{
		if(top<0)
		{
			System.out.println("empty");
			top=0;
		}
		else {
		for(int i=0;i<top;i++)
		{
			System.out.print(ar[i]+" ");
		}
		System.out.println();
	}}
}
public class Aqueue {
public static void main(String args[])
{
	que s1=new que();
	s1.enqueue(3);
	s1.enqueue(7);
	s1.enqueue(8);
	s1.display();
	s1.dequeue();
	s1.display();
	s1.enqueue(50);
	s1.display();
	s1.dequeue();
	s1.display();
	s1.dequeue();
	s1.dequeue();
	s1.display();
	
	
}
}