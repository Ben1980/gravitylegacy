#include "gravityConfig.h"
#include "solver/solver.h"
#include "solver/euler.h"
#include <cstdlib>

int main(int argc, char *argv[]) {
	Solver *solver = new Euler();

	system("pause");
	return 0;
}