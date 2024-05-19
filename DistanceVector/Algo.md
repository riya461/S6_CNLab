1. Start 
2. Each node prepares it Distance Vector Table using local knowledge 
( non adjacent marked as infinity )
3. Each node exchanges it's Distance Vector Table with it's neighbours
4. For each value in received Distance Vector Table from node B: `d(A,C) = min(d(A,B)+d(B,C),d(A,C))`
5. If d(A,C) changes, send the new Distance Vector Table to neighbouring
nodes.
6. End
