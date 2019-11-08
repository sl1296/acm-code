
with open('kotlin.in', 'r') as f:
    h, w, n = map(int, f.readline().split())

with open('kotlin.out', 'w') as f:
    flag = False
    g = [['.' for j in range(w)] for i in range(h)]
    for h1 in range(1, (h+1)//2+1):
        if flag: break
        for w1 in range(1, (w+1)//2+1):
            if h1*w1==n:
                for i in range(1,h1):
                    g[i*2-1] = ['#' for j in range(w)]
                for j in range(1,w1):
                    for i in range(h):
                        g[i][j*2-1] = '#'
                flag = True
                break
    if flag:
        for i in range(h):
            print(''.join(g[i]), file=f)
    else:
        print('Impossible', file=f)

