import sys
sys.setrecursionlimit(1002)
def rec(n):
    if n==0:
        return 0
    elif n==1:
        return 1
    else:
        return 9*rec(n-1) + 10**(n-1)

if __name__ == '__main__':
    while True:
        try:
            n = int(input())
            print(rec(n))
        except:
            break