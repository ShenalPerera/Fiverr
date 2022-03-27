public class ConstantTerm implements ITerm{
    private int value;
    private int priority = 2;

    public ConstantTerm(int val){
        this.value = val;
    }

    public void setValue(int constTerm) {
        this.value = constTerm;
    }

    public int getValue() {
        return value;
    }

    @Override
    public double evaluate(double value) {
        return this.value;

    }

    public double evaluate(){
        return this.value;
    }

    @Override
    public String toString() {
        if (this.value >= 0){
            return " + "+ value ;
        }
        else{
            return " - " + -value;
        }

    }

    @Override
    public ITerm derivative() {
        return new ConstantTerm(0);
    }

    public int getPriority() {
        return priority;
    }

    public void setPriority(int priority) {
        this.priority = priority;
    }

    public int compareTo(ITerm constantTerm){
        return Integer.compare(this.priority, constantTerm.getPriority());
    }
}
