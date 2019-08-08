#include "../pub.h"

class Solution {
public:
    string decodeString(string s);
    string decodeString(const string& s, int& i, const int& len);
};

string Solution::decodeString(string s) {
    int i = 0;
    int len = static_cast<int>(s.size());
    return decodeString(s, i, len);
}

string Solution::decodeString(const string& s, int& i, const int& len) {
    string res;
    while (i < len && s[i] != ']') {
        if (!isdigit(s[i])) {
            res += s[i++];
        } else {
            int n = 0;
            while (i < len && isdigit(s[i])) {
                n = n * 10 + s[i++] - '0';
            }
            i++; // [
            string t = decodeString(s, i, len);
            i++; // ]
            while (n-- > 0) {
                res += t;
            }
        }
    }
    return res;
}

int main() {
    string s{"3[a]2[bc]"};
    Solution obj;
    cout << s << endl << obj.decodeString(s) << endl;;

}
