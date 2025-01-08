num = [170, 45, 75, 90, 802, 24, 2, 66]
n = len(num)
def countSort(num,n,ex,base):
    con = [0]*base
    op = [0]*n
    for i in range(0,n):
        index = (num[i]//ex)%10
        con[index]+=1

    for i in range(1,base):
        con[i] +=con[i-1]

    for i in range(n-1,-1,-1):
        index = (num[i]//ex)%10
        op[con[index]-1] = num[i]
        con[index]-=1
    print("Output",op)
    for i in range(0,n):
        num[i] = op[i]

print("Print Before Sort",num)
def radixSort(num,n):
    mx = max(num)
    ex =1
    while mx//ex>0:
        countSort(num,n,ex,10)
        ex *=10

radixSort(num,n)
print(num)