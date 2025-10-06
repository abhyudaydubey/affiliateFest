public class AffiliateLinkGenerator {
    public static String generateLink(String baseUrl, String productId, String affiliateId) {
        return String.format("%s/product?id=%s&ref=%s", baseUrl, productId, affiliateId);
    }

    public static void main(String[] args) {
        String link = generateLink("https://yourapp.com", "123", "AFF001");
        System.out.println("Affiliate Link: " + link);
    }
}
