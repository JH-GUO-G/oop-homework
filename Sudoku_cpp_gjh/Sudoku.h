#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <string>
#include <iostream>

class Sudoku {
private:
    std::vector<std::vector<int>> grid;
    const int BOX_SIZE = 3;
    const int GRID_SIZE = 9;

public:
    Sudoku(const std::string& input);
    bool isok(int row, int col, int num);
    bool solve();
};

Sudoku::Sudoku(const std::string& input) {
    grid.resize(GRID_SIZE, std::vector<int>(GRID_SIZE, 0));
    for (int i = 0; i < input.length(); i++) {
        int num = input[i] - '0';
        grid[i / GRID_SIZE][i % GRID_SIZE] = num;
    }
}

bool Sudoku::isok(int row, int col, int num) {
    // Check row
    for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[row][j] == num) return false;
    }
    // Check column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[i][col] == num) return false;
    }
    // Check box
    int startRow = row - row % BOX_SIZE, startCol = col - col % BOX_SIZE;
    for (int i = 0; i < BOX_SIZE; i++) {
        for (int j = 0; j < BOX_SIZE; j++) {
            if (grid[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

bool Sudoku::solve() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isok(i, j, num)) {
                        grid[i][j] = num;//候选
                        if (solve()) return true;//候选进入后成功不断迭代到最后解
                        grid[i][j] = 0; // 候选失败，进入下一个候选值
                    }
                }
                return false;
            }
        }
    }
    return true;
}
#endif // SUDOKU_H