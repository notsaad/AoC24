file_name = "input.txt"

board = []

with open(file_name, 'r') as f:
    for line in f:
        board.append(list(line.strip()))

ans = [0]

def check(r, c):
    if (
        (
            board[r+1][c-1] == "M" and board[r-1][c-1] == "M" and
            board[r+1][c+1] == "S" and board[r-1][c+1] == "S"
        ) or (
            board[r+1][c-1] == "S" and board[r-1][c-1] == "S" and
            board[r+1][c+1] == "M" and board[r-1][c+1] == "M"
        ) or (
            board[r+1][c-1] == "M" and board[r-1][c-1] == "S" and
            board[r+1][c+1] == "M" and board[r-1][c+1] == "S"
        ) or (
            board[r+1][c-1] == "S" and board[r-1][c-1] == "M" and
            board[r+1][c+1] == "S" and board[r-1][c+1] == "M"
        )
    ):
        ans[0] += 1


for r in range(1, len(board) -1):
    for c in range(1, len(board[0]) -1):
        if board[r][c] == "A":
            check(r, c)

print(ans[0])