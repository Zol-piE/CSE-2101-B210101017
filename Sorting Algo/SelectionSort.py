import random

def randomIn(n):
    num = []
    i = 0
    while i<n:
        x = random.randint(1,10)
        if x not in num:
            num.append(x)
            i+=1
    return num

arr = randomIn(5)
print(arr)

def minIndex(arr,low,high):
    m = arr[low]
    mIN  = low
    for i in range(low+1,high):
        if(arr[i]<m):
            m = arr[i]
            mIN = i
    return mIN

def selectionSort(arr=[],n=1):
    for i in range(n):
        m = minIndex(arr,i,n)
        arr[m],arr[i]=arr[i],arr[m]

selectionSort(arr,5)
print(arr)