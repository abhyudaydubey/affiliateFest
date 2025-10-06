#include <iostream>
#include <unordered_map>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class URLShortener {
private:
    unordered_map<string, string> codeToUrl;
    unordered_map<string, string> urlToCode;
    string base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int counter = 0;

    // Generate a short code using base62
    string generateCode() {
        int temp = counter++;
        string code;
        while (temp > 0) {
            code += base[temp % 62];
            temp /= 62;
        }
        // Pad with 'a' if short
        while (code.length() < 6) code += 'a';
        return code;
    }

public:
    // Shorten the URL
    string shorten(string longUrl) {
        if (urlToCode.find(longUrl) != urlToCode.end()) {
            return "short.ly/" + urlToCode[longUrl]; // we need other domain
        }

        string code = generateCode();
        codeToUrl[code] = longUrl;
        urlToCode[longUrl] = code;
        return "short.ly/" + code;
    }

    // Expand short code back to long URL
    string expand(string shortUrl) {
        string code = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        if (codeToUrl.find(code) != codeToUrl.end()) {
            return codeToUrl[code];
        } else {
            return "Error: Short URL not found!";
        }
    }

    // Show all mappings
    void showAll() {
        cout << "\n--- All Stored URLs ---\n";
        for (auto& pair : codeToUrl) {
            cout << "short.ly/" << pair.first << " → " << pair.second << endl;
        }
    }
};

int main() {
    URLShortener shortener;
    int choice;
    string longUrl, shortUrl;

    do {
        cout << "\n=== URL Shortener ===\n";
        cout << "1. Shorten URL\n2. Expand URL\n3. Show All\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // ignore newline after number input

        switch (choice) {
            case 1:
                cout << "Enter long URL: ";
                getline(cin, longUrl);
                cout << "Shortened URL: " << shortener.shorten(longUrl) << endl;
                break;
            case 2:
                cout << "Enter short URL: ";
                getline(cin, shortUrl);
                cout << "Original URL: " << shortener.expand(shortUrl) << endl;
                break;
            case 3:
                shortener.showAll();
                break;
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
