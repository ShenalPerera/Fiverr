import javax.swing.tree.TreeNode;

public class LinkedList {
    public Node head;
    public int size;

    public void addNode(int x)
    {
        if(head==null)
        {
            head = new Node(x);
        }else
        {
            Node t = head;
            while(t.next!= null)
            {
                t=t.next;
            }
            t.next = new Node(x);
        }
    }

    public void printList(Node x)
    {
        if(x==null)
        {
            // base case
        }else
        {
            System.out.print(x+",");
            printList(x.next);
        }
        
    }
    public void printListR(Node x)
    {
        if(x==null)
        {

        }else
        {
            printListR(x.next);
            System.out.print(x+",");
        }
        
    }

    public void corruptList()
    {
        Node temp= head;
        while(temp.next !=null)
        {
            temp = temp.next;
        }
        temp.next= head;
    }

    public void print()
    {
        printList(head);
    }

    public void printR()
    {
        printListR(head);
    }

}
