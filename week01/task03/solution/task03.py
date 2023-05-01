a_len = int(input())
a = input().split(" ")
ret = ""

for item in a:
    item = int(item)
    if item%2 or item%3:
        if item%2 and item%3:
            continue
        else:
            print(item)
            '''
            if len(ret) != 0:
                ret += " "
            ret += f"{item}"
            '''

#print(ret)