import org.w3c.dom.Node;

import java.util.ArrayList;
import java.util.List;

public class GenLinkedList<T> {

    // Generic node
    static class  Node<T> {
        T data;
        Node<T> next;

        // Default constructor
        Node(T data) {
            this.data = data;
            this.next = null;
        }
    }


    Node<T> head;   // head of the list
    Node<T> tail;   // tail of the list

    // Length of the list
    private int length = 0;

    // Default constructor
    GenLinkedList(){
        this.head = null;
        this.tail = null;
    }

    public void addFront(T item){
        Node<T> newNode = new Node<T>(item);

        if (head == null){
            head = newNode;
            tail = newNode;
        }

        else{
            newNode.next = head;
            head = newNode;
        }
        length++;
    }


    public void addEnd(T item){

        Node<T> newNode = new Node<T>(item);

        if (tail == null){
            head = newNode;
            tail = newNode;
        }

        else{
            tail.next = newNode;
            tail = newNode;
        }
        length++;
    }

    public void removeFront(){
        if (head == null){
            return;
        }

        Node<T> node = head;
        head = head.next;
        length--;

    }

    public void removeEnd(){
        if (tail == null){
            return;
        }

        Node<T> current = head;
        while (current.next != tail){
            current = current.next;
        }

        current.next = current.next.next;
        tail = current;
        length--;
    }

    public void set(int position, T item) throws Exception {
        if (head == null) return;
        if (position >=0 && position <= length-1){
            if (position == 0) {

                // Temporary node that stores previous head value
                Node<T> temp = head;
                head = new Node<>(item);
                head.next = temp;
                length++;
                return;
            }


            Node<T> previous = null;
            Node<T> current = head;

            while (position > 0){
                previous = current;
                current = current.next;
                position--;
            }

            previous.next = new Node<T>(item);

            // new value now points to former current node
            previous.next.next = current;
            length++;
        }
        else{
            throw new Exception("Invalid parameter!");
        }
    }

    public Node<T> get(int position) throws Exception {
        if (position >=0 && position <= length-1){
            Node<T> current = head;
            Node<T> expectedNode = null;

            while (position >= 0 ){
                expectedNode = current;
                current = current.next;
                position--;
            }
            return expectedNode;
        }
        else{
            throw new Exception("Invalid parameter!");
        }
    }

    public void swap(int position1, int position2) throws Exception {
        if (head == null) return;
        if (position1 >=0 && position2 >= 0 && position1 < length && position2 < length){
            if (position1 == position2) return;

            boolean pos1 = position1 == length-1;
            boolean pos2 = position2 == length-1;

            Node<T> current1 = head;
            Node<T> prevNode1 = null;

            while (position1 > 0){
                prevNode1 = current1;
                current1 = current1.next;
                position1--;
            }

            Node<T> current2 = head;
            Node<T> prevNode2 = null;

            while (position2 > 0 ){
                prevNode2 = current2;
                current2 = current2.next;
                position2--;
            }


            if (prevNode1 != null){
                prevNode1.next = current2;
            }
            else{
                head = current2;
            }

            if (prevNode2 !=null){
                prevNode2.next = current1;
            }
            else{
                head = current1;
            }

            Node<T> temp = current1.next;
            current1.next = current2.next;
            current2.next = temp;

            if (pos1){
                tail = current2;
            }
            if (pos2){
                tail = current1;
            }
        }
        else{
            throw new Exception("Invalid parameters");
        }


    }

    public void shift(int k) throws Exception {
        if (k == 0) return;
        if (head == null) return;

        if (Math.abs(k) >= length) {
            throw new Exception("Shift value is invalid");
        }
        else{
            Node<T> temp ;

            if ( k > 0){

                while (k > 0){

                    temp = head;
                    head = head.next;

                    temp.next = tail.next;
                    tail.next = temp;
                    tail = temp;
                    k--;
                }


            }
            else{

                k = Math.abs(k);

                temp = null;
                Node<T> current = head;
                int i = 0;
                while ( i < length - k){
                    temp = current;
                    current = current.next;
                    i++;
                }



                temp.next = tail.next;
                tail.next = head;

                tail = temp;

                head = current;

            }
        }

    }

    public void removeMatching(T item){
        if (head == null) return;

        Node<T> temp = head;
        Node<T> prev = null;


        while (temp != null && temp.data == item) {
            head = temp.next;
            temp = head;
            length--;
        }

        while (temp != null) {

            while (temp != null && temp.data != item)
            {
                prev = temp;
                temp = temp.next;
            }

            if (temp == null)
                return;

            prev.next = temp.next;

            temp = prev.next;

            length--;

        }
        temp = head;
        while (temp.next != null){
            temp = temp.next;
        }
        tail = temp;

    }

