import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class node 
{
    public int data;
    public node left;
    public node right;
    node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
}

public class TreeDiameter {

    static int res = Integer.MIN_VALUE;
    static void levelTraverse(node root)
    {
        Queue<node> qt = new LinkedList<>();
        qt.add(root);
        while(!qt.isEmpty())
        {
            int n = qt.size();
            for(int i=0;i<n;i++)
            {
                node temp = qt.remove();
                System.out.print(temp.data+" ");
                if(temp.left!=null) qt.add(temp.left);
                if(temp.right!=null) qt.add(temp.right);
            }
            System.out.println();
        }
    }
    static node create(node root,int info)
    {
        if(root == null)
        {
            root = new node(info);
            return root;
        }
        if(root.data>=info) root.left = create(root.left, info);
        else root.right = create(root.right, info);
        return root;
    }
    static node create(node root)
    {
        int x; 
        Queue<node> qt = new LinkedList<>();
        Scanner cin = new Scanner(System.in);
        x = cin.nextInt();
        root = new node(x);
        qt.add(root);
        while(!qt.isEmpty())
        {
            node ptr = qt.remove();
            x = cin.nextInt();
            if(ptr.left==null && x!=-1)
            {
                node temp = new node(x);
                ptr.left = temp;
                qt.add(temp);
            }
            x = cin.nextInt();
            if(ptr.right == null && x!=-1)
            {
                node temp = new node(x);
                ptr.right = temp;
                qt.add(temp);
            }
        }
        return root;
    }
    static void inorder(node root)
    {
        if(root!=null)
        {
        inorder(root.left);
        System.out.print(root.data+" ");
        inorder(root.right);
        }
    }
    static int height(node root)
    {
        if(root == null) return 0;
        int lh = height(root.left);
        int rh = height(root.right);
        return Math.max(lh,rh)+1;
    }
    static int diameter(node root)
    {
        if(root==null) return 0;
        int lh = diameter(root.left);
        int rh = diameter(root.right);
        res = Math.max(lh+rh+1,res);
        return 1+Math.max(lh,rh);
    }
    public static void main(String[] args) {
        try
        {
        	System.setIn(new FileInputStream("input.txt"));
        }
        catch(FileNotFoundException e)
        {
            System.out.println("Input File not Found");
        }
        try
        {
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        }
        catch(FileNotFoundException e)
        {
            System.out.println("Output File Not Found");
        }
        Scanner cin = new Scanner(System.in);
        node root = null;
        root = create(root);
        inorder(root); System.out.println();
        levelTraverse(root);
        System.out.println("Height of Tree  : "+height(root));
        diameter(root);
        System.out.println("Diameter : "+res);
        cin.close();
    }
}