import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

/**
 * myTree
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
public class TreeSpiral {

    static node create(node root,int info)
    {
        if(root == null)
        {
            root = new node(info);
            return root;
        }
        if(root.data >= info) root.left = create(root.left, info);
        else root.right = create(root.right, info);
        return root;

    }
    static void spiralTraverse(node root)
    {
        Queue<node> qt = new LinkedList<>();
        Stack<Integer> st = new Stack<>();
        qt.add(root);
        boolean rev = false;
        while(!qt.isEmpty())
        {
            int n = qt.size();
            for(int i=0;i<n;i++)
            {
                node temp = qt.remove();
                if(rev)
                {
                    st.push(temp.data);
                }
                else System.out.print(temp.data + " ");
                if(temp.left!=null) qt.add(temp.left);
                if(temp.right != null) qt.add(temp.right);
            }
            if(st.empty())
            {
                rev = true;
                System.out.println();
            }
            else
            {
                while(!st.empty()) System.out.print(st.pop() + " ");
                System.out.println();
                rev = false;
            }
        }
    }
    static void levelTraverseLine(node root)
    {
        Queue<node> qt = new LinkedList<>();
        qt.add(root);
        qt.add(null);
        while(qt.size()>1)
        {
            node temp = qt.remove();
            if(temp == null )
            {
                System.out.println();
                qt.add(null);
                continue;
            }
            System.out.print(temp.data+" ");
            if(temp.left != null) qt.add(temp.left);
            if(temp.right!=null) qt.add(temp.right);
        }
        System.out.println();
    }
    public static void main(String[] args) {
        node tree = null;
        Scanner  cin = new Scanner(System.in);

        while(true)
        {
            System.out.print("Enter x : ");
            int x = cin.nextInt();
            System.out.println();

            if(x == -1) break;

            else tree = create(tree, x);
        }
        levelTraverseLine(tree);
        spiralTraverse(tree);
        cin.close();
    }
}