#include <fstream>
#include <stdio.h>
#include <vector>
#include <time.h>

#include <iostream>
#include <iomanip>

#include <sstream>
#include <string>

#include "General.h"
#include "Read_Dat.h"
#include "Read_Mesh.h"
#include "Print_Results.h"
#include "Read_Materials.h"
#include "Read_bco.h"
#include "Read_Fra.h"
#include "Read_Pre.h"

int main()
{
	std::string
		name = "DFN_p21_0056",
		//name = "DFN_3D_no_intersection_Flow_X",

		msh = name + ".post.msh",
		dat = name + ".dat",
		prp = name + ".prp",
		bco = name + ".bco",
		fra = name + ".fra",
		pre = name + ".pre",

		out = "Out.txt",
		bco_out = "Out_bco.txt",
		fra_out = "Out_fra.txt",
		pre_out = "Out_pre.txt";

	std::vector<Node> N;
	std::vector<Element> E;
	std::vector<Material> M;
	std::vector<Fracture_Prop> F;
	Dat_Info D;
	
	Print_Header();

	Load_Dat(D, dat);

	N.resize(D.NPOIN);
	E.resize(D.NELEM + D.NELINT);
	M.resize(D.NMATS);
	F.resize(D.NELINT);

	Load_Mesh(N,E,msh,D);
	Load_Materials(M, prp);
	Load_bco(bco, bco_out);
	Load_Fra(F, fra);
	Load_Pre(pre, pre_out);

	Print_Results(D, N, E, M, out);

	system("pause");

	return 0;
}