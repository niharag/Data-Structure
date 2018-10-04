/*
This is a basic Stack program using Linked-List in java.
Created on:- 04-Oct-2018
Last Updated:- 04-Oct-2018
@author:- Nihar Agrawal

*/
class List{
	int data;
	List prev;
	public List(int data){
		this.prev = null;
		this.data = data;
	}
	public List(List prev,int data){
		this.prev = prev;
		this.data = data;
	}
}
class Stack{
	List top;
	public Stack(){
		top = null;
	}
	public void add(int data){
		if(top ==null)
			top = new List(data);
		else
			top = new List(top,data);
	}
	public int delete(){
		if(top == null)
			return -1;
		else{
			int data = top.data;
			top = top.prev;
			return data;
		}
	}
}

class datastruc{
	public static void main(String[] args){
		Stack s = new Stack();
		for(int i = 0;i<10;i++)
			s.add(i);
		int j ;
		for(int i = 0;i<11;i++){
			j = s.delete();
			if(j == -1)
				System.out.println("Stack empty");
			else
				System.out.println(j);
		}
	}
}
