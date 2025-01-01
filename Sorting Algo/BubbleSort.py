import random
num = list()
n = 10
i =0
while i<n:
    x = random.randint(1,20)
    if(x not in num):
        num.append(x)
        i+=1

print(num)

def bubbleSort(arr=[],n=1):
    for i in range(n-1): #there will n-1 passes if the array size is n
        for j in range(n-i-1):#every time there will be one less comparison
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1] = arr[j+1],arr[j]

bubbleSort(num,n)
print(num)  