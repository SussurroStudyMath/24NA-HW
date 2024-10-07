run: ProblemB ProblemC ProblemD ProblemE ProblemF
	./ProblemB
	./ProblemC
	./ProblemD
	./ProblemE
	./ProblemF
	del *.o *.exe

ProblemB: ProblemB.o
	g++ -o ProblemB ProblemB.o

ProblemB.o: ProblemB.cpp
	g++ -c ProblemB.cpp

ProblemC: ProblemC.o
	g++ -o ProblemC ProblemC.o

ProblemC.o: ProblemC.cpp
	g++ -c ProblemC.cpp

ProblemD: ProblemD.o
	g++ -o ProblemD ProblemD.o

ProblemD.o: ProblemD.cpp
	g++ -c ProblemD.cpp

ProblemE: ProblemE.o
	g++ -o ProblemE ProblemE.o

ProblemE.o: ProblemE.cpp
	g++ -c ProblemE.cpp

ProblemF: ProblemF.o
	g++ -o ProblemF ProblemF.o

ProblemF.o: ProblemF.cpp
	g++ -c ProblemF.cpp

report: report.pdf

report.pdf: report.tex
	pdflatex report.tex
	del *.bib *.aux *.log *.xml

