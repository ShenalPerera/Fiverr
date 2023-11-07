// BinarySearchTree class
//
// CONSTRUCTION: with no initializer
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// boolean contains( x )  --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as appropriate

/**
 * Implements an unbalanced binary search tree.
 * Note that all "matching" is based on the compareTo method.
 * @author Mark Allen Weiss
 */
public class BinarySearchTree<AnyType extends Comparable<? super AnyType>>
{
    /**
     * Construct the tree.
     */
    public BinarySearchTree( )
    {
        root = null;
    }

    /**
     * Insert into the tree; duplicates are ignored.
     * @param x the item to insert.
     */
    public void insert( AnyType x )
    {
        root = insert( x, root );
    }

    /**
     * Remove from the tree. Nothing is done if x is not found.
     * @param x the item to remove.
     */
    public void remove( AnyType x )
    {
        root = remove( x, root );
    }

    /**
     * Find the smallest item in the tree.
     * @return smallest item or null if empty.
     */
    public AnyType findMin( )
    {
        if( isEmpty( ) ) return null;
            //throw new UnderflowException( );
        return findMin( root ).element;
    }

    /**
     * Find the largest item in the tree.
     * @return the largest item of null if empty.
     */
    public AnyType findMax( )
    {
        if( isEmpty( ) ) return null;
            //throw new UnderflowException( );
        return findMax( root ).element;
    }

    /**
     * Find an item in the tree.
     * @param x the item to search for.
     * @return true if not found.
     */
    public boolean contains( AnyType x )
    {
        return contains( x, root );
    }

    /**
     * Make the tree logically empty.
     */
    public void makeEmpty( )
    {
        root = null;
    }

    /**
     * Test if the tree is logically empty.
     * @return true if empty, false otherwise.
     */
    public boolean isEmpty( )
    {
        return root == null;
    }

    /**
     * Print the tree contents in sorted order.
     */
    public void printTree( )
    {
        if( isEmpty( ) )
            System.out.println( "Empty tree" );
        else
            printTree( root );
    }

    /**
     * Internal method to insert into a subtree.
     * @param x the item to insert.
     * @param t the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private BinaryNode<AnyType> insert( AnyType x, BinaryNode<AnyType> t )
    {
        if( t == null )
            return new BinaryNode<>( x, null, null );

        int compareResult = x.compareTo( t.element );

        if( compareResult < 0 )
            t.left = insert( x, t.left );
        else if( compareResult > 0 )
            t.right = insert( x, t.right );
        else
            ;  // Duplicate; do nothing
        return t;
    }

    /**
     * Internal method to remove from a subtree.
     * @param x the item to remove.
     * @param t the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private BinaryNode<AnyType> remove( AnyType x, BinaryNode<AnyType> t )
    {
        if( t == null )
            return t;   // Item not found; do nothing

        int compareResult = x.compareTo( t.element );

        if( compareResult < 0 )
            t.left = remove( x, t.left );
        else if( compareResult > 0 )
            t.right = remove( x, t.right );
        else if( t.left != null && t.right != null ) // Two children
        {
            t.element = findMin( t.right ).element;
            t.right = remove( t.element, t.right );
        }
        else
            t = ( t.left != null ) ? t.left : t.right;
        return t;
    }

    /**
     * Internal method to find the smallest item in a subtree.
     * @param t the node that roots the subtree.
     * @return node containing the smallest item.
     */
    private BinaryNode<AnyType> findMin( BinaryNode<AnyType> t )
    {
        if( t == null )
            return null;
        else if( t.left == null )
            return t;
        return findMin( t.left );
    }

    /**
     * Internal method to find the largest item in a subtree.
     * @param t the node that roots the subtree.
     * @return node containing the largest item.
     */
    private BinaryNode<AnyType> findMax( BinaryNode<AnyType> t )
    {
        if( t != null )
            while( t.right != null )
                t = t.right;

        return t;
    }

    /**
     * Internal method to find an item in a subtree.
     * @param x is item to search for.
     * @param t the node that roots the subtree.
     * @return node containing the matched item.
     */
    private boolean contains( AnyType x, BinaryNode<AnyType> t )
    {
        if( t == null )
            return false;

        int compareResult = x.compareTo( t.element );

        if( compareResult < 0 )
            return contains( x, t.left );
        else if( compareResult > 0 )
            return contains( x, t.right );
        else
            return true;    // Match
    }

    /**
     * Internal method to print a subtree in sorted order.
     * @param t the node that roots the subtree.
     */
    private void printTree( BinaryNode<AnyType> t )
    {
        if( t != null )
        {
            printTree( t.left );
            System.out.println( t.element );
            printTree( t.right );
        }
    }

