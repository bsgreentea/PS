str = input()

one = 0
zero = 0

lenOfStr = int(len(str))
for i in range(0, lenOfStr):
    if i is lenOfStr - 1:
        if str[i] is '1':
            one += 1
        else:
            zero += 1
        break

    if str[i] is not str[i + 1]:
        if str[i] is '1':
            one += 1
        else:
            zero += 1

ans = min(one, zero)
print(ans)