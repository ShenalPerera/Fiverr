public class BinarySearchTree{

    // Node class to implement the node of the BST
    static  public class Node{
        int key;
        Node left;
        Node right;

        public Node(){};

        public Node(int key){
            this.key = key;
            this.left = null;
            this.right = null;
        }

    }

    // Head (root) of the tree
    public Node head;

    // Constructor
    public BinarySearchTree(){
        head = null;
    }

    public void insert(int key){
        head = insertRec(head,key);
    }

    // Insert a value to tree
    public Node insertRec(Node root, int key  ){
        if (root == null) {
            root = new Node(key);
            return root;
        }

        /* Otherwise, recur down the tree */
        else if (key < root.key)
            root.left = insertRec(root.left, key);
        else if (key > root.key)
            root.right = insertRec(root.right, key);

        /* return the (unchanged) node pointer */
        return root;
    }

    // Wil traverse recursively and update each stack's value
    public int nodeCount(Node root){
        if (root == null)
            return 0;

        // Initial condition for each stack
        int res = 1;

        // call the function
        res += (nodeCount(root.left) + nodeCount(root.right));
        return res;
    }

    public int fullNodeCount(Node root){
        if (root == null)
            return 0;

        // Initial condition for each stack
        int res = 0;

        // Condition for full node

        if (root.left != null && root.right != null)
            res++;

        // call the function
        res += (fullNodeCount(root.left) + fullNodeCount(root.right));
        return res;
    }


    public boolean isFull(Node root){
        return nodeCount(root) == fullNodeCount(root);
    }


    public void inorder(Node root)
    {
        if (root != null) {
            inorder(root.left);
            System.out.println(root.key);
            inorder(root.right);
        }
    }

    public static void main(String[] args) {
        BinarySearchTree fullTree  = new BinarySearchTree();


        fullTree.insert(20);
    //    fullTree.insert(9);
    //    fullTree.insert(30);
    //    fullTree.insert(8);
    //    fullTree.insert(10);
    //    fullTree.insert(29);
    //    fullTree.insert(31);

        Node head = fullTree.head;

        // System.out.println(binarySearchTree.nodeCount(head));
        System.out.println(fullTree.isFull(head));
    }

}
