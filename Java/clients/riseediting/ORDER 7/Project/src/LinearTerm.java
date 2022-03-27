import java.text.DecimalFormat;

public class LinearTerm extends ConstantTerm{

    public LinearTerm(int value){
        super(value);
        setPriority(3);
    }

    @Override
    public ITerm derivative() {
        return new ConstantTerm(getValue());
    }

    @Override
    public double evaluate(double value) {

        return getValue() * value;
    }

    @Override
    public String toString() {
        if (getValue() >= 0 ){
            return " + "+ getValue()+ "x";
        }
        else{
            return " - "+ -getValue() + "x";
        }
    }
}
