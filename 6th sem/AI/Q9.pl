% Consider a cyclic directed graph [edge (p, q), edge (q, r), edge (q, r), edge (q, s), edge (s,t)] where
% edge (A,B) is a predicate indicating directed edge in a graph from a node A to a node B. Write a
% program to check whether there is a route from one node to another node.

edge(p,q).	% fact
edge(q,r).	% fact
edge(q,s).	% fact
edge(s,t).	% fact

path(P,P) :- !.				% we got to destination so don't backtrack
path(P,Q) :- edge(P,T), path(T,Q).	% check if there is edge to some T from source and if dest can be reached from T

go :-   write('Enter source : '),
	read(S),nl,										% reading source
	write('Enter Destination : '),
	read(D),nl,										% reading destination
	path(S,D), write('yes there exist a path'); write('there does not exist any path').
