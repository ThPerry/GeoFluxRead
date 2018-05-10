struct Node {
	struct coordinates {
		long double x, y, z;
	};

	int n;
	
	coordinates Coord;
};

struct Element {
	bool IsInterface;
	int I_element, Lmat, LcoH, LcoM, LcoT, Ltip, Nnom, Nnof, Ngau;
	std::vector<int> Node_Numbers;
};

struct Dat_Info
{
	struct Steps {
		double T_ini, T_fin, D_ini, D_min, D_max, D_freq;
	};

	struct Time_Functions {
		struct points {
			double time, value;
		};

		int i, N_points;
		std::string Description;
		std::vector<points> p;
	};

	struct Solution_Params {
		int Threads, TINT, NLES, LEQS, STIN;
		double DTOL, EPS, MAXIT_NL, ITOL, MAXIT_LE, CGTOL, FTOL, STOL, LTOL;
	};

	struct Output_Definition {
		int IMPPPR, IMPDIS, IMPTTR, IMPTEN, IMPVEL, NUMCONTR;
	};

	bool AUTORUN, POS3D;
	int NPOIN, NELEM, NMATS, NDIME, NNOMAX, USEGRA, NELINT, GRAVITY, NUMSTEPS,NFUNCT;
	Solution_Params Sol_Params;
	Output_Definition Out_Def;

	std::string PROBLEM_TYPE, ANALYSIS_TYPE;
	std::vector<Steps> Step;
	std::vector<Time_Functions> Time_funct;
};

struct Material {
	std::string Name;
	double Hydraulic_Prop[10], Mechanical_Prop[20], Thermal_Prop[10];
};

struct Fracture_Prop {
	int Ielem;
	bool Ini_act;
	double Updiniap, b0, e0, usecrior, strike, dip, fluidweight, fluidvisc;
};

void Print_Progress(int Current, int End, std::string Title)
{
	float Percent = (float)100 * Current / End;
	char Bar[] = "[                    ]";

	for (int i = 1; 5 * i <= Percent; i++)
		Bar[i] = (char)254u;

	printf("\r>>> %s \t%s %.0f %% ", Title.c_str(), Bar, Percent);

	if (Current >= End)
		printf("\r>>> %s \t%s %.0f %% Complete!\n", Title.c_str(), Bar, Percent);
}

void Print_Header()
{
	std::cout << "===============================================================================" << std::endl;
	std::cout << "GEOFLUX3D to GEMA Conversor" << std::endl;
	std::cout << "Author: Multiphysics Modeling and Simulation Group" << std::endl;
	std::cout << "TECGRAF / PUC-RIO" << std::endl;
	std::cout << "===============================================================================" << std::endl;
	std::cout << std::endl;
}
void Skip_inFile_Lines(std::ifstream& inFile, int n)
{
	std::string line;
	for (int skip = 0; skip < n; skip++)
		std::getline(inFile, line);
}