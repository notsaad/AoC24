file_name = "input.txt"

board = []

with open(file_name, 'r') as f:
    for line in f:
        board.append(list(line.strip()))

goal = "XMAS"
ans = [0]

def check(r, c, i, direction):
    if (
        r < 0 or r == len(board) or
        c < 0 or c == len(board[0]) or
        board[r][c] != goal[i]
    ):
        return

    if (i == 3 and board[r][c] == "S"):
        ans[0] += 1
        return

    # compass directions
    if direction == "left":
        check(r, c-1, i+1, direction)
    if direction == "right":
        check(r, c+1, i+1, direction)
    if direction == "up":
        check(r+1, c, i+1, direction)
    if direction == "down":
        check(r-1, c, i+1, direction)

    # diagonal directions
    if direction == "up_left":
        check(r+1, c-1, i+1, direction)
    if direction == "up_right":
        check(r+1, c+1, i+1, direction)
    if direction == "down_left":
        check(r-1, c-1, i+1, direction)
    if direction == "down_right":
        check(r-1, c+1, i+1, direction)


for r in range(len(board)):
    for c in range(len(board[0])):
        if board[r][c] == "X":
            check(r, c, 0, "left")
            check(r, c, 0, "right")
            check(r, c, 0, "up")
            check(r, c, 0, "down")

            check(r, c, 0, "up_left")
            check(r, c, 0, "up_right")
            check(r, c, 0, "down_left")
            check(r, c, 0, "down_right")

print(ans[0])