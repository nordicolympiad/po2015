r = raw_input
R,C = map(int, r().split())
m = lambda r,c: r >= 0 and r < R and c >= 0 and c < C
g = [r() for l in range(R)]
dr = [0,1,0,-1]
dc = [1,0,-1,0]
n = lambda r,c,d: (r,c) if not m(r,c) or m(r+dr[d],c+dc[d]) and g[r+dr[d]][c+dc[d]] == '#' else n(r+dr[d],c+dc[d],d)
q = [n(0,0,0)]
t = {q[0]:0}
while q:
    v = q.pop(0)
    if v[1] == C:
        print t[v]
        break
    for k in range(4):
        u = n(v[0],v[1],k)
        if not u in t:
            q.append(u)
            t[u] = t[v] + 1
