package JavaCodes;
import java.util.Scanner;

/**
 * TreeJava
 */
class node
{
    public int data;
    public node left;
    public node right;
}
public class BTreeBOOkJava {

    static node create(node temp,int info)
    {
        if(temp ==null)
        {
            temp = new node();
            temp.data= info;
            temp.left = null;
            temp.right = null;
            return temp;
        }
        if(temp.data>=info) temp.left = create(temp.left, info);
        else temp.right = create(temp.right, info);
        return temp;
        
    }
    static void inorder(node temp)
    {
        if(temp!=null)
        {
            inorder(temp.left);
            System.out.printf(" %d ",temp.data);
            inorder(temp.right);
        }
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        node root= null;
        System.out.println("Enter x or -1");
        int x = cin.nextInt();
        while(x!=-1)
        {
            root = create(root, x);
            System.out.println("Enter x or -1");
            x=cin.nextInt();
        }
        inorder(root);

    }
}