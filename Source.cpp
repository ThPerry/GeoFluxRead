#include <fstream>
#include <stdio.h>
#include <vector>
#include <time.h>

#include <iostream>
#include <iomanip>

#include <sstream>
#include <string>

#include <cstdio>
#include <ctime>

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
		inFolder = "C:\\Users\\thiago\\source\\repos\\Conversor\\Conversor\\MODEL_2",
		outFolder = "C:\\Users\\thiago\\source\\repos\\Conversor\\Conversor\\MODEL_2",

		//name = "DFN_p21_0056",
		name = inFolder + "\\" + "MODEL_2",
		//name = "DFN_3D_no_intersection_Flow_X",

		msh = name + ".post.msh",
		dat = name + ".dat",
		prp = name + ".prp",
		bco = name + ".bco",
		fra = name + ".fra",
		pre = name + ".pre",

		out = outFolder + "\\" + "Out.txt",
		bco_out = outFolder + "\\" + "Out_bco.txt",
		fra_out = outFolder + "\\" + "Out_fra.txt",
		pre_out = outFolder + "\\" + "Out_pre.txt";

	std::vector<Node> N;
	std::vector<Element> E, EI;
	std::vector<Material> M;
	std::vector<Fracture_Prop> F;
	Dat_Info D;
	
	Print_Header();

	Load_Dat(D, dat);

	N.resize(D.NPOIN);
	E.resize(D.NELEM);
	EI.resize(D.NELINT);
	M.resize(D.NMATS);
	F.resize(D.NELINT);

	Load_Mesh(N,E,EI,msh,D);
	Load_Materials(M, prp);
	Load_bco(bco, bco_out);
	Load_Fra(F, fra);
	Load_Pre(pre, pre_out);

	Print_Results(D, N, E, EI, M, out);

	printf("%.8d\n", N[2].n);

	system("pause");

	return 0;
}