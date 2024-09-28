import Sudoku


if __name__ == "__main__":
    sudoku = Sudoku.sudoku("017903600000080000900000507072010430000402070064370250701000065000030000005601720")
    assert sudoku.solve() == True
    print("All tests passed!")