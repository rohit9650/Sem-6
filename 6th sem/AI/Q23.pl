merge([H1|T1],[H2|T2],R) :- H1=<H2, merge(T1,[H2|T2],R1), append([H1],R1,R).
merge([H1|T1],[H2|T2],R) :- merge([H1|T1],T2,R1), append([H2],R1,R).
merge([],L2,L2).
merge(L1,[],L1).

go :-   write('Enter the First ordered list : '),
	read(L1),nl,
	write('Enter the Second ordered list : '),
	read(L2),nl,
	merge(L1,L2,R), write(R), !.
