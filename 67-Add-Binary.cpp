class Solution {
public:
    string addBinary(string a, string b) {
        int sum ;
        int carry = 0;
        string result ;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while(i >= 0 || j >= 0 || carry){
            sum = carry;
            if( i >= 0){
                sum = sum + a[i] - '0';
                i--;
            }
            if( j >= 0){
                sum = sum + b[j] -'0';
                j--;
            }
            carry = sum/2;
            result += (sum%2) + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};