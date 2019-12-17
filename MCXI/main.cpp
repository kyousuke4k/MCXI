//MCXI
#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
namespace cpp2
{
	class mcxi {
	public:
		mcxi(const std::basic_string<char> &mcxistr) : value_(0) {

			int digit = 1;
			for (auto pos = mcxistr.begin(); pos != mcxistr.end(); ++pos) {
				if (*pos >= '2' && *pos <= '9') {
					digit = static_cast<int>(*pos - '0');
				}
				else {
					switch (*pos) {
					case 'm':
						value_ += digit * 1000;
						break;
					case 'c':
						value_ += digit * 100;
						break;
					case 'x':
						value_ += digit * 10;
						break;
					case 'i':
						value_ += digit;
						break;
					default:
						std::cerr << "—áŠO‚ª”­¶‚µ‚Ü‚µ‚½" << std::endl;
						value_ = -1;
						break;
					}
				}
			}
		}

		const int &value() const {
			return value_;
		}

	private:
		int value_;//10iŠi”[•Ï”
	};
}//namespace cpp2


string mcxitran(int n) {
	int m, c, x, i;
	string mcxi;
	int sum=n;
	if (sum > 1000) {
		m = sum / 1000;
		sum = sum - m * 1000;
		if(m!=1)mcxi += to_string(m);
		mcxi += "m";
	}
	if (sum > 100) {
		c = sum / 100;
		sum = sum - c * 100;
		if (sum != 1)mcxi += to_string(c);
		mcxi += "c";
	}
	if (sum > 10) {
		x = sum / 10;
		sum = sum - x * 10;
		if (sum != 1)mcxi += to_string(x);
		mcxi += "x";
		i = sum;
		if(sum!=1)mcxi += to_string(i);
		mcxi += "i";
	}
	return mcxi;
}

int main(void) {
	//txtinclude
	std::ifstream inputfile("input.txt");
	std::string str;
	if (inputfile.fail()) {
		std::cerr << "input-error" << std::endl;
		return -1;
	}

	while (getline(inputfile, str)) {
		cpp2::mcxi a(str);
		std::cout << "a.value():" << a.value() << std::endl;
		std::cout << "str:" << str << std::endl;
		cout << mcxitran(a.value()) << endl;
		
	}
	return 0;
}