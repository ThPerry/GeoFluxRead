void Get_Autorun(Dat_Info &D, std::ifstream& inFile)
{
	std::string line;

	std::getline(inFile, line);
	if (line == "AUTORUN: YES")
		D.AUTORUN = 1;
	else
		D.AUTORUN = 0;

	std::getline(inFile, line);
	if (line == "POS3D: YES")
		D.POS3D = 1;
	else
		D.POS3D = 0;
}
void Get_General_Data(Dat_Info &D, std::ifstream& inFile)
{
	std::string line;

	std::getline(inFile, line);

	D.PROBLEM_TYPE = line;

	std::getline(inFile, line);

	D.ANALYSIS_TYPE = line;

	for(int skip = 0;skip<4;skip++)
		std::getline(inFile, line);

	std::istringstream iss(line);

	iss >> D.NPOIN >> D.NELEM >> D.NMATS >> D.NDIME >> D.NNOMAX >> D.USEGRA >> D.NELINT >> D.GRAVITY;
}
void Get_General_Solution_Param(Dat_Info &D, std::ifstream& inFile)
{
	std::string line;

	for (int skip = 0; skip<3; skip++)
		std::getline(inFile, line);

	std::istringstream iss1(line);
	
	iss1 >> D.Sol_Params.Threads;

	for (int skip = 0; skip<4; skip++)
		std::getline(inFile, line);

	std::istringstream iss2(line);
	iss2 >> D.Sol_Params.TINT >> D.Sol_Params.DTOL >> D.Sol_Params.EPS;

	for (int skip = 0; skip<4; skip++)
		std::getline(inFile, line);

	std::istringstream iss3(line);
	iss3 >> D.Sol_Params.NLES >> D.Sol_Params.MAXIT_NL >> D.Sol_Params.ITOL;

	for (int skip = 0; skip<4; skip++)
		std::getline(inFile, line);

	std::istringstream iss4(line);
	iss4 >> D.Sol_Params.LEQS >> D.Sol_Params.MAXIT_LE >> D.Sol_Params.CGTOL;

	for (int skip = 0; skip<4; skip++)
		std::getline(inFile, line);

	std::istringstream iss5(line);
	iss5 >> D.Sol_Params.STIN >> D.Sol_Params.FTOL >> D.Sol_Params.STOL >> D.Sol_Params.LTOL;

}
void Get_Steps_Def(Dat_Info &D, std::ifstream& inFile)
{
	std::string line;

	for (int skip = 0; skip<3; skip++)
		std::getline(inFile, line);

	std::istringstream iss(line);

	iss >> D.NUMSTEPS;

	D.Step.resize(D.NUMSTEPS);

	for (int skip = 0; skip<3; skip++)
		std::getline(inFile, line);

	for (int i = 0; i < D.NUMSTEPS; i++)
	{
		std::getline(inFile, line);

		std::istringstream iss(line);

		iss >> D.Step[i].T_ini >> D.Step[i].T_fin >> D.Step[i].D_ini >> D.Step[i].D_min >> D.Step[i].D_max >> D.Step[i].D_freq;
	}

}
void Get_Output_Def(Dat_Info &D, std::ifstream& inFile)
{
	std::string line;

	for (int skip = 0; skip<3; skip++)
		std::getline(inFile, line);

	std::istringstream iss(line);
	iss >> D.Out_Def.IMPPPR >> D.Out_Def.IMPDIS >> D.Out_Def.IMPTTR >> D.Out_Def.IMPTEN >> D.Out_Def.IMPVEL >> D.Out_Def.NUMCONTR;
}
void Get_Time_Functs(Dat_Info &D, std::ifstream& inFile)
{
	std::string line;

	for (int skip = 0; skip<3; skip++)
		std::getline(inFile, line);

	std::istringstream iss(line);

	iss >> D.NFUNCT;

	D.Time_funct.resize(D.NFUNCT);

	for (int skip = 0; skip<3; skip++)
		std::getline(inFile, line);

	for (int i = 0; i < D.NFUNCT; i++)
	{
		std::getline(inFile, line);

		std::istringstream iss(line);

		iss >> D.Time_funct[i].i >> D.Time_funct[i].N_points >> D.Time_funct[i].Description;

		D.Time_funct[i].p.resize(D.Time_funct[i].N_points);
	}

	for (int skip = 0; skip<4; skip++)
		std::getline(inFile, line);

	for (int i = 0; i < D.NFUNCT; i++)
		for (int j = 0; j < D.Time_funct[i].N_points;j++)
		{
			std::getline(inFile, line);
			std::istringstream iss(line);

			iss >> D.Time_funct[i].p[j].time >> D.Time_funct[i].p[j].value;
		}
}
void Load_Dat(Dat_Info &D, std::string Address)
{
	std::ifstream File;
	File.open(Address);

	std::clock_t start = std::clock();
	double duration;

	if (!File)
	{
		printf("Not able to read the file \"%s\"\n", Address.c_str());
		system("pause");
		exit(1);
	}

	std::cout << ">>> loading .dat";

	Get_Autorun(D, File);

	std::string line;

	while (std::getline(File, line) && line != "%END_DAT")
	{
		if (line == "%GENERAL_DATA")
		{
			Get_General_Data(D, File);
		}
		else if (line == "%SOLUTION_PARAMETERS")
		{
			Get_General_Solution_Param(D, File);
		}
		else if (line == "%STEPS_DEFINITION")
		{
			Get_Steps_Def(D, File);
		}
		else if (line == "%OUTPUT_DEFINITION")
		{
			Get_Output_Def(D, File);
		}
		else if (line == "%TIME_FUNCTIONS")
		{
			Get_Time_Functs(D, File);
		}
			
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "\r>>> loading .dat\t\tElapsed Time: " << duration << "s\n";

	File.close();
}