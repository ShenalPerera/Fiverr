public class Main {
    private static final TrigType COSINE = TrigType.COSINE;
    private static final TrigType SINE = TrigType.SINE;

    public static void main(String[] args) {
        ITerm t1 = new LinearTerm(5);
        ITerm t2 = new PolynomialTerm(-4,3);
        ITerm t3 = new TrigTerm(-6,COSINE);


//        System.out.println(t1); // + 5x
//        System.out.println(t1.evaluate(5)); // 25
//        System.out.println(t2); // - 4x^3
//        System.out.println(t2.evaluate(2)); // -32
//        System.out.println(t3); // - 6cos(x)
//        System.out.println(t3.evaluate(45)); // -4.24

        Expression e1 = new Expression();
        e1.add(t1);
        e1.add(t2);
        e1.add(t3);
        Expression e2 = e1.getDerivative();

        System.out.println(e1); // - 4x^3 + 5x - 6cos(x)
        System.out.println(e2); // - 12x^2 + 5 + 6sin(x)
//        System.out.println(e1.getEvaluation(0));// -6
//        System.out.println(e2.getEvaluation(0));// 5


    }
}
