specs = input().split(" ")
for index, item in enumerate(specs):
    specs[index] = int(item)

numbers = input().split(" ")
for index, item in enumerate(numbers):
    numbers[index] = int(item)

search = {}
for index in range(specs[1]):
    search[int(input())] = []

for index, item in enumerate(numbers):
    for item2 in search:
        if item == item2:
            search[item2].append(index+1)

for item in search:
    if len(search[item]) == 0:
        print("None!")
    else:
        ret = ""
        for index in search[item]:
            if index != len(search[item])-1:
                print(f"{index}")
            else:
                print(f"{index} ", end = '')