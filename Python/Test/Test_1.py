num=int(input("Input number."))
if num in range(0, 10, 2):
    print(f"{num}")
elif num not in range(0, 10, 2):
    i=1
    while i<10:
        print(i)
        i=i+1