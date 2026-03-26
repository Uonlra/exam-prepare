#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

static uint32_t ipToUint(const string& ip) {
	stringstream ss(ip);
	string part;
	uint32_t result = 0;
	for (int i = 0; i < 4; ++i) {
		getline(ss, part, '.');
		result = (result << 8) | static_cast<uint32_t>(stoi(part));
	}
	return result;
}

static void printIp(uint32_t x) {
	cout << ((x >> 24) & 255) << '.'
		 << ((x >> 16) & 255) << '.'
		 << ((x >> 8) & 255) << '.'
		 << (x & 255) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	if (!(cin >> n)) {
		return 0;
	}

	vector<uint32_t> ips;
	ips.reserve(n);

	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		ips.push_back(ipToUint(s));
	}

	uint32_t minIp = ips[0], maxIp = ips[0];
	for (int i = 1; i < n; ++i) {
		if (ips[i] < minIp) minIp = ips[i];
		if (ips[i] > maxIp) maxIp = ips[i];
	}

	uint32_t diff = minIp ^ maxIp;
	int commonPrefixLen = 32;
	while (diff) {
		--commonPrefixLen;
		diff >>= 1;
	}

	uint32_t mask;
	if (commonPrefixLen == 0) {
		mask = 0;
	} else {
		mask = 0xFFFFFFFFu << (32 - commonPrefixLen);
	}

	uint32_t network = minIp & mask;

	printIp(network);
	printIp(mask);

	return 0;
}
