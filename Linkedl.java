import java.io.*;
import java.util.*;

public class Linkedl{
	public static void main(String args[]) throws java.io.IOException{
		Ll list;
		list=new Ll();
		for(int i=0;i<4;i++)
		{
			list.nodeMaker();

		}
		list.display();
	}
}
class Ll{
	private int count=0;
	private class node{
		public int x;
		public node next;
	} 
	private node head,end,temp;

	public void nodeMaker() throws java.io.IOException{
		String s;
		temp=new node();
		temp.next=null;
		System.out.println("enter no.");
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		s=br.readLine();
		temp.x=Integer.parseInt(s);
		if(head==null){
			head=temp;
			head.next=null;
			end=head;
		}
		end.next=temp;
		end=temp;
		count++;

	}
	public void display(){
			node p;
			p=head;
			while(p!=null){
				System.out.println(p.x);
				p=p.next;
		}
	}
}