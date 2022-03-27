public class PolynomialTerm extends LinearTerm {
    private int power;

    PolynomialTerm(int polyConst ,int power ){
        super(polyConst);
        this.power = power;
        setPriority(4*power);
    }


    public int getPower() {
        return power;
    }

    public void setPower(int power) {
        this.power = power;
    }

    @Override
    public ITerm derivative() {
        if (power > 2){
            return new PolynomialTerm(power * getValue(),power -1);
        }
        else if (power == 2){
            return new LinearTerm(2 * getValue());
        }
        else {
            return null;
        }
    }

    @Override
    public double evaluate(double value) {
        return getValue() * Math.pow(value,power);
    }

    @Override
    public String toString() {
        if (getValue() >= 0){
            return "+ " + getValue() + "x^" + power;
        }
        return "- " + -getValue() + "x^" + power;
    }
}
