package JavaCodes;

import java.util.Scanner;

class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

public class TreeHeightJava {

    static int height(Node temp) {
        if (temp == null) return 0;
        return Math.max(height(temp.left), height(temp.right)) + 1;
    }

    static Node create(Node temp, int info) {
        if (temp == null) {
            temp = new Node(info);
            return temp;
        }
        if (temp.data >= info) {
            temp.left = create(temp.left, info);
        } else {
            temp.right = create(temp.right, info);
        }
        return temp;
    }

    static void inorder(Node temp) {
        if (temp == null) return;
        inorder(temp.left);
        System.out.printf("%d ",temp.data);
        inorder(temp.right);
    }

    public static void main(String[] args) {
        Node root = null;
        Scanner cin = new Scanner(System.in);

        System.out.println("Enter Root Node:");
        int x = cin.nextInt();

        while (x != -1) {
            root = create(root, x);
            System.out.println("Enter Node:");
            x = cin.nextInt();
        }

        System.out.println("Inorder Traversal:");
        inorder(root);
        System.out.println();
        System.out.println("Height "+height(root));
        cin.close();
    }
}

