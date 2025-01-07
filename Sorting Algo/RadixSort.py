num = [170, 45, 75, 90, 802, 24, 2, 66]
n = len(num)

def countingSort(num, ex, n, base):
    con = [0] * base  # Count array
    op = [0] * n  # Output array

    # Count occurrences of digits
    for i in range(n):
        index = (num[i] // ex) % base
        con[index] += 1

    # Update count array to store positions
    for i in range(1, base):
        con[i] += con[i - 1]

    # Build output array (iterate backwards for stability)
    for i in range(n - 1, -1, -1):
        index = (num[i] // ex) % base
        op[con[index] - 1] = num[i]
        con[index] -= 1

    # Copy sorted elements back to original array
    for i in range(n):
        num[i] = op[i]


def RadixSort(num, n):
    mx = max(num)  # Find the maximum number
    ex = 1  # Start with the least significant digit

    while mx // ex > 0:
        countingSort(num, ex, n, 10)
        ex *= 10


RadixSort(num, n)
print(num)
