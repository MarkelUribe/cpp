#include "Base.hpp"

int main(void) {
	Base* x = generate();

	identify(x);

	identify(*x);

	delete(x);

	return (0);
}