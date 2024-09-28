#include "Sudoku.h"
#include <cassert>

int main() {
    std::string input = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku(input);
    assert(sudoku.solve()==true);
    std::cout << "All tests passed!" << std::endl;
    return 0;
}