import java.util.HashSet;

public class A5Q3 {
//Student ID:
//Student Name:

/*/
Student Comments:


*/


    //calling this function should remove all duplicates in the list
    public static void removeDups(LinkedList lst)
    {
        HashSet<Integer> hashSet = new HashSet<Integer>();
        Node temp = lst.head;



        for(Node current = lst.head; current != null; current = current.next){
            int data = current.data;

            if (hashSet.contains(data)){
                temp.next = current.next;
            }
            else{
                hashSet.add(data);
                temp = current;
            }
        }

    }


    //you may use this for testing purposes
    public static void main(String[] args)
    {
        LinkedList myList = new LinkedList();
        myList.addNode(5);
        myList.addNode(4);
        myList.addNode(4); // here 4 is duplicated
        myList.addNode(2);
        myList.addNode(1);
        myList.addNode(1); // here 1 is duplicated

        myList.print();

        removeDups(myList);

        System.out.println("");

        myList.print();

    }

}
