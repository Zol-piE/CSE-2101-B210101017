import random
n = int(input())
m = int(input())

def initialize(n):
    num = [] 
    i = 0
    while i<n:
        x = random.randint(1,10)
        if(x not in num):
            num.append(x)
            i+=1
    return num

arr = initialize(n)
brr = initialize(m)

def merge(arr,brr,n,m):
    i = j = 0
    num = []
    while(i<n and j<m):
        if(arr[i]>brr[j]):
            num.append(brr[j])
            j+=1
        else:
            num.append(arr[i])
            i+=1
    for k in range(i,n):
        num.append(arr[k])
    for k in range(j,m):
        num.append(brr[k])
    return num
arr.sort()
brr.sort()
crr= merge(arr,brr,n,m)
print(arr,brr,crr,sep="\n")