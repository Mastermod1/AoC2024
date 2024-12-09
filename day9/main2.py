import sys

data = sys.stdin.read()
data = data[0:len(data) - 1]


new_data = []
ind = 0
for i in range(len(data)):
    if (i % 2 == 0):
        new_data.append((data[i], ind))
        ind += 1
    else:
        new_data.append((data[i], -1))

r = len(data) - 1
while (r >= 0):
    l = 1
    while (l < r):
        dl = int(new_data[l][0])
        dr = int(new_data[r][0])
        if (dr <= dl):
            ff = new_data[r][1]
            new_data[r] = (new_data[r][0], -1)
            new_data[l] = (str(dl - dr), -1)
            new_data.insert(l, (str(dr), ff))  # -10 to id
            new_data.insert(l, ("0", -1))
            r += 2
            break
        l += 2
    r -= 2

res = 0
pos = 0
for i in range(len(new_data)):
    length = int(new_data[i][0])
    if new_data[i][1] != -1:
        for k in range(length):
            res += pos * new_data[i][1]
            pos += 1
    else:
        pos += length
print(res)




