public class TrigTerm extends LinearTerm{
    private TrigType trigType;

    TrigTerm(int value,TrigType trigType){
        super(value);
        this.trigType = trigType;
        if (trigType == TrigType.COSINE){
            setPriority(1);
        }
        else{
            setPriority(0);
        }
    }

    public void setTrigType(TrigType trigType) {
        this.trigType = trigType;
    }

    public TrigType getTrigType() {
        return trigType;
    }

    @Override
    public ITerm derivative() {
        if (this.trigType == TrigType.COSINE){
            return new TrigTerm(-getValue(),TrigType.SINE);
        }
        else{
            return new TrigTerm(getValue(),TrigType.COSINE);
        }
    }

    @Override
    public double evaluate(double value) {
        if (this.trigType == TrigType.COSINE){
            return getValue() * Math.cos(Math.toRadians(value));
        }
        else{
            return getValue() * Math.sin(value);
        }
    }

    @Override
    public String toString() {
        if (getValue() >= 0){
            if (trigType == TrigType.COSINE) return " + " + getValue() +"cos(x)";
            else return " + " + getValue() +"sin(x)";
        }
        else{
            if (trigType == TrigType.COSINE) return " - " + -getValue() +"cos(x)";
            else return " - " + -getValue() +"sin(x)";
        }
    }
}
