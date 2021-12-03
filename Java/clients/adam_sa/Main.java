

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static ArrayList<CVE> cves = new ArrayList<>();
    static ArrayList<Product> products = new ArrayList<>();
    static ArrayList<Vendor> vendors = new ArrayList<>();

    public static void main(String[] args) {
        readData();
        Scanner in = new Scanner(System.in);

        while (true) {
            System.out.println("1. List All Vendors");
            System.out.println("2. List CVEs caused by CWE Code");
            System.out.println("3. List CVEs caused by CWE Code (Clustered by CVSS)");
            System.out.println("4. Display Vendor & Product for a CVE ID");
            System.out.println("5. Display CVE for a Vendor");
            System.out.println("6. Vendor with highest CVEs");
            System.out.println("7. Vendor with worst Cumulative CVSS");
            System.out.println("8. Sort in Ascending");
            System.out.println("9. Find Record with Incomplete Data");
            System.out.println("0. Exit");
            System.out.print("Choose: ");
            int choice = in.nextInt();
            switch (choice) {
                case 1:
                    listVendors();
                    break;
                case 2:
                    listCVEsbyCWECode(false);   //for without clustering
                    break;
                case 3:
                    listCVEsbyCWECode(true);    //for with clustering
                    break;
                case 4:
                    listDetailsForCVE();
                    break;
                case 5:
                    listCVEforVendor();
                    break;
                case 6:
                    VendorWithHighestCVEs();
                    break;
                case 7:
                    findWorstCVSS();
                    break;
                case 8:
                    sort();
                    break;
                case 9:
                    findIncompleteRecord();
                    break;
                case 0:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invaid Input!");
                    break;
            }
            System.out.println("");
        }
    }

    public static void listVendors() {
        for (int a = 0; a < vendors.size(); a++) {
            System.out.println(vendors.get(a).toString());
        }
        System.out.println("Total Vendors: " + vendors.size());
    }

    public static void listCVEsbyCWECode(boolean cluster) {
        Scanner in = new Scanner(System.in);
        System.out.print("CWE Code: ");
        int code = in.nextInt();
        if (!cluster) {
            for (int a = 0; a < cves.size(); a++) {
                if (code == cves.get(a).getCweCode()) {
                    System.out.println(cves.get(a).getCveID());
                }
            }
        } else if (cluster) {
            //get the highest range for clustering
            double max = cves.get(0).getCVSS();
            double min = cves.get(0).getCVSS();
            for (int a = 0; a < cves.size(); a++) {
                if (max < cves.get(a).getCVSS()) {
                    max = cves.get(a).getCVSS();
                }
                if (min > cves.get(a).getCVSS()) {
                    min = cves.get(a).getCVSS();
                }
            }

            for (double a = min; a < max; a++) {
                double start = a;
                double end = a + 1;
                System.out.println("From " + start + " to " + end + ": ");
                for (int b = 0; b < cves.size(); b++) {
                    if (code == cves.get(b).getCweCode()
                            && (cves.get(b).getCVSS() >= start && cves.get(b).getCVSS() <= end)) {
                        System.out.println("\t" + cves.get(b).getCveID());
                    }
                }
            }
        }
    }

    public static void listDetailsForCVE() {
        Scanner in = new Scanner(System.in);
        System.out.print("CWE ID: ");
        String id = in.next();
        System.out.println("Vendor(s): ");
        for (int a = 0; a < vendors.size(); a++) {
            if (vendors.get(a).getCveID().equalsIgnoreCase(id)) {
                System.out.println("   " + vendors.get(a).getVendor());
            }
        }
        System.out.println("");
        System.out.println("Product(s): ");
        for (int a = 0; a < products.size(); a++) {
            if (products.get(a).getCveID().equalsIgnoreCase(id)) {
                System.out.println("   " + products.get(a).getProduct());
            }
        }

    }

    public static void listCVEforVendor() {
        Scanner in = new Scanner(System.in);
        System.out.print("Vendor: ");
        String vendor = in.nextLine();
        String id = "";
        for (int a = 0; a < vendors.size(); a++) {
            if (vendors.get(a).getVendor().equalsIgnoreCase(vendor)) {
                id = vendors.get(a).getCveID();
            }
        }

        for (int a = 0; a < cves.size(); a++) {
            if (cves.get(a).getCveID().equalsIgnoreCase(id)) {
                System.out.println("   CVE ID: " + cves.get(a).getCveID());
                System.out.println("   Product: " + getProduct(cves.get(a).getCveID()));
                System.out.println("   CWE Code: " + cves.get(a).getCweCode());
                System.out.println("");
            }
        }

    }

    public static void VendorWithHighestCVEs() {
        int highest = 0;
        String highestVendor = "";
        //finding the vendor with highest number of CVEs
        for (int a = 0; a < vendors.size(); a++) {
            String id = vendors.get(a).getCveID();
            String vendor = vendors.get(a).getVendor();
            int count = 0;
            for (int b = 0; b < vendors.size(); b++) {
                if (vendors.get(b).getCveID().equalsIgnoreCase(id)) {
                    count++;
                }
            }
            if (highest < count) {
                highest = count;
                highestVendor = vendor;
            }
        }

        System.out.println("Vendor with Highest CVEs: " + highestVendor);
        System.out.println("CVEs: ");
        for (int a = 0; a < vendors.size(); a++) {
            if (vendors.get(a).getVendor().equalsIgnoreCase(highestVendor)) {
                String vid = vendors.get(a).getCveID();
                for (int b = 0; b < cves.size(); b++) {
                    if (vid.equalsIgnoreCase(cves.get(b).getCveID())) {
                        System.out.println("   ID: " + cves.get(b).getCveID() + "  Pub Date: " + cves.get(b).getPubDate());
                    }
                }
            }
        }

    }

    public static void findWorstCVSS() {
        double max = 0;
        String worstVendor = "";
        //finding the vendor with lowest CVSS
        for (int a = 0; a < vendors.size(); a++) {
            String vendor = vendors.get(a).getVendor();
            double score = 0;
            for (int b = 0; b < vendors.size(); b++) {
                if (vendors.get(b).getVendor().equalsIgnoreCase(vendor)) {
                    String id = vendors.get(b).getCveID();
                    for (int c = 0; c < cves.size(); c++) {
                        if (cves.get(c).getCveID().equalsIgnoreCase(id)) {
                            score += cves.get(c).getCVSS();
                        }
                    }
                }
            }
            if (max < score) {
                max = score;
                worstVendor = vendor;
            }

        }
        String vendor = worstVendor;
        for (int b = 0; b < vendors.size(); b++) {
            if (vendors.get(b).getVendor().equalsIgnoreCase(vendor)) {
                String id = vendors.get(b).getCveID();
                for (int c = 0; c < cves.size(); c++) {
                    if (cves.get(c).getCveID().equalsIgnoreCase(id)) {
                        System.out.println("   ID: " + cves.get(c).getCveID() + "  CVSS: " + cves.get(c).getCVSS());
                    }
                }
            }
        }
    }

    public static void sort() {
        for (int a = 0; a < cves.size(); a++) {
            for (int b = 1; b < (cves.size() - a); b++) {
                if(cves.get(b-1).getRatio() > cves.get(b).getRatio()){
                    CVE temp = cves.get(b-1);
                    cves.set(b-1, cves.get(b));
                    cves.set(b, temp);
                }
            }
        }
    }

    public static void findIncompleteRecord() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter Any Keyword to find Incomplete Records: ");
        String keyword = in.nextLine();

        for (int a = 0; a < cves.size(); a++) {
            if (cves.get(a).toString().contains(keyword)) {
                System.out.println(cves.get(a).toString());
            }
        }
    }

    public static void readData() {
        try {
            Scanner in = new Scanner(new File("C:\\Users\\adams\\Desktop\\Task\\Mk1\\SampleDataset\\SampleDataset-CVE.csv"));
            in.nextLine();
            while (in.hasNextLine()) {
                String line = in.nextLine();
                if (line.startsWith("CVE")) {
                    String[] recs = line.split(",");
                    if (recs.length <= 1) {
                        continue;
                    }
                    String cveID = "";
                    if (!recs[0].equals("")) {
                        cveID = recs[0];
                    }
                    String modDate = "";
                    if (!recs[1].equals("")) {
                        modDate = recs[1];
                    }
                    String pubDate = "";
                    if (!recs[2].equals("")) {
                        pubDate = recs[2];
                    }
                    double CVSS = 0;
                    if (!recs[3].equals("")) {
                        CVSS = Double.parseDouble(recs[3]);
                    }
                    int cweCode = 0;
                    if (!recs[4].equals("")) {
                        cweCode = Integer.parseInt(recs[4]);
                    }
                    String cweName = "";
                    if (!recs[5].equals("")) {
                        cweName = recs[5];
                    }
                    String summary = "";
                    if (!recs[6].equals("")) {
                        summary = recs[6];
                    }
                    if (recs.length == 7) {
                        CVE cve = new CVE(cveID, modDate, pubDate, CVSS, cweCode, cweName,
                                summary, "", "", "", "", "", "");
                        cves.add(cve);
                        continue;
                    }
                    String accessAuthentication = "";
                    if (!recs[7].equals("")) {
                        accessAuthentication = recs[7];
                    }
                    if (recs.length == 8) {
                        CVE cve = new CVE(cveID, modDate, pubDate, CVSS, cweCode, cweName,
                                summary, accessAuthentication, "", "", "", "", "");
                        cves.add(cve);
                        continue;
                    }
                    String accessComplexity = "";
                    if (!recs[8].equals("")) {
                        accessComplexity = recs[8];
                    }
                    if (recs.length == 9) {
                        CVE cve = new CVE(cveID, modDate, pubDate, CVSS, cweCode, cweName, summary,
                                accessAuthentication, accessComplexity, "", "", "", "");
                        cves.add(cve);
                        continue;
                    }
                    String accessVector = "";
                    if (!recs[9].equals("")) {
                        accessVector = recs[9];
                    }
                    if (recs.length == 10) {
                        CVE cve = new CVE(cveID, modDate, pubDate, CVSS, cweCode, cweName, summary,
                                accessAuthentication, accessComplexity, accessVector, "", "", "");
                        cves.add(cve);
                        continue;
                    }
                    String impactAvailability = "";
                    if (!recs[10].equals("")) {
                        impactAvailability = recs[10];
                    }
                    if (recs.length == 11) {
                        CVE cve = new CVE(cveID, modDate, pubDate, CVSS, cweCode, cweName, summary,
                                accessAuthentication, accessComplexity, accessVector, impactAvailability, "", "");
                        cves.add(cve);
                        continue;
                    }
                    String impactConfidentiality = "";
                    if (!recs[11].equals("")) {
                        impactConfidentiality = recs[11];
                    }
                    if (recs.length == 12) {
                        CVE cve = new CVE(cveID, modDate, pubDate, CVSS, cweCode, cweName, summary,
                                accessAuthentication, accessComplexity, accessVector, impactAvailability, impactConfidentiality, "");
                        cves.add(cve);
                        continue;
                    }
                    String impactIntegrity = "";
                    if (!recs[12].equals("")) {
                        impactIntegrity = recs[12];
                    }
                    CVE cve = new CVE(cveID, modDate, pubDate, CVSS, cweCode, cweName, summary, accessAuthentication,
                            accessComplexity, accessVector, impactAvailability, impactConfidentiality, impactIntegrity);
                    cves.add(cve);
                }
            }

            in = new Scanner(new File("C:\\Users\\adams\\Desktop\\Task\\Mk1\\SampleDataset\\SampleDataset-Vendors.csv"));
            while (in.hasNextLine()) {
                String line = in.nextLine();
                String[] recs = line.split(",");
                if (recs.length == 2) {
                    Vendor v = new Vendor(recs[0], recs[1]);
                    vendors.add(v);
                }
            }

            in = new Scanner(new File("C:\\Users\\adams\\Desktop\\Task\\Mk1\\SampleDataset\\SampleDataset-Products.csv"));
            while (in.hasNextLine()) {
                String line = in.nextLine();
                String[] recs = line.split(",");
                if (recs.length == 2) {
                    Product p = new Product(recs[0], recs[1]);
                    products.add(p);
                }
            }
        } catch (FileNotFoundException ex) {
            System.out.println(ex.getMessage());
            System.exit(0);
        }

    }

    public static String getProduct(String cveID) {
        for (int a = 0; a < products.size(); a++) {
            if (products.get(a).getCveID().equalsIgnoreCase(cveID)) {
                return products.get(a).getProduct();
            }
        }
        return "No Product Found";
    }

}
