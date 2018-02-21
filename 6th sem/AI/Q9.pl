edge(p,q).
edge(q,r).
edge(q,s).
edge(s,t).

path(P,P) :- !.
path(P,Q) :- edge(P,T), path(T,Q).

go :-   write('Enter source : '),
	read(S),nl,
	write('Enter Destination : '),
	read(D),nl,
	path(S,D), write('yes there exist a path'); write('there does not exist any path').
