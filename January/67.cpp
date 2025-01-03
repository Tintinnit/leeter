#include <iostream>
#include <string>
using namespace std;

// Function to reverse a string
void reverseString(string& str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

// Function to add two binary strings
string addBinary(string a, string b) {
    int a_len = a.length();
    int b_len = b.length();

    reverseString(a);
    reverseString(b);

    string output = "";
    int carry = 0;

    for (int i = 0; i < max(a_len, b_len); ++i) {
        int digitA = (i < a_len) ? a[i] - '0' : 0;
        int digitB = (i < b_len) ? b[i] - '0' : 0;

        int sum = digitA + digitB + carry;
        output += (sum % 2) + '0';
        carry = sum / 2;
    }

    // Append carry if it exists
    if (carry) {
        output += '1';
    }

    // Reverse the result to get the correct order
    reverseString(output);
    return output;
}

// Example usage
int main() {
    string a = "1010";
    string b = "1011";

    string result = addBinary(a, b);
    cout << "Sum: " << result << endl;

    return 0;
}
