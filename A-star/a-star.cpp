/*
Improve upon Dijsktra via a* which uses an additional heuristic to check if searching right direction.
Heuristic used here is line-of-sight to end node. Global goal will be combination of local distance
and line-of-sight distance. Local goal will be distance only. Priority queue tracks global goal.
Line-of-sight is measured by edge weight to following node added with distance at current. 
Next node condition/update weight condition done with local nodes.
Ideally difference b/w local/global goals SHOULD be zero, indicating destination. Larger the difference,
the longer the path to destination really is, as future edge weights distort. After updating each node,
check global goals in queue, pop off front, then continue.
*/

