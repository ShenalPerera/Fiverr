public class ProjLinkedList <E>{
    ProjNode<E> head;
    int length;

    public ProjLinkedList(){
        head = new ProjNode<>(null);
        length = 0;
    }

    public void add(E data){
        ProjNode<E> projNode = new ProjNode<E>(data);
        projNode.setNext(head);
        head = projNode;
        length++;
    }

    public ProjNode<E> getAt(int index){
        int round = 0;
        ProjNode<E> currentNode = head;

        while(currentNode.getNext() != null ){
            if (round == index){
                break;
            }
            round++;
            currentNode = currentNode.getNext();
        }
        return currentNode;
    }
}
