
public class Product {
    
    private String cveID;
    private String product;

    public Product(String cveID, String product) {
        this.cveID = cveID;
        this.product = product;
    }

    public String getCveID() {
        return cveID;
    }

    public void setCveID(String cveID) {
        this.cveID = cveID;
    }

    public String getProduct() {
        return product;
    }

    public void setProduct(String product) {
        this.product = product;
    }
    
}