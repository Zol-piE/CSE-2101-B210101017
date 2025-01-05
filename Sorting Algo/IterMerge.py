import random 
def initialize(n):
    num =[]
    i =0
    while i<n:
        x = random.randint(1,20)
        if x  not in num:
            num.append(x)
            i+=1
    return num
arr = initialize(8)
print(arr)
def merge(arr,low,mid,high):
    i = low
    j = mid+1
    num =[]
    while i<=mid and j<=high:
        if(arr[i]>arr[j]):
            num.append(arr[j])
            j+=1
        else:
            num.append(arr[i])
            i+=1
    for k in range(i,mid+1):
        num.append(arr[k])
    for k in range(j,high+1):
        num.append(arr[k])
    i =0
    for k in range(low,high+1):
        arr[k] = num[i]
        i+=1
    
def mergeSort(arr, n):
    p =2
    while p<n:
        i =0
        while i+p-1<n:
            l = i
            h = i+p-1
            mid = (l+h)//2
            merge(arr,l,mid,h)
            i+=p
        p *=2
        
    if(p//2<n):
        merge(arr,0,p//2-1,n-1)



mergeSort(arr,len(arr))
print(arr)