    public void erase(int index,int numberOfElements) throws Exception {
        if (index + numberOfElements-1 <= length-1 && numberOfElements > 0 && index >=0 && index < length-1){
            if (head == null) return;

            Node<T> prev = null;
            Node<T> current = head;
            boolean isHead = index == 0;
            int copy = numberOfElements;

            while (index > 0){
                prev = current;
                current = current.next;
                index--;
            }

            while (numberOfElements-1 > 0){
                current= current.next;
                numberOfElements--;
            }

            if (isHead){
                head = current.next;
            }
            else {
                prev.next = current.next;
            }

            length = length - copy;

            Node<T> temp = head;
            while (temp.next != null){
                temp = temp.next;
            }
            tail = temp;

        }
        else{
            throw  new Exception("Index or number of elements is invalid");
        }
    }

    public void insertList(List<T> list, int index) throws Exception {
        if (head == null) return;

        if (index >=0 && index < length && list.size() >0){
            Node<T> prev = head;
            Node<T> current = head;

            length = length + list.size();

            if (index == 0){
                head = new Node<>(list.get(0));
                current = head;

                for (int i = 1; i<list.size(); i++){
                    current.next = new Node<>(list.get(i));
                    current = current.next;
                }
                current.next = prev;
                return;
            }


            while (index > 0){
                prev = current;
                current = current.next;
                index--;
            }


            for (T t : list) {
                prev.next = new Node<>(t);
                prev = prev.next;
            }

            prev.next = current;

            Node<T> temp = head;
            while (temp.next != null){
                temp = temp.next;
            }
            tail = temp;


        }
        else{
            throw new Exception("Index is out of bound or list is empty");
        }
    }

    // Testing function
    public void print(){
        Node<T> node = head;

        while (node != null){
            System.out.printf("%s " , node.data);
            node = node.next;
        }
        System.out.printf("\t\tHEAD = %s TAIL = %s SIZE = %s\n\n",head.data,tail.data,length);
    }

    public static void main(String[] args) throws Exception {
        GenLinkedList<Integer> genLinkedList = new GenLinkedList<Integer>();
        genLinkedList.addFront(5);
        genLinkedList.addFront(4);
        genLinkedList.addFront(3);
        genLinkedList.addFront(2);
        genLinkedList.addFront(1);

        genLinkedList.print();

        genLinkedList.addEnd(11);
        genLinkedList.addEnd(12);
        genLinkedList.addFront(0);

        genLinkedList.print();

        genLinkedList.removeFront();

        genLinkedList.print();

        genLinkedList.removeEnd();

        genLinkedList.print();

        genLinkedList.set(1,-2);
        genLinkedList.print();

        genLinkedList.set(0,10);
        genLinkedList.print();

        genLinkedList.set(7,90);
        genLinkedList.print();

        System.out.println(genLinkedList.get(0).data);
        System.out.println(genLinkedList.get(1).data);
        System.out.println(genLinkedList.get(3).data);
        System.out.println(genLinkedList.get(8).data);

        genLinkedList.swap(0,8);
        genLinkedList.print();

        genLinkedList.swap(0,5);
        genLinkedList.print();

        genLinkedList.swap(8,5);
        genLinkedList.print();

        genLinkedList.swap(2,4);
        genLinkedList.print();

        genLinkedList.shift(2);
        genLinkedList.print();

        genLinkedList.shift(3);
        genLinkedList.print();

        genLinkedList.shift(-3);
        genLinkedList.shift(-2);
        genLinkedList.print();

        genLinkedList.set(8,11);
        genLinkedList.addFront(11);
        genLinkedList.addEnd(11);
        genLinkedList.set(5,-2);

        genLinkedList.print();

        genLinkedList.removeMatching(11);
        genLinkedList.removeMatching(4);
        genLinkedList.print();

        genLinkedList.addFront(5);
        genLinkedList.addFront(4);
        genLinkedList.addFront(3);
        genLinkedList.addFront(2);
        genLinkedList.addFront(1);
        genLinkedList.print();

        genLinkedList.erase(5,8);
        genLinkedList.print();

        ArrayList<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(20);
        list.add(30);

        genLinkedList.insertList(list,3);
        genLinkedList.print();

        genLinkedList.insertList(list,7);
        genLinkedList.print();

        genLinkedList.insertList(list,0);
        genLinkedList.print();
    }
}
