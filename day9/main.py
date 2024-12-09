import sys

data = sys.stdin.read()
data = data[0:len(data) - 1]

last_id = len(data) // 2
first_id = 0

l = 0
r = len(data) - 1
res = 0
pos = 0
ends = []
to_be_used = int(data[r])
while l < r:
    length = int(data[l])
    if l % 2 == 0:
        for i in range(length):
            res += first_id * pos
            pos += 1
        first_id += 1
    else:
        i = 0
        while (i < length):
            if (to_be_used == 0):
                r -= 2
                to_be_used = int(data[r])
                last_id -= 1
            res += last_id * pos
            pos += 1
            i += 1
            to_be_used -= 1
    l += 1
while (to_be_used > 0):
    res += last_id * pos
    pos += 1
    to_be_used -= 1

print(res)
