public class Main {

    public static void main(String[] args) {
	// write your code here
        Contract contract = new Contract(PACKAGE.Large,DATA.Low,"22 oct 2022",12, false,"JB123B","J Mason",7.65,10,ContractT.Business);
        ContractUtility.displayContract(contract);
    }
}
