class sudoku:
    def __init__(self, input):
        self.GRID_SIZE = 9
        self.BOX_SIZE = 3
        self.grid = self.parse(input)

    def parse(self, input):
        grid = [[0] * self.GRID_SIZE for _ in range(self.GRID_SIZE)]
        for i, char in enumerate(input):
            num = int(char) if char.isdigit() else 0
            grid[i // self.GRID_SIZE][i % self.GRID_SIZE] = num
        return grid

    def get_grid(self):
        return self.grid

    def get_row(self, row):
        return self.grid[row]

    def get_column(self, col):
        return [self.grid[i][col] for i in range(self.GRID_SIZE)]

    def get_box(self, row, col):
        box = []
        for i in range(row - row % self.BOX_SIZE, row - row % self.BOX_SIZE + self.BOX_SIZE):
            for j in range(col - col % self.BOX_SIZE, col - col % self.BOX_SIZE + self.BOX_SIZE):
                box.append(self.grid[i][j])
        return box


    def is_safe(self, row, col, num):
        for i in range(self.GRID_SIZE):
            if self.grid[row][i] == num or self.grid[i][col] == num:
                return False
        row_start = row - row % self.BOX_SIZE
        col_start = col - col % self.BOX_SIZE
        for i in range(self.BOX_SIZE):
            for j in range(self.BOX_SIZE):
                if self.grid[i + row_start][j + col_start] == num:
                    return False
        return True

    def solve(self):
        for i in range(self.GRID_SIZE):
            for j in range(self.GRID_SIZE):
                if self.grid[i][j] == 0:
                    for num in range(1, 10):
                        if self.is_safe(i, j, num):
                            self.grid[i][j] = num
                            if self.solve():
                                return True
                            self.grid[i][j] = 0
                    return False
        return True

    def fill_candidates(self):
        self.solve()