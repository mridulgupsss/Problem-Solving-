class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int i1=num1.find('+');
        int i2=num2.find('+');
        int a = stoi(num1.substr(0, i1));
        int c = stoi(num2.substr(0, i2));
        int b = stoi(num1.substr(i1+1, num1.length()-2-i1));
        int d = stoi(num2.substr(i2+1, num2.length()-2-i2));
        
        return to_string((a*c) - (b*d)) + '+' + to_string(c*b + (a*d)) + 'i';
        
    }
};