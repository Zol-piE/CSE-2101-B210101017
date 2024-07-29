package Ceil;

class Node {

    public int data;
    public Node left;
    public Node right;
    Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }
}

public class CeilJava {

    static Node insertNode(Node root,int data)
    {
        if(root == null)
        {
            root = new Node(data);
            return root;
        }
        if(data < root.data ) root.left = insertNode(root.left, data);
        else root.right = insertNode(root.right, data);
        return root;
    }
    static void inorder(Node root)
    {
        if(root!=null)
        {
            inorder(root.left);
            System.out.print(root.data+ " ");
            inorder(root.right);
        }
    }
    static Node res = null;
    static Node rCeil(Node root,int key)
    {
        if(root == null) return null;
        if(root.data == key )
        {
            res = root ;
            return root;
        }
        if(root.data>key)
        {
            res = root;
        }
        if(root.data > key)
        {
            
            root.left = rCeil(root.left, key);
        }
        else
        {
            root.right = rCeil(root.right, key);
        }
        return root;
    }
    static void iCeil(Node root,int key)
    {
        if(root == null) return;
        while(root != null)
        {
            if(root.data == key)
            {
                res = root;
                return;
            }
            if(root.data > key )
            {
                res = root;
                root = root.left;
            }
            else
            {
                
                root = root.right;
            }
        }
    }
    public static void main(String[] args) {
        Node root=  null;
        root = insertNode(root, 10);
        insertNode(root, 5);
        insertNode(root, 15);
        insertNode(root, 12);
        insertNode(root, 30);
        inorder(root); System.out.println();
        iCeil(root, 13);
        System.out.println(res.data);
        
    }
}