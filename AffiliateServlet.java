@WebServlet("/product")
public class ProductServlet extends HttpServlet {

    private static final Map<String, Integer> affiliateClicks = new HashMap<>();

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String affiliateId = request.getParameter("ref");
        String productId = request.getParameter("id");

        // Track affiliate click
        if (affiliateId != null) {
            affiliateClicks.put(affiliateId, affiliateClicks.getOrDefault(affiliateId, 0) + 1);
            // Store in session for purchase tracking
            request.getSession().setAttribute("affiliate", affiliateId);
        }

        response.getWriter().println("Showing product: " + productId);
    }
}