    /**
     * Internal method to compute height of a subtree.
     * @param t the node that roots the subtree.
     */
    private int height( BinaryNode<AnyType> t )
    {
        if( t == null )
            return -1;
        else
            return 1 + Math.max( height( t.left ), height( t.right ) );
    }

    // Basic node stored in unbalanced binary search trees
    private static class BinaryNode<AnyType>
    {
        // Constructors
        BinaryNode( AnyType theElement )
        {
            this( theElement, null, null );
        }

        BinaryNode( AnyType theElement, BinaryNode<AnyType> lt, BinaryNode<AnyType> rt )
        {
            element  = theElement;
            left     = lt;
            right    = rt;
        }

        AnyType element;            // The data in the node
        BinaryNode<AnyType> left;   // Left child
        BinaryNode<AnyType> right;  // Right child
    }


    /** The tree root. */
    private BinaryNode<AnyType> root;


    // Wil traverse recursively and update each stack's value
    private int count_nodes(BinaryNode<AnyType> root){
        if (root == null)
            return 0;

        // Initial condition for each stack
        int res = 1;

        // call the function
        res += (count_nodes(root.left) + count_nodes(root.right));
        return res;
    }

    /**
     * Function to calculate how many full node is presented
     * @param root root of the tree
     * @return count of the full nodes
     */
    private int fullNodeCount(BinaryNode<AnyType> root){
        if (root == null)
            return 0;

        // Initial condition for each stack
        int res = 0;

        // Condition for full node

        if (root.left != null && root.right != null)
            res++;
        if (root.left == null && root.right == null)
            res++;

        // call the function
        res += (fullNodeCount(root.left) + fullNodeCount(root.right));
        return res;
    }

    public int nodeCount(){
        return count_nodes(root);
    }


    public boolean isFull(){
        return nodeCount() == fullNodeCount(root);
    }

    private boolean isSameStructure(BinaryNode<AnyType> root1, BinaryNode<AnyType> root2){
        // 1. both empty
        if (root1==null && root2==null)
            return true;
        // 2. both non-empty -> compare them
        if (root1!=null && root2!=null)
        {
            return
                    (
                            isSameStructure(root1.left, root2.left) &&
                                    isSameStructure(root1.right, root2.right)
                    );
        }
        // 3. one empty, one not -> false
        return false;
    }

    public boolean compareStructure(BinarySearchTree<AnyType> t){
        return isSameStructure(root,t.root);
    }


    private boolean areTreesIdentical(BinaryNode<AnyType> root1, BinaryNode<AnyType> root2){
        // 1. both empty
        if (root1==null && root2==null)
            return true;
        // 2. both non-empty -> compare them
        if (root1!=null && root2!=null)
        {
            return
                    (
                            areTreesIdentical(root1.left, root2.left) &&
                                    areTreesIdentical(root1.right, root2.right) && (root1.element == root2.element)
                    );
        }
        // 3. one empty, one not -> false
        return false;
    }


    public boolean equals(BinarySearchTree<AnyType> t){
        return areTreesIdentical(root,t.root);
    }

    private BinaryNode<AnyType> cloneTree(BinaryNode<AnyType> root){
        if (root == null) {
            return null;
        }

        BinaryNode<AnyType> root_copy = new BinaryNode<>(root.element);

        // clone the left and right subtree
        root_copy.left = cloneTree(root.left);
        root_copy.right = cloneTree(root.right);

        // return cloned root node
        return root_copy;
    }

    public BinarySearchTree<AnyType> copy(){
        BinarySearchTree<AnyType> t = new BinarySearchTree<>();
        t.root = cloneTree(this.root);
        return t;
    }


    private BinaryNode<AnyType> cloneMirrorTree(BinaryNode<AnyType> root){
        if (root == null) {
            return null;
        }

        BinaryNode<AnyType> root_copy = new BinaryNode<>(root.element);


        root_copy.right = cloneMirrorTree(root.left);
        root_copy.left = cloneMirrorTree(root.right);

        // return cloned root node
        return root_copy;
    }

    public BinarySearchTree<AnyType> mirror(){
        BinarySearchTree<AnyType> t =  new BinarySearchTree<>();
        t.root = cloneMirrorTree(this.root);
        return t;
    }

    public boolean isMirror(BinarySearchTree<AnyType> t){
        return this.equals(t.mirror());
    }


