public class ProjNode <E>{
    private E data;
    private ProjNode<E> next;
    private boolean isPrinted = false;

    public ProjNode(E data){
        this.data = data;
    }

    public E getData() {
        return data;
    }

    public void setData(E data) {
        this.data = data;
    }

    public ProjNode<E> getNext() {
        return next;
    }

    public void setNext(ProjNode<E> next) {
        this.next = next;
    }

    public void setPrinted(boolean printed) {
        isPrinted = printed;
    }

    public boolean isPrinted() {
        return isPrinted;
    }
}
