import random
n ,m =5,5
def initialize(n):
    num =[]
    i =0
    while i<n:
        x = random.randint(1,20)
        if x  not in num:
            num.append(x)
            i+=1
    return num
def merge(arr,n,m):
    low = 0
    high = n+m-1
    mid = n -1
    i =0
    j = mid+1
    num = []
    while(i<=mid and j<=high):
        if arr[i]>arr[j]:
            num.append(arr[j])
            j+=1
        else:
            num.append(arr[i])
            i+=1
    for k in range(i,mid+1):
        num.append(arr[k])
    for k in range(j,high+1):
        num.append(arr[k])
    return num


arr = initialize(n)
brr = initialize(m)
arr.sort()
brr.sort()
print(arr,brr,sep="\n")
arr.extend(brr)
print(arr)
print(merge(arr,n,m))