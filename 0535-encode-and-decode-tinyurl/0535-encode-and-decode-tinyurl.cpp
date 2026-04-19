class Solution {
private:
    unordered_map<string, string> shortToLong;
    unordered_map<string, string> longToShort;
    long long id = 1;

    string base62 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // Convert number → Base62 string
    string encodeBase62(long long num) {
        if (num == 0) return "a";

        string res = "";
        while (num > 0) {
            res += base62[num % 62];
            num /= 62;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    // Encode long URL → short URL
    string encode(string longUrl) {
        // If already encoded, return existing short URL
        if (longToShort.count(longUrl)) {
            return longToShort[longUrl];
        }

        string shortCode = encodeBase62(id++);
        shortToLong[shortCode] = longUrl;
        longToShort[longUrl] = shortCode;

        // You can prepend a domain if you want
        // e.g. return "https://mytinyurlservice.com/" + shortCode;
        return shortCode;
    }

    // Decode short URL → original URL
    string decode(string shortUrl) {
        if (shortToLong.count(shortUrl)) {
            return shortToLong[shortUrl];
        }
        return ""; // or handle error
    }
};