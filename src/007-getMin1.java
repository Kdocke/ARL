package com.kdocke.getmin;

import java.util.Stack;

class MyStack1{
	private Stack<Integer> stackData;
	private Stack<Integer> stackMin;
	
	public  MyStack1(){
		stackData = new Stack<Integer>();
		stackMin = new Stack<Integer>();
	}
	
	public void push(int newNum) {
		if(this.stackMin.isEmpty()) {
			this.stackMin.push(newNum);
		}else if(newNum <= this.getmin()){
			this.stackMin.push(newNum);
		}
		this.stackData.push(newNum);
	}
	
	public int pop() {
		if(this.stackData.isEmpty()) {
			throw new RuntimeException("Your stack is empty!");
		}
		int value = this.stackData.pop();
		if(value == this.getmin()) {
			this.stackMin.pop();
		}
		return value;
	}
	
	public int getmin() {
		if(this.stackMin.isEmpty()) {
			throw new RuntimeException("Your stack is empty!");
		}
		return this.stackMin.peek();
	}
}

public class $007$getMin1 {
	
	public static void main(String args[]) {
		MyStack1 myStack1 = new MyStack1();
		myStack1.push(3);
		myStack1.push(4);
		myStack1.push(5);
		myStack1.push(1);
		myStack1.push(2);
		myStack1.push(6);
		
		System.out.println(myStack1.pop());
		System.out.println(myStack1.pop());
		System.out.println(myStack1.pop());
		System.out.println(myStack1.pop());
		
		System.out.println("-->" + myStack1.getmin());
	}
	
}
