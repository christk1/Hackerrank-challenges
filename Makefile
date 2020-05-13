output: $(fn).cpp
	uncrustify -c uncr.cfg --no-backup -f $(fn).cpp -o $(fn).cpp
	g++ -std=c++0x $(fn).cpp -o $(fn)
