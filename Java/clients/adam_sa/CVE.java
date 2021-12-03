

public class CVE {
    
    private String cveID;
    private String modDate;
    private String pubDate;
    private double CVSS;
    private int cweCode;
    private String cweName;
    private String summary;
    
    private String accessAuthentication;
    private String accessComplexity;
    private String accessVector;
    private String impactAvailability;
    private String impactConfidentiality;
    private String impactIntegrity;

    public CVE(String cveID, String modDate, String pubDate, double CVSS, int cweCode, 
            String cweName, String summary, String accessAuthentication, 
            String accessComplexity, String accessVector, String impactAvailability, 
            String impactConfidentiality, String impactIntegrity) {
        this.cveID = cveID;
        this.modDate = modDate;
        this.pubDate = pubDate;
        this.CVSS = CVSS;
        this.cweCode = cweCode;
        this.cweName = cweName;
        this.summary = summary;
        this.accessAuthentication = accessAuthentication;
        this.accessComplexity = accessComplexity;
        this.accessVector = accessVector;
        this.impactAvailability = impactAvailability;
        this.impactConfidentiality = impactConfidentiality;
        this.impactIntegrity = impactIntegrity;
    }
    
    public double getRatio(){
        int impact = 0;
        if(this.getImpactAvailability().equals("NONE")){
            impact = 1;
        }
        else if(this.getImpactAvailability().equals("NONE")){
            impact = 2;
        }
        else if(this.getImpactAvailability().equals("NONE")){
            impact = 3;
        }
        
        int access = 0;
        if(this.getImpactAvailability().equals("LOW")){
            access = 1;
        }
        else if(this.getImpactAvailability().equals("MEDIUM")){
            access = 2;
        }
        else if(this.getImpactAvailability().equals("HIGH")){
            access = 3;
        }
        if(impact == 0 || access == 0){
            return 0;
        }
        return impact/access;
    }

    public String getCveID() {
        return cveID;
    }

    public void setCveID(String cveID) {
        this.cveID = cveID;
    }

    public String getModDate() {
        return modDate;
    }

    public void setModDate(String modDate) {
        this.modDate = modDate;
    }

    public String getPubDate() {
        return pubDate;
    }

    public void setPubDate(String pubDate) {
        this.pubDate = pubDate;
    }

    public double getCVSS() {
        return CVSS;
    }

    public void setCVSS(double CVSS) {
        this.CVSS = CVSS;
    }

    public int getCweCode() {
        return cweCode;
    }

    public void setCweCode(int cweCode) {
        this.cweCode = cweCode;
    }

    public String getCweName() {
        return cweName;
    }

    public void setCweName(String cweName) {
        this.cweName = cweName;
    }

    public String getSummary() {
        return summary;
    }

    public void setSummary(String summary) {
        this.summary = summary;
    }

    public String getAccessAuthentication() {
        return accessAuthentication;
    }

    public void setAccessAuthentication(String accessAuthentication) {
        this.accessAuthentication = accessAuthentication;
    }

    public String getAccessComplexity() {
        return accessComplexity;
    }

    public void setAccessComplexity(String accessComplexity) {
        this.accessComplexity = accessComplexity;
    }

    public String getAccessVector() {
        return accessVector;
    }

    public void setAccessVector(String accessVector) {
        this.accessVector = accessVector;
    }

    public String getImpactAvailability() {
        return impactAvailability;
    }

    public void setImpactAvailability(String impactAvailability) {
        this.impactAvailability = impactAvailability;
    }

    public String getImpactConfidentiality() {
        return impactConfidentiality;
    }

    public void setImpactConfidentiality(String impactConfidentiality) {
        this.impactConfidentiality = impactConfidentiality;
    }

    public String getImpactIntegrity() {
        return impactIntegrity;
    }

    public void setImpactIntegrity(String impactIntegrity) {
        this.impactIntegrity = impactIntegrity;
    }

    @Override
    public String toString() {
        return "CVE ID: " + cveID + ", Modification Date: " + modDate + ", Publish Date: " + pubDate + 
                ", CVSS: " + CVSS + ", CWE Code: " + cweCode + ", CWE Name: " + cweName + 
                ", Summary: " + summary + ", Access Authentication: " + accessAuthentication + 
                ", Access Complexity: " + accessComplexity + ", Access Vector: " + accessVector + 
                ", Impact Availability: " + impactAvailability + 
                ", Impact Confidentiality: "+ impactConfidentiality + ", Impact Integrity: " + impactIntegrity;
    }
    
}
