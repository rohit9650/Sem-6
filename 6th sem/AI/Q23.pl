% program in PROLOG to implement merge (L1, L2, L3) where L1 is first ordered list and L2
% is second ordered list and L3 represents the merged list.

merge([H1|T1],[H2|T2],R) :- H1=<H2, merge(T1,[H2|T2],R1), append([H1],R1,R).	% if head of L1 is less or euqal to head of L2, call merge on tail of L1 
										% append this result with head of L1 and finally put in result R
merge([H1|T1],[H2|T2],R) :- merge([H1|T1],T2,R1), append([H2],R1,R).		% else call merge on tail of L2
										% append this result with head of L2 and finally put in result R
merge([],L2,L2).								% base case if first list is empty; L3 is L2
merge(L1,[],L1).								% base case if first list is empty; L3 is L1

go :-   write('Enter the First ordered list : '),
	read(L1),nl,								% reading first ordered list L1
	write('Enter the Second ordered list : '),
	read(L2),nl,								% reading second ordered list L2
	merge(L1,L2,R), write(R), !.
