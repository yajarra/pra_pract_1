bin/testListArray: testListArray.cpp ListArray.h List.h
		mkdir -p bin
		g++ -o bin/testListArray testListArray.cpp
bin/testNode: testNode.cpp Node.h
		mkdir -p bin
		g++ -o bin/testNode testNode.cpp
bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp
Point2D.o: Point2D.cpp Point2D.h
	g++ -c Point2D.cpp
bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o
Shape.o: Shape.cpp Shape.h
	g++ -c Shape.cpp
bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o
Rectangle.o: Rectangle.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Rectangle.cpp
bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -c testRectangle.cpp
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o
bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	g++ -c testSquare.cpp
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Shape.o Point2D.o
clean:
		rm -r *.o *.gch *.pch bin
