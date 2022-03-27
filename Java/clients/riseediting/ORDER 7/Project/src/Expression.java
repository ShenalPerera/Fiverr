public class Expression {
    private final ProjLinkedList<ITerm> iTermProjLinkedList = new ProjLinkedList<ITerm>();

    public Expression(){}

    public void add(ITerm iTerm){
        this.iTermProjLinkedList.add(iTerm);
    }

    public Expression getDerivative(){
        Expression tempE = new Expression();

        ProjNode<ITerm> current = this.iTermProjLinkedList.head;

        while (current.getNext() != null){
            if (current.getData().derivative().getValue() != 0){
                tempE.add(current.getData().derivative());
            }

            current = current.getNext();
        }
        return tempE;
    }

    public double getEvaluation(double value){
        double sum = 0;

        ProjNode<ITerm> current = this.iTermProjLinkedList.head;

        while (current.getNext() != null){
            sum += current.getData().evaluate(value);
            current = current.getNext();
        }
        return sum;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder();

        int max ;
        int index =-1;

        for (int i =0; i< iTermProjLinkedList.length; i++){
            max = -1;
            index = -1;
            for (int j = 0; j<iTermProjLinkedList.length; j++){
                if (iTermProjLinkedList.getAt(j).isPrinted()){
                   continue;
                }
                if (max < iTermProjLinkedList.getAt(j).getData().getPriority()){
                    max = iTermProjLinkedList.getAt(j).getData().getPriority();
                    index = j;

                }
            }
            s.append(iTermProjLinkedList.getAt(index).getData().toString());
            iTermProjLinkedList.getAt(index).setPrinted(true);
        }
        return s.toString();
    }
}
