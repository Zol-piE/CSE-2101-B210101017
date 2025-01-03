import random

# Function to generate random unique integers
def randomIn(n):
    arr = []
    i = 0
    while i < n:
        x = random.randint(1, 10)
        if x not in arr:
            arr.append(x)
            i += 1
    return arr

def partition(arr,low,high):
    pivot = arr[low]
    i = low
    j = high
    while i<j:
        i+=1
        while i<high and arr[i]<=pivot:
            i+=1
        j-=1
        while arr[j]>pivot:
            j-=1

        if(i<j):
            arr[i],arr[j] = arr[j],arr[i]
            
    arr[low],arr[j] = arr[j],arr[low]
    return j
    
def quicksort(arr,low,high):
    if low <high:
        pi = partition(arr,low,high)
        quicksort(arr,low,pi)
        quicksort(arr,pi+1,high)

# Main program
n = 5
arr = randomIn(n)
print("Unsorted array:", arr)

quicksort(arr, 0, n)
print("Sorted array:", arr)
