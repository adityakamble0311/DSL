def print_board(board):
    for row in board:
        print(" ".join(map(str, row)))


def is_valid(board, num, row, col):
    # Check if the number is not in the same row and column
    if num in board[row] or num in [board[i][col] for i in range(9)]:
        return False

    # Check if the number is not in the 3x3 subgrid
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[start_row + i][start_col + j] == num:
                return False

    return True


def find_empty_location(board):
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                return i, j
    return None, None


def solve_sudoku(board):
    row, col = find_empty_location(board)

    if row is None and col is None:
        # No empty location left, the board is solved
        return True

    for num in range(1, 10):
        if is_valid(board, num, row, col):
            # Try placing the number
            board[row][col] = num

            # Recursively try to solve the remaining board
            if solve_sudoku(board):
                return True

            # If placing the number doesn't lead to a solution, backtrack
            board[row][col] = 0

    # No number from 1 to 9 can be placed at this location, backtrack
    return False


# Example Usage
if __name__ == "__main__":
    sudoku_board = [
        [5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 1, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]
    ]

    print("Sudoku Puzzle:")
    print_board(sudoku_board)

    if solve_sudoku(sudoku_board):
        print("\nSudoku Solution:")
        print_board(sudoku_board)
    else:
        print("\nNo solution exists.")
