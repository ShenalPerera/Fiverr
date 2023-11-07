enum PACKAGE {Small, Medium, Large};
enum DATA {Low, Medium, High, Unlimited};
enum ContractT {NORMAL, Business, Charity};


public class Contract {

    private PACKAGE packageSize;            // hold the package size
    private DATA dataBundle;                // hold the data bundle type
    private String date;                    // keep the date details as a string
    private int period;                     // keep the duration of the package
    private boolean isAllowIntCalls;        // keep the boolean value to store
    private String refNumber;               // reference number of the contract
    private String clientName;              // Name of the client
    private double chargePerMonth;          // Monthly Charge (Default value without any discount or vat)
    private double discount;                // discount percentage
    private ContractT type;                 // type of the contract

    // Constructors
    public Contract(){};                    // default constructor

    /**
     * Class Constructor
     * @param packageSize   category of the package size
     * @param dataBundle    category of the data bundle (Low, Medium, High, Unlimited)
     * @param date      Date of the contact created
     * @param period    Time duration of the package
     * @param isAllowIntCalls   Is this contract allow the international calls
     * @param refNumber     reference number of the contract
     * @param clientName    name of the client
     * @param chargePerMonth    monthly charge (Default value without any discount or tax)
     *
     */
    public Contract(PACKAGE packageSize, DATA dataBundle, String date, int period, boolean isAllowIntCalls, String refNumber, String clientName , double chargePerMonth, int discount, ContractT type){
        this.packageSize = packageSize;
        this.dataBundle  = dataBundle;
        this.date = date;
        this.period = period;
        this.isAllowIntCalls = isAllowIntCalls;
        this.refNumber = refNumber;
        this.clientName = clientName;
        this.chargePerMonth = chargePerMonth;
        this.type = type;
        this.discount = discount;

    }


    /**
     * This an accessor function to get package size of the contract
     * @return  package size of the contract as PACKAGE type
     */
    public PACKAGE getPackageSize() {
        return packageSize;
    }


    /**
     * This an accessor function to get data bundle
     * @return  dataBundle of the class as DATA type
     */
    public DATA getDataBundle() {
        return dataBundle;
    }


    /**
     * This function will return the created date of the contract as a string
     * @return  string of the date
     */
    public String getDate() {
        return date;
    }


    /**
     * This function will return the period (duration) of the contract
     * @return  period of the contract as int
     */
    public int getPeriod() {
        return period;
    }


    /**
     * Accessor to get check the contract allows the international calls
     * @return return boolean based on the contract. True if allowable and false otherwise
     */
    public boolean isAllowIntCalls() {
        return isAllowIntCalls;
    }


    /**
     * This function will give the reference number of the contract
     * @return reference number of the contract
     */
    public String getRefNumber() {
        return refNumber;
    }


    /**
     * Accessor method to get the client name
     * @return name of the clint as a string
     */
    public String getClientName() {
        return clientName;
    }


    /**
     * Accessor method to get the monthly charge for the contract
     * @return monthly charge for the contract as double
     */
    public double getChargePerMonth() {
        return chargePerMonth;
    }


    /**
     * Accessor method to get the discount of the contract if have any
     * @return return the discount
     */
    public double getDiscount() {
        return discount;
    }


    /**
     * Accessor method to get the type of the contract. Check the contract is Normal, business or charity type
     * @return return the type of the contract as ContractT type
     */
    public ContractT getType() {
        return type;
    }


    /**
     * Sets the package size of the contract
     * @param packageSize PACKAGE data type containing the package size
     */
    public void setPackageSize(PACKAGE packageSize){
        this.packageSize = packageSize;
    }


    /**
     * Sets the data bundle type for the contract
     * @param dataBundle A DATA type containing the Data bundle type
     */
    public void setDataBundle(DATA dataBundle) {
        this.dataBundle = dataBundle;
    }


    /**
     * Sets the created date of the contract
     * @param date A string that contains the date of the creation of contract
     */
    public void setDate(String date) {
        this.date = date;
    }


    /**
     * Sets the period (duration) of the contract
     * @param period An int type holds the duration of the contract(package) in months
     */
    public void setPeriod(int period) {
        this.period = period;
    }


    /**
     * Sets the status of the allowably of the international calls
     * @param allowIntCalls A boolean represents the allowable of the Int. Calls (True =  Allow, False = Deny)
     */
    public void setAllowIntCalls(boolean allowIntCalls) {
        isAllowIntCalls = allowIntCalls;
    }


    /**
     * Sets the reference number of the contract
     * @param refNumber A string containing the reference number of the contract
     */
    public void setRefNumber(String refNumber) {
        this.refNumber = refNumber;
    }


    /**
     * Sets name of the client
     * @param clientName A string represents the name of the client
     */
    public void setClientName(String clientName) {
        this.clientName = clientName;
    }


    /**
     * Sets the charge per month
     * @param chargePerMonth Double represents the monthly charge
     */
    public void setChargePerMonth(double chargePerMonth) {
        this.chargePerMonth = chargePerMonth;
    }


    /**
     * Sets the discount of the contract. If not eligible any discount sets it as 0.0
     * @param discount A double represents that the percentage of the discount
     */
    public void setDiscount(double discount) {
        this.discount = discount;
    }

    /**
     * Sets the type of the contract
     * @param type ContractT type that represents the type of the contract
     */
    public void setType(ContractT type) {
        this.type = type;
    }

}
