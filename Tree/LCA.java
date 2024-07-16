import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

/**
 * LCA
 */
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

public class LCA {
    
    static node create(Scanner cin)
    {
        node root = null;
        Queue<node> qt = new LinkedList<>();
        int x = cin.nextInt();
        root = new node(x);
        qt.add(root);
        while (!qt.isEmpty()) {
            node ptr = qt.remove();
            x = cin.nextInt();
            if(x!=-1)
            {
                ptr.left = new node(x);
                qt.add(ptr.left);
            }
            x = cin.nextInt();
            if(x!=-1)
            {
                ptr.right = new node(x);
                qt.add(ptr.right);
            }

        }
        
        return root;
    }
    static void inorder(node root)
    {
        if(root!=null)
        {
            inorder(root.left);
            System.out.println(root.data + " ");
            inorder(root.right);
        }
    }
    static void level(node root)
    {
        Queue<node> qt = new LinkedList<>();
        qt.add(root);
        while(!qt.isEmpty())
        {
            int n = qt.size();
            for(int i=0;i<n;i++)
            {
                node temp =  qt.remove();
                System.out.print(temp.data + " ");
                if(temp.left != null ) qt.add(temp.left);
                if(temp.right != null) qt.add(temp.right);
            }
            System.out.println();
        }
    }
    static boolean FindPath(node root,ArrayList<Integer>arr,int key)
    {
        if(root == null ) return false;
        arr.add(root.data);
        if(root.data == key ) return true;
        if(FindPath(root.left, arr, key) || FindPath(root.right, arr, key)) return true;
        arr.remove(arr.size()-1);
        return false;
    }
    static Integer lca(node root,Scanner cin)
    {
        ArrayList<Integer> arr=new ArrayList<>(),brr = new ArrayList<>();
        int key1,key2;
        System.out.print("Enter key one : "); 
        key1 = cin.nextInt(); System.out.println();
        System.out.print("Enter key Two : "); 
        key2 = cin.nextInt(); System.out.println();
        if(FindPath(root, arr, key1) == false  || FindPath(root, brr, key2)==false)
        {
            System.out.println("Key is not Found");
            return Integer.MIN_VALUE;
        }
        for(int i=0;i<arr.size()-1 && i<brr.size()-1 ;i++)
        {
            if(!arr.get(i+1).equals(brr.get(i+1))) return arr.get(i) ;
        }
        return Integer.MIN_VALUE;
        
    }
    public static void main(String[] args) {
        try (Scanner cin = new Scanner(new FileInputStream("input.txt"));
             PrintStream out = new PrintStream(new FileOutputStream("output.txt"))) {
            System.setOut(out);
        node root = create(cin);
        level(root);
        ArrayList<Integer> arr= new ArrayList<>();
        FindPath(root, arr, 15);
        System.out.println(arr);
        arr.clear();
        FindPath(root, arr, 88);
        System.out.println(arr);
        System.out.println(lca(root, cin));

    }catch(FileNotFoundException e)
    {
     System.out.println("File Not Found");
    }
    }    
}