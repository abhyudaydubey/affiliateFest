#include <iostream>
#include <map>
#include <string>

using namespace std;

// In-memory data storage
map<string, int> affiliateClicks;
map<string, double> affiliateCommission;

// Generate affiliate link
string generateAffiliateLink(const string& baseUrl, const string& productId, const string& affiliateId) {
    return baseUrl + "/product?id=" + productId + "&ref=" + affiliateId;
}

// Simulate product page visit with affiliate ID
void visitProductPage(const string& affiliateId) {
    affiliateClicks[affiliateId]++;
    cout << "Product page visited via affiliate: " << affiliateId << endl;
}

// Simulate purchase
void makePurchase(const string& affiliateId, double amount) {
    if (affiliateId.empty()) {
        cout << "Purchase made without affiliate.\n";
        return;
    }

    double commission = amount * 0.10; // 10% commission
    affiliateCommission[affiliateId] += commission;

    cout << "Affiliate " << affiliateId << " earned ₹" << commission << " on this purchase.\n"; // redundant code found
}

void showReports() {
    cout << "\n--- Affiliate Click Report ---\n";
    for (const auto& [id, clicks] : affiliateClicks) {
        cout << "Affiliate ID: " << id << " | Clicks: " << clicks << endl;
    }

    cout << "\n--- Affiliate Commission Report ---\n";
    for (const auto& [id, comm] : affiliateCommission) {
        cout << "Affiliate ID: " << id << " | Commission Earned: ₹" << comm << endl;
    }
}

int main() {
    string baseUrl = "https://yourapp.com";
    string affiliateId = "AFF123";
    string productId = "P001";

    string link = generateAffiliateLink(baseUrl, productId, affiliateId);
    cout << "Generated Affiliate Link: " << link << endl;

    // Simulate some user activity
    visitProductPage(affiliateId);
    visitProductPage(affiliateId);

    makePurchase(affiliateId, 500.0);
    makePurchase(affiliateId, 300.0);

    showReports();

    return 0;
}
