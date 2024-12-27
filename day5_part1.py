import collections
file_name = "input.txt"

ans = 0
rules = []
first_part = True

with open(file_name, 'r') as f:
    for line in f:
        line = line.strip()

        if "|" not in line and first_part:
            first_part = False
            continue

        if first_part:
            rules.append(tuple(line.split("|")))
        else:
            v = True
            n = line.split(",")
            for a, b in rules:
                if a in n and b in n and n.index(a) > n.index(b):
                    v = False
                    break

            if v:
                ans += int(n[len(n) // 2])

print(ans)
