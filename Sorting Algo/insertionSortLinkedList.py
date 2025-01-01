import random
number = []
n =5
def intialize():
    global number
    i =0
    while i<n:
        x = random.randint(1,10)
        if x not in number:
            number.append(x)
            i+=1

def insertionSort():
    global number
    for i in range(1,n):
        key = number[i]
        j = i-1
        while j>=0 and number[j]>key:
            number[j+1] = number[j]
            j-=1
        number[j+1] = key

intialize()
print(number)
insertionSort()
print(number)