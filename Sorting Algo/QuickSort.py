num = [10,15,7,3,50]
n = 5
def quicksort(num,low,high):
   if(low<high):
      p = partitiond(num,low,high)
      quicksort(num,low,p-1)
      quicksort(num,p+1,high)

def partitiond(num,low,high):
   pivot = num[low]
   i = low
   j = high
   while i<j:
      
      while num[i] < pivot:
         i+=1
      while num[j]>pivot:
         j-=1
      if(i<j):
         num[i],num[j] = num[j],num[i]
   num[low],num[j] = num[j],num[low]
   return j

print(num)
quicksort(num,low=0,high=n-1)
print(num)
