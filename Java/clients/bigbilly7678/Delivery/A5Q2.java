import java.util.HashSet;

//Student ID:
//Student Name:

/*/
Student Comments:


*/

public class A5Q2 {


    // detect if a linked list has a loop... the reason its printing infinitely
    // should not exceed O(n) complexity
    public static boolean hasLoop(LinkedList lst) {        
        // Assume the manipulating hash table for one node is equal O(1)
        Node head = lst.head;
        HashSet<Node> hashSet= new HashSet<Node>();

        // Inserting of Hashset = O(1)
        // Searching hashset assuming hashing function is decent < O(n)
        for(Node current = head; current != null; current = current.next){
            if(hashSet.contains(current)){
                return true;
            }
            else{
                hashSet.add(current);
            }
        }

        return false;
    }






    //you may use this for testing purposes
    public static void main(String[] args)
    {
        LinkedList myList = new LinkedList();
        myList.addNode(5);
        myList.addNode(4);
        myList.addNode(2);
        myList.addNode(1);

        //this would corrupt the list and a stack overflow will occur.. uncomment to corrupt the linkedlist
        myList.corruptList();
        System.out.println(A5Q2.hasLoop(myList));

        if(!A5Q2.hasLoop(myList))
        myList.print();

    }
}
