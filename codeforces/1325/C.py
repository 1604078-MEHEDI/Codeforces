n = int(input())
g = [0]*(n+1)
l = []
for i in range(n-1):
	a,b = map(int,input().split())
	a -= 1
	b -= 1
	g[a] += 1
	g[b] += 1
	l.append([a,b])
cnt = 0
mex = n-2
for a,b in l:
	if g[a] == 1 or g[b] == 1:
		print(cnt)
		cnt += 1
	else:
		print(mex)
		mex -= 1