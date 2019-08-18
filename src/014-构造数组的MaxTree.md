# 构造数组的 MaxTree

## 题目：

​	定义二叉树节点如下：

```java
public class Node{
    public int value;
    public Node left;
    public Node right;

    public Node(int data){
        this.value = data;
    }
}
```

​	一个数组的 MaxTree 定义如下：

* 数组必须没有重复元素

*  MaxTree 是一棵二叉树，数组的每一个值对应一个二叉树节点

* 包括 MaxTree树 在内且在其中的每一棵子树上，值最大的节点都是树的头。

​    给定一个没有重复元素 arr，写出生成这个数组的 MaxTree 函数，要求如果数组长度为 N，则时间复杂度为O(N)，额外空间复杂度为 O(N)。

## 实现代码：

```java
class Node{
    public int value;
    public Node left;
    public Node right;

    public Node(int data){
        this.value = data;
    }
}

public class MaxTree {

    public static Node getMaxTree(int[] arr){
        Node[] nArr = new Node[arr.length];
        // 构建 Node 数组
        for (int i = 0; i != arr.length; i++) {
            nArr[i] = new Node(arr[i]);
        }

        // 利用栈找出左右边第一个比自身大的数
        Stack<Node> stack = new Stack<>();
        HashMap<Node, Node> lBigMap = new HashMap<>();
        HashMap<Node, Node> rBigMap = new HashMap<>();

        // 从第一个开始,找出所有左边第一个比自身大的数
        for (int i = 0; i != nArr.length; i++) {
            Node curNode = nArr[i];
            while (!stack.isEmpty() && stack.peek().value < curNode.value){
                popStackSetMap(stack, lBigMap);
            }
            stack.push(curNode);
        }
        while (!stack.isEmpty()) {
            popStackSetMap(stack, lBigMap);
        }

        // 从最后一个开始,找出所有右边第一个比自身大的数
        for (int i = nArr.length - 1; i != -1; i--) {
            Node curNode = nArr[i];
            while (!stack.isEmpty() && stack.peek().value < curNode.value) {
                popStackSetMap(stack, rBigMap);
            }
            stack.push(curNode);
        }
        while (!stack.isEmpty()) {
            popStackSetMap(stack, rBigMap);
        }

        // 声明头结点
        Node head = null;
        for (int i = 0; i != nArr.length; i++) {
            Node curNode = nArr[i];
            Node left = lBigMap.get(curNode);
            Node right = rBigMap.get(curNode);
            if (left == null && right == null){
                head = curNode;
            }else if (left == null){
                // 左为空，就串在右的底下,从左到右
                if (right.left == null) {
                    right.left = curNode;
                }else {
                    right.right = curNode;
                }
            } else if (right == null) {
                // 右为空，就串在左的底下，从左到右
                if (left.left == null) {
                    left.left = curNode;
                }else {
                    left.right = curNode;
                }
            }else {
                // 选择左右较小的数位父节点
                Node parent = left.value < right.value ? left : right;
                if (parent.left == null) {
                    parent.left = curNode;
                }else {
                    parent.right = curNode;
                }
            }
        }
        return head;
    }

    // 利用栈来找出左大或右大
    private static void popStackSetMap(Stack<Node> stack, HashMap<Node, Node> map) {
        Node popNode = stack.pop();
        if (stack.isEmpty()) {
            map.put(popNode, null);
        }else {
            map.put(popNode, stack.peek());
        }
    }

    // 二叉树的先序遍历
    public static void printPreOrder(Node head) {
        if (head == null) {
            return;
        }
        System.out.print(head.value + " ");
        printPreOrder(head.left);
        printPreOrder(head.right);
    }

    // 二叉树的中序遍历
    public static void printInOrder(Node head) {
        if (head == null) {
            return;
        }
        printInOrder(head.left);
        System.out.print(head.value + " ");
        printInOrder(head.right);
    }

    public static void main(String[] args) {
        int[] uniqueArr = { 3, 4, 5, 1, 2 };
        Node head = getMaxTree(uniqueArr);

        printPreOrder(head);

        System.out.println();

        printInOrder(head);
    }

}
```

## 题目来源：

> 程序员代码面试指南：IT 名企算法与数据结构题目最优解 - P22