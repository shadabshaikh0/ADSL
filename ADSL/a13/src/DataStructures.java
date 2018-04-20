import java.util.*;

public class DataStructures {
	Scanner in=new Scanner(System.in);

	void RunAll()
	{
		int choice;
		do
		{
			System.out.println("1.LinkedList");
			System.out.println("2.Stack");
			System.out.println("3.Priority Queue");
			System.out.println("4.Dequeue");
			System.out.println("5.Hashset");
			System.out.println("6.Exit");
			System.out.println("Enter your choice");
			choice=in.nextInt();
			switch (choice)
			{
							case 1:
								linkedlistimplementation();
								break;
							case 2:
								stackimplementation();
								break;
							case 3:
								priorityimplementation();
								break;
							case 4:
								dequeueimplementation();
								break;
							case 5:
								hashsetimplementation();
								break;
							case 6:
								System.exit(0);
								break;
							default:
								System.out.println("Enter valid choice");
								break;
			}
		}while(choice!=6);
	}
	
	void linkedlistimplementation()
	{
	  LinkedList<Integer> ll=new LinkedList<Integer>();
	  int choice,data;
	  do
	  {
		System.out.println("1.Add First");
		System.out.println("2.Add Last");
		System.out.println("3.Remove First");
		System.out.println("4.Remove Last");
		System.out.println("5.Display All");
		System.out.println("6.Exit");
		System.out.println("Enter your choice");
		choice=in.nextInt();
		switch (choice)
		{
						case 1:
							System.out.println("Enter data to be added");
							data=in.nextInt();
							ll.addFirst(data);
							break;
						case 2:
							System.out.println("Enter data to be added");
							data=in.nextInt();
							ll.addLast(data);
							break;
						case 3:
							ll.removeFirst();
							break;
						case 4:
							ll.removeLast();
							break;
						case 5:
							System.out.println("List :"+ll);
							break;
		}
	  }while(choice!=6);

	}
	void stackimplementation()
	{
		  Stack<Integer> st=new Stack<Integer>();
		  int choice,data;
		  do
		  {
			System.out.println("1.push");
			System.out.println("2.pop");
			System.out.println("3.Display top");
			System.out.println("4.check IS empty");
			System.out.println("5.Exit");
			System.out.println("Enter your choice");
			choice=in.nextInt();
			switch (choice)
			{
							case 1:
								System.out.println("Enter data to be push");
								data=in.nextInt();
								st.push(data);
								break;
							case 2:
								System.out.println("Popped data:"+st.pop());
								break;
							case 3:
								System.out.println("Top Element:"+st.peek());
								break;
							case 4:
								if(st.isEmpty())
								{
									System.out.println("Stack is empty");
								}
								else
								{
									System.out.println("Stack is not empty");									
								}
								break;
			}
		  }while(choice!=5);
		
	}
	void priorityimplementation()
	{
		  PriorityQueue<Integer> pq=new PriorityQueue<Integer>();
		  int choice,data;
		  do
		  {
			System.out.println("1.Add data");
			System.out.println("2.pop");
			System.out.println("3.Display head");
			System.out.println("4.size");
			System.out.println("5.Exit");
			System.out.println("Enter your choice");
			choice=in.nextInt();
			switch (choice)
			{
							case 1:
								System.out.println("Enter data to be added");
								data=in.nextInt();
								pq.add(data);
								break;
							case 2:
								System.out.println("Popped data:"+pq.poll());
								break;
							case 3:
								System.out.println("Top Element:"+pq.peek());
								break;
							case 4:
								System.out.println("size:"+pq.size());
								break;
			}
		  }while(choice!=5);
		
	}
	void dequeueimplementation()
	{
		  ArrayDeque<Integer> aq=new ArrayDeque<Integer>();
		  int choice,data;
		  do
		  {
			System.out.println("1.Add First");
			System.out.println("2.Add last");
			System.out.println("3.Display head");
			System.out.println("4.Display tail");
			System.out.println("5.Remove First");
			System.out.println("6.Remove last");
			System.out.println("7.Exit")	;
			System.out.println("Enter your choice");
			choice=in.nextInt();
			switch (choice)
			{
							case 1:
								System.out.println("Enter data to be added");
								data=in.nextInt();
								aq.addFirst(data);
								break;
							case 2:
								System.out.println("Enter data to be added");
								data=in.nextInt();
								aq.addLast(data);
								break;
							case 3:
								System.out.println("Top Element:"+aq.peekFirst());
								break;
							case 4:
								System.out.println("Last Element:"+aq.peekLast());
								break;
							case 5:
								System.out.println("Removed Element:"+aq.removeFirst());
								break;
							case 6:
								System.out.println("Removed Element:"+aq.removeLast());
								break;							
			}
		  }while(choice!=7);
		
		
	}
	void hashsetimplementation()
	{
		  HashSet<Integer> hs=new HashSet<Integer>();
		  int choice,data;
		  do
		  {
			System.out.println("1.Add data");
			System.out.println("2.remove");
			System.out.println("3.Display ");
			System.out.println("4.size");
			System.out.println("5.Exit");
			System.out.println("Enter your choice");
			choice=in.nextInt();
			switch (choice)
			{
							case 1:
								System.out.println("Enter data to be added");
								data=in.nextInt();
								hs.add(data);
								break;
							case 2:
								System.out.println("Enter data to be deleted");
								data=in.nextInt();								
								System.out.println("removed data:"+hs.remove(data));
								break;
							case 3:
								System.out.println("Hash Set:"+hs);
								break;
							case 4:
								System.out.println("size:"+hs.size());
								break;
			}
		  }while(choice!=5);
		
	}
	
	public static void main(String[] args) {
		DataStructures ds=new DataStructures();
		ds.RunAll();
	}

}