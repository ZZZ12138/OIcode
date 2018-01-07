#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string tot[21];

bool cmp(string a, string b) {
	a += a;
	b += b;
	return a < b;
}

int main() {
	string temp;
	int count = 0;
	while (cin >> temp) {
		if (temp == ".") break;
		if (temp == "zero") tot[count++] = "00";
		if (temp == "one") tot[count++] = "01";
		if (temp == "two") tot[count++] = "04";
		if (temp == "three") tot[count++] = "09";
		if (temp == "four") tot[count++] = "16";
		if (temp == "five") tot[count++] = "25";
		if (temp == "six") tot[count++] = "36";
		if (temp == "seven") tot[count++] = "49";
		if (temp == "eight") tot[count++] = "64";
		if (temp == "nine") tot[count++] = "81";
		if (temp == "ten") tot[count++] = "00";
		if (temp == "eleven") tot[count++] = "21";
		if (temp == "twelve") tot[count++] = "44";
		if (temp == "thirteen") tot[count++] = "69";
		if (temp == "fourteen ") tot[count++] = "96";
		if (temp == "fifteen") tot[count++] = "25";
		if (temp == "sixteen") tot[count++] = "56";
		if (temp == "seventeen") tot[count++] = "89";
		if (temp == "eighteen") tot[count++] = "24";
		if (temp == "nineteen") tot[count++] = "61";
		if (temp == "twenty") tot[count++] = "00";
		if (temp == "a") tot[count++] = "01";
		if (temp == "both") tot[count++] = "04";
		if (temp == "another") tot[count++] = "01";
		if (temp == "first") tot[count++] = "01";
		if (temp == "second") tot[count++] = "04";
		if (temp == "third") tot[count++] = "09";
	}

	sort(tot, tot + count, cmp);
	string out;
	for (int i = 0; i < count; i++) {
		out += tot[i];
	}

	string::iterator it;
	for (it = out.begin(); it != out.end();) {
		if (*it == '0') {
			out.erase(it);
			it = out.begin();
		}
		else break;
	}
	cout << out;
	if (count == 0) cout << "0";
	return 0;
}
