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
        //myList.corruptList();
        System.out.println(A5Q2.hasLoop(myList));

        if(!A5Q2.hasLoop(myList))
        myList.print();

    }
}
