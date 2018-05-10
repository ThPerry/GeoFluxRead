void Print_Dat(Dat_Info &D, std::ofstream& outFile)
{
	outFile << "#==================================================================================================================================\n";
	outFile << "# Dat_Info\n";

	outFile << "\tAutorun: " << D.AUTORUN << std::endl;
	outFile << "\tPOS3D: " << D.POS3D << std::endl;

	outFile << "\n\t%General_Data" << std::endl;
	outFile << "\t" << D.PROBLEM_TYPE << std::endl;
	outFile << "\t" << D.ANALYSIS_TYPE << std::endl;
	outFile << "\t\t" << "   NPOIN   NELEM   NMATS   NDIME  NNOMAX  USEGRA  NELINT   GRAVITY" << std::endl;
	outFile << "\t\t" << "-------+-------+-------+-------+-------+-------+-------+---------+   " << std::endl;
	outFile << "\t\t" << std::setfill(' ') << std::setw(8) << D.NPOIN;
	outFile << std::setfill(' ') << std::setw(8) << D.NELEM;
	outFile << std::setfill(' ') << std::setw(8) << D.NMATS;
	outFile << std::setfill(' ') << std::setw(8) << D.NDIME;
	outFile << std::setfill(' ') << std::setw(8) << D.NNOMAX;
	outFile << std::setfill(' ') << std::setw(8) << D.USEGRA;
	outFile << std::setfill(' ') << std::setw(8) << D.NELINT;
	outFile << std::setfill(' ') << std::setw(10) << D.GRAVITY << std::endl;
	
	outFile << "\n\t%Solution_Parameters" << std::endl;
	outFile << "\t\t" << "   THREADS" << std::endl << "\t\t" << "---------+" << std::endl;
	outFile << "\t\t" << std::setfill(' ') << std::setw(10) << D.Sol_Params.Threads << std::endl << std::endl;
	outFile << "\t\t" << "      TINT      DTOL       EPS" << std::endl;
	outFile << "\t\t" << "---------+---------+---------+" << std::endl;
	outFile << "\t\t" << std::setfill(' ') << std::setw(10) << D.Sol_Params.TINT;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.DTOL;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.EPS << std::endl;
	outFile << "\t\t" << "      NLES  MAXIT_NL      ITOL" << std::endl;
	outFile << "\t\t" << "---------+---------+---------+" << std::endl;
	outFile << "\t\t" << std::setfill(' ') << std::setw(10) << D.Sol_Params.NLES;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.MAXIT_NL;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.ITOL << std::endl;
	outFile << "\t\t" << "      LEQS  MAXIT_LE     CGTOL" << std::endl;
	outFile << "\t\t" << "---------+---------+---------+" << std::endl;
	outFile << "\t\t" << std::setfill(' ') << std::setw(10) << D.Sol_Params.LEQS;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.MAXIT_LE;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.CGTOL << std::endl;
	outFile << "\t\t" << "      STIN      FTOL      STOL      LTOL" << std::endl;
	outFile << "\t\t" << "---------+---------+---------+---------+" << std::endl;
	outFile << "\t\t" << std::setfill(' ') << std::setw(10) << D.Sol_Params.STIN;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.FTOL;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.STOL;
	outFile << std::setfill(' ') << std::setw(10) << D.Sol_Params.LTOL << std::endl;


	outFile << "\n\t%Steps_Definition" << std::endl;
	outFile << "\t\t" << "       T_ini       T_fin       D_ini       D_min       D_max      D_freq" << std::endl;
	outFile << "\t\t" << "-----------+-----------+-----------+-----------+-----------+-----------+" << std::endl;
	for (int i = 0; i < (int)D.Step.size(); i++)
	{
		outFile << "\t\t" << std::setfill(' ') << std::setw(12) << D.Step[i].T_ini;
		outFile << std::setfill(' ') << std::setw(12) << D.Step[i].T_fin;
		outFile << std::setfill(' ') << std::setw(12) << D.Step[i].D_ini;
		outFile << std::setfill(' ') << std::setw(12) << D.Step[i].D_min;
		outFile << std::setfill(' ') << std::setw(12) << D.Step[i].D_max;
		outFile << std::setfill(' ') << std::setw(12) << D.Step[i].D_freq << std::endl;
	}

	outFile << "\n\t%Output_Definition" << std::endl;
	outFile << "\t\t" << "    IMPPPR    IMPDIS    IMPTTR    IMPTEN    IMPVEL  NUMCONTR" << std::endl;
	outFile << "\t\t" << "---------+---------+---------+---------+---------+---------+" << std::endl;
	outFile << "\t\t" << std::setfill(' ') << std::setw(10) << D.Out_Def.IMPPPR;
	outFile << std::setfill(' ') << std::setw(10) << D.Out_Def.IMPDIS;
	outFile << std::setfill(' ') << std::setw(10) << D.Out_Def.IMPTTR;
	outFile << std::setfill(' ') << std::setw(10) << D.Out_Def.IMPTEN;
	outFile << std::setfill(' ') << std::setw(10) << D.Out_Def.IMPVEL;
	outFile << std::setfill(' ') << std::setw(10) << D.Out_Def.NUMCONTR << std::endl;

	outFile << "\n\t%STime_Functions" << std::endl;
	outFile << "\t\t" << "         i    points Description" << std::endl;
	outFile << "\t\t" << "---------+---------+-----------+" << std::endl;
	for (int i = 0; i < (int)D.Time_funct.size(); i++)
	{
		outFile << "\t\t" << std::setfill(' ') << std::setw(10) << D.Time_funct[i].i;
		outFile << std::setfill(' ') << std::setw(10) << D.Time_funct[i].N_points;
		outFile << "   " << D.Time_funct[i].Description << std::endl;
	}
	outFile << "\t\t" << " FUNCTIONS POINTS ith" << std::endl;
	outFile << "\t\t" << "   Time(i,j), Value(i,j)" << std::endl;
	outFile << "\t\t" << "-----------+-----------+" << std::endl;
	for (int i = 0; i < (int)D.Time_funct.size(); i++)
		for (int j = 0; j < (int)D.Time_funct[i].p.size(); j++)
		{
			outFile << "\t\t" << std::setfill(' ') << std::setw(10) << D.Time_funct[i].p[j].time;
			outFile << std::setfill(' ') << std::setw(10) << D.Time_funct[i].p[j].value << std::endl;
		}

	outFile << std::endl << std::endl;
}
void Print_Mesh(Dat_Info &D, std::vector<Node> &N, std::vector<Element> &E, std::ofstream& outFile) 
{
	outFile << "#==================================================================================================================================\n";
	outFile << "# Mesh_Info" << std::endl << std::endl;
	
	outFile << "\tNode_Coordinates" << std::endl;
	outFile << "\t#     NODE                   X                   Y                   Z" << std::endl;
	outFile << "\t#--------+-------------------+-------------------+-------------------+" << std::endl;
	for (int i = 0; i < D.NPOIN; i++)
	{
		outFile << "\t" << std::setfill(' ') << std::setw(10) << N[i].n;
		outFile << std::setfill(' ') << std::setw(20) << N[i].Coord.x;
		outFile << std::setfill(' ') << std::setw(20) << N[i].Coord.y;
		outFile << std::setfill(' ') << std::setw(20) << N[i].Coord.z << std::endl;
	}

	outFile << std::endl << std::endl;

	outFile << "\tElements" << std::endl;
	outFile << "\t#  Ielem     Conectivities               Lmat LcoH LcoM LcoT Ltip Nnom Nnof Ngau" << std::endl;
	outFile << "\t#------+-------+-------+-------+-------+----+----+----+----+----+----+----+----+" << std::endl;
	for (int i = 0; i < D.NELEM; i++)
	{
		outFile << "\t" << std::setfill(' ') << std::setw(8) << E[i].I_element;
		for (int j = 0; j < (int)E[i].Node_Numbers.size(); j++)
			outFile << std::setfill(' ') << std::setw(8) << E[i].Node_Numbers[j];
		outFile << std::setfill(' ') << std::setw(5) << E[i].Lmat;
		outFile << std::setfill(' ') << std::setw(5) << E[i].LcoH;
		outFile << std::setfill(' ') << std::setw(5) << E[i].LcoM;
		outFile << std::setfill(' ') << std::setw(5) << E[i].LcoT;
		outFile << std::setfill(' ') << std::setw(5) << E[i].Ltip;
		outFile << std::setfill(' ') << std::setw(5) << E[i].Nnom;
		outFile << std::setfill(' ') << std::setw(5) << E[i].Nnof;
		outFile << std::setfill(' ') << std::setw(5) << E[i].Ngau << std::endl;
	
	}

	outFile << std::endl << std::endl;
}
void Print_Material(std::vector<Material> &M, std::ofstream& outFile)
{
	outFile << "# ==================================================================================================================================\n";
	outFile << "# Prp_Info\n";

	for (int i = 0; i < (int)M.size(); i++)
	{
		outFile << "\t" << M[i].Name << std::endl;

		for (int j = 0; j < 10; j++)
			outFile << "\t\t" << M[i].Hydraulic_Prop[j] << "\t";
		outFile << std::endl;

		for (int j = 0; j < 10; j++)
			outFile << "\t\t" << M[i].Mechanical_Prop[j] << "\t";
		outFile << std::endl;

		for (int j = 10; j < 20; j++)
			outFile << "\t\t" << M[i].Hydraulic_Prop[j] << "\t";
		outFile << std::endl;

		for (int j = 0; j < 10; j++)
			outFile << "\t\t" << M[i].Thermal_Prop[j] << "\t";
		outFile << std::endl;
	}
}
void Print_Results(Dat_Info &D, std::vector<Node> &N, std::vector<Element> &E, std::vector<Material> &M, std::string Address)
{	
	std::ofstream File;
	File.open(Address);
	std::cout << "Printing Data Info on \'" << Address << "\'. . ." << std::endl;
	Print_Dat(D, File);
	std::cout << "Printing Mesh Info on \'" << Address << "\'. . ." << std::endl;
	Print_Mesh(D, N, E, File);
	std::cout << "Printing Material Info on \'" << Address << "\'. . ." << std::endl;
	Print_Material(M, File);

	std::cout << "Complete!" << std::endl;

	File.close();
}