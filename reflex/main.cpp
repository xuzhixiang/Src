#include <iostream>
#include "test.h"

using namespace std;

int main()
{
	QTest *t =  (QTest *)MS::getClassObjByName("QTest");
	t -> setm_val(5);
	t -> setm_name("xuzhixiang");
	cout << t -> getm_val() << ' ' << t -> getm_name() << endl;
	MS::destroyFactory();	
	return 0;
}

