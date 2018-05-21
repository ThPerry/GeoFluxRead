void Get_PoreP(std::ifstream& inFile, std::ofstream& OutFile)
{
	int n, Nnode;
	long double PoreP, Hydr_Flow;
	std::string line;
	std::getline(inFile, line);

	inFile >> n;

	OutFile << "%'POREP' 'HYDR_FLOW'" << std::endl;
	OutFile << "\t" << n << std::endl;

	for (int i = 0; i < n; i++)
	{
		inFile >> Nnode >> PoreP >> Hydr_Flow;

		OutFile << "\t" << Nnode << "\t" << PoreP << "\t" << Hydr_Flow << std::endl;
	}
}
void Get_Displ(std::ifstream& inFile, std::ofstream& OutFile)
{
	int n, Nnode;
	long double dx, dy, dz, rx, ry, rz;
	std::string word;

	inFile >> n >> word >> word >> word;

	OutFile << "%'DISPLACEMENT AND REACTIONS'" << std::endl;
	OutFile << "\t" << n << std::endl;

	for (int i = 0; i < n; i++)
	{
		inFile >> Nnode >> dx >> dy >> dz >> rx >> ry >> rz;

		OutFile << "\t" << Nnode << "\t" << dx << "\t" << dy << "\t" << dz
			<< "\t" << rx << "\t" << ry << "\t" << rz << std::endl;
	}
	
}
void Get_Gauss_Data1(std::ifstream& inFile, std::ofstream& OutFile)
{
	int n, Nnode, Ngau;
	long double KPHXX, KPHYY, KPHXY, VELHX, VELHY, SATFL, KFRAC;

	std::string line;
	std::getline(inFile, line);

	inFile >> n;

	OutFile << "%'KPHXX' 'KPHYY' 'KPHXY' 'VELHX' 'VELHY' 'SATFL' 'KFRAC'" << std::endl;
	OutFile << "\t" << n << std::endl;

	for (int i = 0; i < n; i++)
	{
		inFile >> Nnode >> Ngau;

		OutFile << "\t" << Nnode << "\t" << Ngau << std::endl;

		for (int j = 0; j < Ngau; j++)
		{
			inFile >> KPHXX >> KPHYY >> KPHXY >> VELHX >> VELHY >> SATFL >> KFRAC;

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

	inFile >> n;

	OutFile << "%'SEFXX' 'SEFYY' 'SIGXY' 'SEFZZ' 'DEFXX' 'DEFYY' 'DEFXY' 'DEFZZ' 'SIGOC' 'SIGJ2' 'DEFPL' 'SIGYI' 'POROS' 'POREP' 'TEMPE' 'POREC' 'RATIO' 'BIOT' 'STOXX' 'STOYY' 'STOZZ'" << std::endl;
	OutFile << "\t" << n << std::endl;

	for (int i = 0; i < n; i++)
	{
		inFile >> Nnode >> Ngau;

		OutFile << "\t" << Nnode << "\t" << Ngau << std::endl;

		for (int j = 0; j < Ngau; j++)
		{
			inFile >> SEFXX >> SEFYY >> SIGXY >> SEFZZ >> DEFXX >> DEFYY >> DEFXY >> DEFZZ
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

	std::clock_t start = std::clock();
	double duration;

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

	std::cout << ">>> loading .pre. . .";

	OutFile << "%.Pre Info" << std::endl;

	std::string line;

	while (std::getline(inFile, line) && line != "%END")
	{
		if (line == "'POREP' 'HYDR_FLOW'")
		{
			std::cout << "\r>>> loading .pre PoreP. . .";
			Get_PoreP(inFile, OutFile);
		}
		if (line == "%RESULT.CASE.STEP.NODAL.DISPLACEMENT")
		{
			std::cout << "\r>>> loading .pre Displ. . .";
			Get_Displ(inFile, OutFile);
		}
		if (line == "'KPHXX' 'KPHYY' 'KPHXY' 'VELHX' 'VELHY' 'SATFL' 'KFRAC'")
		{
			std::cout << "\r>>> loading .pre Gauss data. . .";
			Get_Gauss_Data1(inFile, OutFile);
		}
		if (line == "'SEFXX' 'SEFYY' 'SIGXY' 'SEFZZ' 'DEFXX' 'DEFYY' 'DEFXY' 'DEFZZ' 'SIGOC' 'SIGJ2' 'DEFPL' 'SIGYI' 'POROS' 'POREP' 'TEMPE' 'POREC' 'RATIO' 'BIOT' 'STOXX' 'STOYY' 'STOZZ'")
			Get_Gauss_Data2(inFile, OutFile);
	}

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "\r>>> loading .pre\t\tElapsed Time: " << duration << "s\n";
}