    public BinaryNode<AnyType> rightRotate(BinaryNode<AnyType> y) {

        BinaryNode<AnyType> x = y.left;
        BinaryNode<AnyType> z = x.right;
        x.right = y;
        y.left = z;

        return x;
    }



    private BinaryNode<AnyType> searchNode(BinaryNode<AnyType> node, AnyType value){
        if(node != null){
            if(node.element == value){
                return node;
            } else {
                BinaryNode<AnyType> foundNode = searchNode(node.left,value);
                if(foundNode == null) {
                    foundNode = searchNode(node.right,value);
                }
                return foundNode;
            }
        }
        else {
            return null;
        }

    }

    public void rotateRight(AnyType element){
        BinaryNode<AnyType> temp = searchNode(root,element);
        if (temp != null){
            temp = rightRotate(temp);
        }

    }

    int height_root(BinaryNode<AnyType> root)
    {
        if (root == null)
            return 0;
        else {
            /* compute height of each subtree */
            int lheight = height(root.left);
            int rheight = height(root.right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }


    private void printGivenLevel(BinaryNode<AnyType> root, int level)
    {
        if (root == null)
            return;
        if (level == 1) {
            System.out.print(root.element + " ");
        }
        else if (level > 1) {
            printGivenLevel(root.left, level - 1);
            printGivenLevel(root.right, level - 1);
        }
    }

    public void printLevels(){
        int h = height_root(root);
        int i;
        for (i = 1; i <= h; i++) {
            printGivenLevel(root, i);
            System.out.print(System.lineSeparator());
        }
    }

    // Test program
    public static void main( String [ ] args )
    {
        BinarySearchTree<Integer> t = new BinarySearchTree<>( );
//        final int NUMS = 4000;
//        final int GAP  =   37;
//
//        System.out.println( "Checking... (no more output means success)" );
//
//        for( int i = GAP; i != 0; i = ( i + GAP ) % NUMS )
//            t.insert( i );
//
//        for( int i = 1; i < NUMS; i+= 2 )
//            t.remove( i );
//
//        if( NUMS < 40 )
//            t.printTree( );
//        if( t.findMin( ) != 2 || t.findMax( ) != NUMS - 2 )
//            System.out.println( "FindMin or FindMax error!" );
//
//        for( int i = 2; i < NUMS; i+=2 )
//            if( !t.contains( i ) )
//                System.out.println( "Find error1!" );
//
//        for( int i = 1; i < NUMS; i+=2 )
//        {
//            if( t.contains( i ) )
//                System.out.println( "Find error2!" );
//        }

        for (int i = 0; i < 100; i++) {
            t.insert(i);
        }
        t.remove(0);

        if (!(t.nodeCount() == 99)){
            System.out.println("Error in node count function");
        }

        if (t.isFull()){
            System.out.println("Error in is full function");
        }

        BinarySearchTree<Integer> fullTree = new BinarySearchTree<>( );
        BinarySearchTree<Integer> fullTree2 = new BinarySearchTree<>();

        fullTree.insert(20);
        fullTree.insert(9);
        fullTree.insert(30);
        fullTree.insert(8);
        fullTree.insert(10);
        fullTree.insert(29);
        fullTree.insert(31);

        fullTree2.insert(21);
        fullTree2.insert(10);
        fullTree2.insert(31);
        fullTree2.insert(9);
        fullTree2.insert(11);
        fullTree2.insert(30);
        fullTree2.insert(32);


        BinarySearchTree<Integer> t3 = new BinarySearchTree<>();
        for (int i = 0; i < 100; i++) {
            t3.insert(i);
        }
        t3.remove(0);


        if (!fullTree.isFull()){
            System.out.println("Error in is full tree function");
        }





        if (fullTree.compareStructure(t)){
            System.out.println("Error in compare structure");
        }

        if (!fullTree.compareStructure(fullTree2)){
            System.out.println("Error in compare structure");
        }

        if (fullTree.equals(fullTree2)){
            System.out.println("Error 1 in equals function");
        }

        if (!t.equals(t3)){
            System.out.println("Error 2 in equals function");
        }

        BinarySearchTree<Integer> copy_tree = t.copy();

        if (!copy_tree.equals(t)){
            System.out.println("Error in copy function");
        }

        BinarySearchTree<Integer> mirror_tree = t.mirror();

        if (!t.equals(mirror_tree.mirror())){
            System.out.println("Error in mirror function");
        }

        if (!t.isMirror(mirror_tree)){
            System.out.println("Error in is Mirror / mirror functions");
        }



        fullTree.printLevels();


    }
}