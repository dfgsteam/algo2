a = int(input())
counter = 0
while a > 0:
    counter += a%2
    a = int(a/2)
print(counter)