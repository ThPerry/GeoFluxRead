void Get_Node_Var_Hydraulic_Pressure(std::ifstream& inFile, std::ofstream& OutFile)
{
	int NNVHP, label, NNode, Funct, Type, RL, DHP_RL, GRAD_DHP;

	OutFile << "\t %NODES_VARIABLE_HYDRAULIC_PRESSURE" << std::endl;

	std::string line;
	Skip_inFile_Lines(inFile, 2);
	std::getline(inFile, line);
	std::istringstream iss(line);
	iss >> NNVHP;
	Skip_inFile_Lines(inFile, 3);

	OutFile << "\t\t  LABEL     NODES     FUNCT  TYPE(1:IN, 2 : AB)   RL      DHP_RL    GRAD_DHP" << std::endl;
	OutFile << "\t\t---------+---------+---------+---------+-----------+-----------+-----------+" << std::endl;

	for (int i = 0; i < NNVHP; i++)
	{
		std::getline(inFile, line);
		std::istringstream iss(line);
		iss >> label >> NNode;
		iss >> Funct >> Type >> RL >> DHP_RL >> GRAD_DHP;

		OutFile << "\t\t" << std::setfill(' ') << std::setw(10) << label;
		OutFile << std::setfill(' ') << std::setw(10) << NNode;
		OutFile << std::setfill(' ') << std::setw(10) << Funct;
		OutFile << std::setfill(' ') << std::setw(10) << Type;
		OutFile << std::setfill(' ') << std::setw(10) << RL;
		OutFile << std::setfill(' ') << std::setw(10) << DHP_RL;
		OutFile << std::setfill(' ') << std::setw(10) << GRAD_DHP << std::endl;

		//Print_Progress(i, NNVHP, "Loading .bco NVHP");
	}
}

void Get_Node_Fixed_Displacements(std::ifstream& inFile, std::ofstream& OutFile)
{
	int Nnode=0,NNFD, Fixed_x, Fixed_y, Fixed_z;
	bool Is3d;
	std::string line;

	OutFile << "\t %NODES_FIXED_DISPLACEMENT" << std::endl;

	Skip_inFile_Lines(inFile, 2);
	std::getline(inFile, line);
	std::istringstream iss(line);
	iss >> NNFD;

	for (int skip = 0; skip < 3; skip++)
		std::getline(inFile, line);
	
	if (line == "---------+---------+---------+")
		Is3d = 0;
	else
		Is3d = 1;

	if (Is3d == 0)
	{
		OutFile << "\t\t   Node(i)   Id(i,1)   Id(i,2)" << std::endl;
		OutFile << "\t\t---------+---------+---------+" << std::endl;
	}
	else
	{
		OutFile << "\t\t   Node(i)   Id(i,1)   Id(i,2)   Id(i,3)" << std::endl;
		OutFile << "\t\t---------+---------+---------+---------+" << std::endl;
	}
	

	for (int i = 0; i < NNFD; i++)
	{
		std::getline(inFile, line);
		std::istringstream iss(line);
		iss >> Nnode;

		if (Is3d == 0)
		{
			iss >> Fixed_x >> Fixed_y;
			OutFile << "\t\t" << std::setfill(' ') << std::setw(10) << Nnode;
			OutFile << std::setfill(' ') << std::setw(10) << Fixed_x;
			OutFile << std::setfill(' ') << std::setw(10) << Fixed_y << std::endl;
		}
		else
		{
			iss >> Fixed_x >> Fixed_y >> Fixed_z;
			OutFile << "\t\t" << std::setfill(' ') << std::setw(10) << Nnode;
			OutFile << std::setfill(' ') << std::setw(10) << Fixed_x;
			OutFile << std::setfill(' ') << std::setw(10) << Fixed_y;
			OutFile << std::setfill(' ') << std::setw(10) << Fixed_z << std::endl;
		}

		//Print_Progress(i, NNFD, "Loading .bco NFD");
	}
}

void Get_Node_Variable_Displacements(std::ifstream& inFile, std::ofstream& OutFile)
{
	int Nnode = 0, NNVD, Funct_x, Funct_y, Funct_z, type;
	bool Is3d;
	std::string line;

	OutFile << "\t %NODES_VARIABLE_DISPLACEMENT" << std::endl;

	Skip_inFile_Lines(inFile, 2);
	std::getline(inFile, line);
	std::istringstream iss(line);
	iss >> NNVD;
	for (int skip = 0; skip < 3; skip++)
		std::getline(inFile, line);

	if (line == "---------+---------+---------+---------+")
		Is3d = 0;
	else
		Is3d = 1;

	if (Is3d == 0)
	{
		OutFile << "\t\t     NODES  Funct_ux  Funct_uy      TYPE(1:INC,2:ABS)" << std::endl;
		OutFile << "\t\t---------+---------+---------+---------+" << std::endl;
	}
	else
	{
		OutFile << "\t\t     NODES  Funct_ux  Funct_uy  Funct_uz      TYPE(1:INC,2:ABS)" << std::endl;
		OutFile << "\t\t---------+---------+---------+---------+---------+" << std::endl;
	}

	for (int i = 0; i < NNVD; i++)
	{
		std::getline(inFile, line);
		std::istringstream iss(line);
		iss >> Nnode;

		if (Is3d == 0)
		{
			iss >> Funct_x >> Funct_y >> type;
			OutFile << "\t\t" << std::setfill(' ') << std::setw(10) << Nnode;
			OutFile << std::setfill(' ') << std::setw(10) << Funct_x;
			OutFile << std::setfill(' ') << std::setw(10) << Funct_y;
			OutFile << std::setfill(' ') << std::setw(10) << type << std::endl;
		}
		else
		{
			iss >> Funct_x >> Funct_y >> Funct_z >> type;
			OutFile << "\t\t" << std::setfill(' ') << std::setw(10) << Nnode;
			OutFile << std::setfill(' ') << std::setw(10) << Funct_x;
			OutFile << std::setfill(' ') << std::setw(10) << Funct_y;
			OutFile << std::setfill(' ') << std::setw(10) << Funct_z;
			OutFile << std::setfill(' ') << std::setw(10) << type << std::endl;
		}

		//Print_Progress(i, NNVD, "Loading .bco NVD");
	}
}
void Load_bco(std::string AddressIn, std::string AddressOut)
{
	std::ifstream inFile;
	inFile.open(AddressIn);

	if (!inFile)
	{
		printf("Not able to read the file \"%s\"\n", AddressIn.c_str());
		system("pause");
		exit(1);
	}

	std::ofstream OutFile;
	OutFile.open(AddressOut);

	OutFile << "# ==================================================================================================================================\n";
	OutFile << "# bco_Info\n";

	std::string line;
	while (std::getline(inFile, line))
	{
		if (line == "%NODES_VARIABLE_HYDRAULIC_PRESSURE")
			Get_Node_Var_Hydraulic_Pressure(inFile, OutFile);
		if (line == "%NODES_FIXED_DISPLACEMENT")
			Get_Node_Fixed_Displacements(inFile, OutFile);
		if (line == "%NODES_VARIABLE_DISPLACEMENT")
			Get_Node_Variable_Displacements(inFile, OutFile);
	}
	Print_Progress(1, 1, "Loading .bco");
}