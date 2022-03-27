public interface ITerm {
    public ITerm derivative();
    public double evaluate(double value);
    public String toString();
    public int getValue();
    public int compareTo(ITerm iTerm);

    public int getPriority();
}
