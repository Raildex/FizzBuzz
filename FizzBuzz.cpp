#include <span>
#include <string>
#include <functional>
#include <array>
#include <numeric>
#include <iostream>
struct fizz_buzz_entry {
	std::string sequence;
	std::function<bool(long long)> predicate;
};

template<typename Iter>
void fizz_buzz(Iter begin, Iter end, std::span<fizz_buzz_entry> trigger_map) {
	for (auto i = begin; i != end; i++) {
		auto integer = *i;
		std::string string = "";
		bool predicate_hit = false;
		for (const auto& e : trigger_map) {
			if (e.predicate(integer)) {
				predicate_hit = true;
				string += e.sequence;
			}
		}
		if (predicate_hit) {
			std::cout << string << std::endl;
		}
		else {
			std::cout << std::to_string(integer) << std::endl;
		}
	}
}

int main() {
	std::vector<long long> integers(400);
	std::iota(integers.begin(), integers.end(), 0);
	std::array triggers = {
		fizz_buzz_entry {"Fizz", [](long long i) { return i % 3 == 0; }},
		fizz_buzz_entry {"Buzz", [](long long i) { return i % 5 == 0; }},
		//fizz_buzz_entry {"Bazz", [](long long i) { return i % 7 == 0; }},
	};
	fizz_buzz(integers.begin(), integers.end(), triggers);
	return 0;
}
