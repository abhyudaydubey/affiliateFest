@WebServlet("/purchase")
public class PurchaseServlet extends HttpServlet {

    private static final Map<String, Double> affiliateCommission = new HashMap<>();

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException {
        // Dummy purchase amount
        double amount = 100.0;

        String affiliateId = (String) request.getSession().getAttribute("affiliate");

        if (affiliateId != null) {
            double commission = amount * 0.10; // 10% commission
            affiliateCommission.put(affiliateId, affiliateCommission.getOrDefault(affiliateId, 0.0) + commission);
            response.getWriter().println("Affiliate " + affiliateId + " earned ₹" + commission);
        } else {
            response.getWriter().println("Purchase made without affiliate.");
        }
    }
}
