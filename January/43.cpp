#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 43. Multiply Strings

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    int num1_len = num1.length();
    int num2_len = num2.length();
    
    // Vector storing result
    vector<int> result(num1_len + num2_len, 0);

    // Reverse iterate over both numbers
    for (int i = num1_len - 1; i >= 0; i--) {
        for (int j = num2_len - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0'); 
            int sum = mul + result[i + j + 1];         

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string output = "";
    for (int num : result) {
        if (!(output.empty() && num == 0)) {
            output += to_string(num);
        }
    }

    return output.empty() ? "0" : output;
}

int main() {
    string str1 = "10";
    string str2 = "20";

    cout << multiply(str1, str2) << endl;
}


