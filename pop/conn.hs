import Data.List
 
type Vertex = Int
type Edge = (Vertex,Vertex)
type Graph = ([Vertex],[Edge])
 
recur :: Graph -> [Vertex] -> [Vertex]
recur ([],_) _ = []
recur (_,_) [] = []
recur (x,e) (top:stack)
    | [var | var<-x,var==top] == [] = recur (curr, e) stack
    | otherwise = top : recur (curr, e) (adjacent ++ stack)
    where
        adjacent = [var | (var,y)<-e,y==top] ++ [var | (y,var)<-e,y==top]
        curr = [var | var<-x,var/=top]

conn_comp :: Graph -> [[Vertex]]
conn_comp ([],_) = []
conn_comp (top:x,e) 
    | left == [] = [set]
    | otherwise = set : conn_comp (left, e)
    where
        set = dfs (top:x,e) top
        left = (top:x) \\ set

dfs :: Graph -> Vertex -> [Vertex]
dfs (x,e) n
    | [var|var<-x,var==n] == [] = []
    | otherwise = recur (x,e) [n]
 

 
