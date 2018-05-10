void Get_PoreP(std::ifstream& inFile, std::ofstream& OutFile)
{
	int n, Nnode;
	long double PoreP, Hydr_Flow;
	std::string line;
	std::getline(inFile, line);
	std::getline(inFile, line);
	std::istringstream iss(line);
	iss >> n;

	OutFile << "%'POREP' 'HYDR_FLOW'" << std::endl;
	OutFile << "\t" << n << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::getline(inFile, line);
		std::istringstream iss(line);

		iss >> Nnode >> PoreP >> Hydr_Flow;

		OutFile << "\t" << Nnode << "\t" << PoreP << "\t" << Hydr_Flow << std::endl;

		//Print_Progress(i, n, "Loading .pre PoreP");
	}
}
void Get_Displ(std::ifstream& inFile, std::ofstream& OutFile)
{
	int n, Nnode;
	long double dx, dy, dz, rx, ry, rz;

	std::string line;
	std::getline(inFile, line);
	std::istringstream iss(line);

	iss >> n;

	OutFile << "%'DISPLACEMENT AND REACTIONS'" << std::endl;
	OutFile << "\t" << n << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::getline(inFile, line);
		std::istringstream iss(line);

		iss >> Nnode >> dx >> dy >> dz >> rx >> ry >> rz;

		OutFile << "\t" << Nnode << "\t" << dx << "\t" << dy << "\t" << dz
			<< rx << "\t" << ry << "\t" << rz << std::endl;

		//Print_Progress(i, n, "Loading .pre Displ");
	}
	
}
void Get_Gauss_Data1(std::ifstream& inFile, std::ofstream& OutFile)
{
	int n, Nnode, Ngau;
	long double KPHXX, KPHYY, KPHXY, VELHX, VELHY, SATFL, KFRAC;

	std::string line;
	std::getline(inFile, line);
	std::getline(inFile, line);
	std::istringstream iss(line);

	iss >> n;

	OutFile << "%'KPHXX' 'KPHYY' 'KPHXY' 'VELHX' 'VELHY' 'SATFL' 'KFRAC'" << std::endl;
	OutFile << "\t" << n << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::getline(inFile, line);
		std::istringstream iss(line);

		iss >> Nnode >> Ngau;

		OutFile << "\t" << Nnode << "\t" << Ngau << std::endl;

		for (int j = 0; j < Ngau; j++)
		{
			std::getline(inFile, line);
			std::istringstream iss(line);
			iss >> KPHXX >> KPHYY >> KPHXY >> VELHX >> VELHY >> SATFL >> KFRAC;

			OutFile << "\t" << KPHXX << "\t" << KPHYY << "\t" << KPHXY 
				<< "\t" << VELHX << "\t" << VELHY << "\t" << SATFL << "\t" << KFRAC << std::endl;
		}
	}
}
void Get_Gauss_Data2(std::ifstream& inFile, std::ofstream& OutFile)
{
	int n, Nnode, Ngau;
	long double SEFXX, SEFYY, SIGXY, SEFZZ, 
		DEFXX, DEFYY, DEFXY, DEFZZ, 
		SIGOC, SIGJ2, DEFPL, SIGYI, POROS, POREP, TEMPE,
		POREC, RATIO, BIOT, STOXX, STOYY, STOZZ;

	std::string line;
	std::getline(inFile, line);
	std::getline(inFile, line);
	std::istringstream iss(line);

	iss >> n;

	OutFile << "%'SEFXX' 'SEFYY' 'SIGXY' 'SEFZZ' 'DEFXX' 'DEFYY' 'DEFXY' 'DEFZZ' 'SIGOC' 'SIGJ2' 'DEFPL' 'SIGYI' 'POROS' 'POREP' 'TEMPE' 'POREC' 'RATIO' 'BIOT' 'STOXX' 'STOYY' 'STOZZ'" << std::endl;
	OutFile << "\t" << n << std::endl;

	for (int i = 0; i < n; i++)
	{
		std::getline(inFile, line);
		std::istringstream iss(line);

		iss >> Nnode >> Ngau;

		OutFile << "\t" << Nnode << "\t" << Ngau << std::endl;

		for (int j = 0; j < Ngau; j++)
		{
			std::getline(inFile, line);
			std::istringstream iss(line);
			iss >> SEFXX >> SEFYY >> SIGXY >> SEFZZ >> DEFXX >> DEFYY >> DEFXY >> DEFZZ
				>> SIGOC >> SIGJ2 >> DEFPL >> SIGYI >> POROS >> POREP >> TEMPE >> POREC
				>> RATIO >> BIOT >> STOXX >> STOYY >> STOZZ;

			OutFile << "\t" << SEFXX << "\t" << SEFYY << "\t" << SIGXY << "\t" << SEFZZ << "\t" << DEFXX
				<< "\t" << DEFYY << "\t" << DEFXY << "\t" << DEFZZ << "\t" << SIGOC << "\t" << SIGJ2
				<< "\t" << DEFPL << "\t" << SIGYI << "\t" << POROS << "\t" << POREP << "\t" << TEMPE
				<< "\t" << POREC << "\t" << RATIO << "\t" << BIOT << "\t" << STOXX << "\t" << STOYY
				<< "\t" << STOZZ << std::endl;
		}
	}
}
void Load_Pre(std::string InAddress, std::string OutAddress)
{
	std::ifstream inFile;
	inFile.open(InAddress);
	std::ofstream OutFile;
	OutFile.open(OutAddress);

	if (!inFile)
	{
		printf("Not able to read the file \"%s\"\n", InAddress.c_str());
		system("pause");
		exit(1);
	}
	if (!OutFile)
	{
		printf("Not able to read the file \"%s\"\n", OutAddress.c_str());
		system("pause");
		exit(1);
	}

	OutFile << "%.Pre Info" << std::endl;

	std::string line;

	while (std::getline(inFile, line) && line != "%END")
	{
		if (line == "'POREP' 'HYDR_FLOW'")
			Get_PoreP(inFile, OutFile);
		if (line == "%RESULT.CASE.STEP.NODAL.DISPLACEMENT")
			Get_Displ(inFile, OutFile);
		if (line == "'KPHXX' 'KPHYY' 'KPHXY' 'VELHX' 'VELHY' 'SATFL' 'KFRAC'")
			Get_Gauss_Data1(inFile, OutFile);
		if (line == "'SEFXX' 'SEFYY' 'SIGXY' 'SEFZZ' 'DEFXX' 'DEFYY' 'DEFXY' 'DEFZZ' 'SIGOC' 'SIGJ2' 'DEFPL' 'SIGYI' 'POROS' 'POREP' 'TEMPE' 'POREC' 'RATIO' 'BIOT' 'STOXX' 'STOYY' 'STOZZ'")
			Get_Gauss_Data2(inFile, OutFile);
	}
	Print_Progress(1, 1, "Loading .pre");
}