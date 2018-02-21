remove_duplicate([H|T],R1) :- member(H,T), remove_duplicate(T,R1). 
remove_duplicate([H|T],[H|R]) :- remove_duplicate(T,R). 
remove_duplicate([],[]).

go :-   write('Enter the list : '),
	read(L),nl,
	remove_duplicate(L,R), write(R),!.
