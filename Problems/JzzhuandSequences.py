x,y = map(int,input().split());
n = int(input());
arr = [x,y,y-x,-x,-y,-y+x];
print(arr[(n-1)%6] % 1000000007);


