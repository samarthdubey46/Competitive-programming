def solve(n,i):
    temp = i+1
    if(n == 1):
        return i;
    if(n % 2 == 0):
        return solve(n/2,temp);
    else:
        return solve(n+1,temp);

n = input()
n = int(n,2)
res = 0
while(n != 1):
    print(n)
    if(n % 2 == 0):
        n = n/2;
    else:
        n = n+1;
    res = res+1;
print(res)
