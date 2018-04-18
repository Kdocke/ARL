package com.kdocke.getmin;

import java.util.Stack;

class MyStack2{
	private Stack<Integer> stackData;
	private Stack<Integer> stackMin;
	
	public MyStack2() {
		this.stackData = new Stack<Integer>();
		this.stackMin = new Stack<Integer>();
	}
	
	public void push(int newNum) {
		if(this.stackMin.isEmpty()) {
			this.stackMin.push(newNum);
		}else if(newNum < this.getmin()) {
			this.stackMin.push(newNum);
		}else {
			this.stackMin.push(this.getmin());
		}
		this.stackData.push(newNum);
	}
	
	public int pop() {
		if(this.stackData.isEmpty())
			throw new RuntimeException("Your stack is empty!");
		this.stackMin.pop();
		return this.stackData.pop();
	}

	public int getmin() {
		if(this.stackMin.isEmpty())
			throw new RuntimeException("Your stack is empty!");
		return this.stackMin.peek();
	}
}

public class $007$getMin2 {

	public static void main(String args[]) {
		MyStack1 myStack1 = new MyStack1();
		myStack1.push(3);
		myStack1.push(4);
		myStack1.push(5);
		myStack1.push(1);
		myStack1.push(2);
		myStack1.push(1);
		
		System.out.println(myStack1.pop());
		System.out.println(myStack1.pop());
		System.out.println(myStack1.pop());
		System.out.println(myStack1.pop());
		
		System.out.println("-->" + myStack1.getmin());
	}
	
}
