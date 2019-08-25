# 设计一个有 getMin 功能的栈

## 题目：

​	实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。

## 实现代码方案一：

```java
public class GetMinStack {

    private Stack<Integer> stackData;
    private Stack<Integer> stackMin;

    public GetMinStack(){
        this.stackData = new Stack<>();
        this.stackMin = new Stack<>();
    }

    public void push(int newNum){
        if (this.stackMin.isEmpty()){
            this.stackMin.push(newNum);
        }else if(newNum <= this.getMin()){
            this.stackMin.push(newNum);
        }
        this.stackData.push(newNum);
    }

    public int pop(){
        if (this.stackData.isEmpty()){
            throw new RuntimeException("Your stack is empty!");
        }
        
        int value = this.stackData.pop();
        if (value == this.getMin()){
            this.stackMin.pop();
        }
        return value;
    }

    public int getMin(){
        if (this.stackMin.isEmpty()){
            throw new RuntimeException("Your stack is empty!");
        }
        return this.stackMin.peek();
    }

    public static void main(String[] args) {
        GetMinStack stack = new GetMinStack();
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(1);
        stack.push(2);
        stack.push(1);

        stack.pop();
        stack.pop();
        stack.pop();

        System.out.println("此时最小: " + stack.getMin());
    }

}
```

## 实现代码方案二：

```java
public class GetMinStack {

    private Stack<Integer> stackData;
    private Stack<Integer> stackMin;

    public GetMinStack(){
        this.stackData = new Stack<>();
        this.stackMin = new Stack<>();
    }

    public void push(int newNum){
        if (this.stackMin.isEmpty()){
            this.stackMin.push(newNum);
        }else if (newNum < this.getMin()){
            this.stackMin.push(newNum);
        }else {
            this.stackMin.push(this.stackMin.peek());
        }
        this.stackData.push(newNum);
    }

    public int pop(){
        if (this.stackData.isEmpty()){
            throw new RuntimeException("Your stack is empty!");
        }
        
        this.stackMin.pop();
        return this.stackData.pop();
    }

    public int getMin(){
        if (this.stackMin.isEmpty()){
            throw new RuntimeException("Your stack is empty!");
        }
        return this.stackMin.peek();
    }

    public static void main(String[] args) {
        GetMinStack stack = new GetMinStack();
        stack.push(3);
        stack.push(4);
        stack.push(5);
        stack.push(1);
        stack.push(2);
        stack.push(1);

        stack.pop();
        stack.pop();
        stack.pop();

        System.out.println("此时最小: " + stack.getMin());
    }

}
```

## 题目来源：

> 程序员代码面试指南：IT 名企算法与数据结构题目最优解 - P1