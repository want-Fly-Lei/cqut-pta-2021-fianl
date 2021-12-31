#please use python3
def dp(M, N, list):
    arr = [[0] * N] * M
    arr[0][0] = 1
    for m in range(len(arr)):
        for n in range(len(arr[0])):
            if (m, n) in list:
                arr[m][n] = 0
            elif m != 0 and n == 0:
                arr[m][n] = arr[m - 1][n]
            elif m == 0 and n != 0:
                arr[m][n] = arr[m][n - 1]
            else:
                arr[m][n] = arr[m][n - 1] + arr[m - 1][n]
    return arr[M - 1][N - 1]
n = int( input ( ))
for i in range(n):
    li = input().strip().split()
    li = [int(i) for i in li]
    print(dp(li[0] + 1, li[1] + 1, [(li[2], li[3]), (li[4], li[5])]))
