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
            case BUSINESS:
                // Sets the business contract if and only period is greater or equal to 12 months
                if (period >= 12){
                    discount = 0.1;
                }
                break;

            case CHARITY:
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
}
