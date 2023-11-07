import java.text.SimpleDateFormat;
import java.util.Calendar;

public class ContractUtility {

    /**
     * This array represents the chart of the monthly rate of the package
     * Each row represent the Package while each row represents the Data bundle
     * <img src = "./img.png">
     */
    public static int [][] monthlyRates = {
                                            {500, 700, 900},
                                            {650, 850, 1050},
                                            {850, 1050, 1250,2000}
                                          };
    /**
     * Calculate the amount of the discount that contract has
     * <ul>
     *     <li>Business customer receive a 10% discount and must take at least a 12-month
     * contract.</li>
     *     <li>Charity customers receive a 30% discount for any length of contract</li>
     *     <li>Non-business customers taking a 12 or 18-month contract receive a 5% discount</li>
     *     <li>Non-business customers taking 24-month contract receive a 10% discount</li>
     * </ul>
     *
     */
    public static double calculateDiscount(ContractT type,int period){
        double discount = 0.0;

        switch (type){
            case NORMAL:
                // Handle the different periods of Normal type contracts
                if (period >= 12 && period <= 18){
                    discount = 0.05;
                }

                else if (period == 24) {
                    discount = 0.1;
                }

                break;
            case Business:
                // Sets the business contract if and only period is greater or equal to 12 months
                if (period >= 12){
                    discount = 0.1;
                }
                break;

            case Charity:
                discount = 0.3;
                break;

        }
        return discount;
    }

    /**
     * This function gets the monthly rate from the table (2d array) from the index by using PACKAGE  and DATA types values
     * Then apply the discount and apply the taxes for the international calls status
     * @param type      Type of the contract
     * @param discount  discount that applies to the contract
     * @param packageT  Package type of the contract
     * @param dataBundle   selected data bundle of the contract
     * @return  return the monthly total charge
     */
    public static double calculateMonthlyCharge(ContractT type,double discount,boolean isIntCallsAllow, PACKAGE packageT, DATA dataBundle){
        double charge;
        // Try to get the packages rate from the array. If the values give out of bound then pass a message to user
        try {
            charge = monthlyRates[packageT.ordinal()][dataBundle.ordinal()];
        }
        catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Large Package only have the Unlimited feature");
            return 0.0;
        }
        return charge;
    }

    /**
     * Function to check the Data package and the data bundle are compatible. If there is entry for package and the data bundle
     * then return true. If not compatible return false
     * @param packageT Package type of the Contract
     * @param dataBundle Data bundle of the Contract
     * @return  return true if package and data have an entry false otherwise
     */
    public static boolean isPackageValid(PACKAGE packageT, DATA dataBundle){
        // Small and Medium packages can not have Unlimited data plan
        if (packageT == PACKAGE.Small || packageT == PACKAGE.Medium){
            return dataBundle != DATA.Unlimited;
        }
        return true;
    }

    /**
     * This function generate the current triggered time and convert it to the string
     * @return A string that represents the date
     */
    public static String getDate(){
        Calendar cal = Calendar.getInstance();
        SimpleDateFormat sdf = new SimpleDateFormat("dd-MMM-yyyy");
        return sdf.format(cal.getTime());
    }



    public static void displayContract(Contract contract){
        System.out.println("+---------------------------------------------+");
        System.out.printf("|%46s\n","|");
        System.out.printf("|%9s: %-25s%10s\n","Customer",contract.getClientName(),"|");
        System.out.printf("|%9s: %-13s\tDate: %-12s|\n","Ref",contract.getRefNumber(),contract.getDate());
        System.out.printf("|%9s: %-13s\tData: %-12s|\n","Package",getPackage(contract.getPackageSize()),getDataBundle(contract.getDataBundle()));
        System.out.printf("|%9s: %-6s Months\tType: %-12s|\n","Period",contract.getPeriod(),contract.getType());
        String _package;
        String type;
    }

    /**
     * This message will return a string that indicates the databudle
     * @param dataBundle DATA type that represents the data bundle
     * @return A string that indicate the data bundle
     */
    public static String getDataBundle(DATA dataBundle){
        String postfix = "";

        // Add a postfix for each data bundle that indicate the capacity of the data amount
        switch (dataBundle){
            case Low -> postfix = " (1GB)";
            case Medium -> postfix = " (4GB)";
            case High -> postfix = " (8GB)";
            case Unlimited -> postfix = "";
        }
        return dataBundle + postfix;
    }

    /**
     * This message will return a string that indicates the package
     * @param packageT PACKAGE type that represents the data package
     * @return A string that indicate the package
     */
    public static String getPackage(PACKAGE packageT){
        String postfix = "";

        // Add a postfix for each data bundle that indicate the capacity of the data amount
        switch (packageT){
            case Small -> postfix = " (300)";
            case Medium -> postfix = " (600)";
            case Large -> postfix = " (1200)";
        }
        return packageT + postfix;
    }
}
