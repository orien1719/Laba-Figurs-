#include"TObj.h"
#include"Point.h"
#include"Vector.h"
#include"Printer.h"
#include"ComplexNumbs.h"
#include "Line.h"
#include"Square.h"
#include"Circle.h"
#include"Triangle.h"
#include"SetOfShapes.h"
#include"Tetrahedron.h"

int main()
{	
	TSet<int> set;
	TTetrahedron<int> tt;
	TCircle<int> circle(10);
	TLine<int>line;
	set.SetObj(&tt);
	set.SetObj(&circle);
	set.SetObj(&line);
	set.ToPrint();
	set.ToPlot();

	return 0;
}