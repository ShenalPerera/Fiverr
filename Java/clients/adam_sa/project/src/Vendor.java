

public class Vendor {
    private String cveID;
    private String vendor;

    public Vendor(String cveID, String vendor) {
        this.cveID = cveID;
        this.vendor = vendor;
    }

    public String getCveID() {
        return cveID;
    }

    public void setCveID(String cveID) {
        this.cveID = cveID;
    }

    public String getVendor() {
        return vendor;
    }

    public void setVendor(String vendor) {
        this.vendor = vendor;
    }

    @Override
    public String toString() {
        return "CVE ID: " + cveID + ", Vendor: " + vendor;
    }
    
}