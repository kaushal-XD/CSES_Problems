# Problem Name: Counting_Rooms
# Language: Python
# Category: Graph_Algorithms
# Date: 2026-07-26

from collections import deque
import sys
 
data = sys.stdin.read().split()
rows = int(data[0])
cols = int(data[1])
mat = data[2:]
q = deque()
 
moves = [(-1,0),(0,1),(1,0),(0,-1)]
check = [[False for _ in range(cols)] for _ in range(rows)]
ans = 0
for i in range(rows):
    for j in range(cols):
        if mat[i][j] == "." and not check[i][j] :
            check[i][j] = True
            ans += 1
            q.append([i,j])
 
            while q :
                x,y = q.popleft()
                for dx,dy in moves :
                    r,c = x+dx , y+dy
                    if 0 <= r < rows and 0 <= c < cols and mat[r][c] == "." and not check[r][c] :
                        q.append([r,c])
                        check[r][c] = True
 
print(ans)
 
 