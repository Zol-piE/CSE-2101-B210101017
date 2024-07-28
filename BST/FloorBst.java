package FloorBst;

class Node {
    public int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

public class FloorBst {

    
    static Node insertNode(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if (data > root.data) {
            root.right = insertNode(root.right, data);
        } else {
            root.left = insertNode(root.left, data);
        }
        return root;
    }

    
    static void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
    }
    static Node floor(Node root,int key)
    {
        Node res = null;
        if(root==null) return null;
        while(root!=null)
        {
            if(root.data==key) return root;
            if(key>root.data) res = root;
            if(key<root.data) root = root.left;
            else root = root.right;
        }
        return res;
    }

    public static void main(String[] args) {
        Node root = null;


        root = insertNode(root, 50);
        insertNode(root, 30);
        insertNode(root, 90);
        insertNode(root, 10);
        insertNode(root, 40);
        insertNode(root, 100);
        insertNode(root, 70);
        insertNode(root, 80);
        insertNode(root, 65);
        inorder(root);System.out.println();
        Node res = floor(root, 75);
        System.out.println(res.data);
    }
}
