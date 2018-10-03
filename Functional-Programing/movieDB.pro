movies([
	%movie(movie name,Director names, Screenplay writer names, film distributor),
	movie("Pulp Fiction",names(quentin,tarantino),	names(quentin,tarantino), miramax),
	movie("Django unchained",names(quentin,tarantino),	names(quentin,tarantino),imax),
	movie("The wolf of wall street",names(martin,scorsese),		names(terence,winter),cinema733),
	movie("Get on Up",names(tate,taylor),names(john-henry,butterworth),miramax),
	movie("Ray",names(taylor,hackford ),names(james,white), imax3D),
	movie("V for vendetta",names(james,mcTeigue ),	names(terence,winter),imax)

]).

fromScrW(_,_,[],[]). %granichno uslovie
fromScrW(S1,S2,
		[movie(Mn,names(D1,D2),names(S1,S2),A)|T],
		[movie(Mn,names(D1,D2))|NewT]):-fromScrW(S1,S2,T,NewT).
fromScrW(S1,S2,[_|T],NewTt):-fromScrW(S1,S2,T,NewTt).

?-movies(L),
	write("enter script-writer first name"), read(S1), nl,
	write("enter script-writer last name"), read(S2), nl,
	%write("enter Screenplay writer names"), read(S1),read(S2), nl,
	fromScrW(S1,S2,L,R),write(R),nl.

