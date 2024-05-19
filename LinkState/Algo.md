1. START
2. Select a root node
3. Add root node R to visited node list N
4. for all nodes v
<br>
if v adjacent to R then
<br>
D(v) = c(R,v)
<br>
else
<br>
D(v) = infinity
<br>

5. While all nodes are not in N
<br>
find w not in N such that D(w) is a minimum.
<br>
Add w to N
<br>
Update D(v) for all v adjacent to w and not in N:
<br>
D(v) = min(D(v) , D(w) + c(w,v))
<br>
End while
<br>
6. END