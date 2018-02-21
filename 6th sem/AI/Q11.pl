conc([],L3,L3).
conc([H|T],L2,[H|L]) :- conc(T,L2,L). 

go :-   write('Enter first List : '),
	read(L1),nl,
	write('Enter second List : '),
	read(L2),nl,
	conc(L1,L2,L3), write(L3).
	
