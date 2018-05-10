void Get_Node_Coordinates(std::ifstream& inFile, std::vector<Node> &N)
{
	int i = 0;
	std::string line;


	std::getline(inFile, line);
	/*
	while (std::getline(inFile, line) && line != "End Coordinates")
	{
		std::istringstream iss(line);

		if (iss >> N[i].n >> N[i].Coord.x >> N[i].Coord.y >> N[i].Coord.z)

		Print_Progress(i, N.size(), "Loading .msh Node");
		i++;
	}
	*/
	
	/*
	for (int i = 0; i < N.size(); i++)
		inFile >> N[i].n >> N[i].Coord.x >> N[i].Coord.y >> N[i].Coord.z;
	*/
	
}

int Get_Elements(std::ifstream& inFile, std::vector<Element> &E,int pos, bool IsInterface)
{
	char a;
	int Params[4], n;

	std::string line;
	std::getline(inFile, line);

	std::istringstream iss(line);

	iss >> a >> Params[0] >> Params[1] >> Params[2] >> Params[3];

	E[pos].Node_Numbers.resize(Params[1]);

	std::getline(inFile, line);
	std::getline(inFile, line);

	if(IsInterface == false)
		while (std::getline(inFile, line) && line != "End Elements")
		{
			E[pos].Node_Numbers.resize(Params[1]);

			E[pos].IsInterface = 0;

			std::istringstream iss(line);

			iss >> E[pos].I_element;

			for (int j = 0; j<Params[1]; j++)
			{
				iss >> n;

				E[pos].Node_Numbers[j] = n;
			}

			iss >> E[pos].Lmat >> E[pos].LcoH >> E[pos].LcoM >> E[pos].LcoT >> E[pos].Ltip >> E[pos].Nnom >> E[pos].Nnof >> E[pos].Ngau;

			//Print_Progress(pos, E.size(), "Loading .msh Elem");
			pos++;
		}
	else 
		while (std::getline(inFile, line) && line != "End Elements")
		{
			E[pos].Node_Numbers.resize(Params[1]);

			E[pos].IsInterface = 1;

			std::istringstream iss(line);

			iss >> E[pos].I_element;

			for (int j = 0; j<Params[1]/2; j++)
			{
				iss >> n;

				E[pos].Node_Numbers[j] = n;
			}

			iss >> E[pos].Lmat >> E[pos].LcoH >> E[pos].LcoM >> E[pos].LcoT >> E[pos].Ltip >> E[pos].Nnom >> E[pos].Nnof >> E[pos].Ngau;

			for (int j = Params[1] / 2; j<Params[1]; j++)
			{
				iss >> n;

				E[pos].Node_Numbers[j] = n;
			}

			//Print_Progress(pos, E.size(), "Loading .msh Elem");
			pos++;
		}
		
	return pos;
}

void Load_Mesh(std::vector<Node> &N, std::vector<Element> &E, std::string Address, Dat_Info D)
{
	std::ifstream File;
	File.open(Address);

	if (!File)
	{
		printf("Not able to read the file \"%s\"\n", Address.c_str());
		system("pause");
		exit(1);
	}

	int pos = 0;

	std::string line;
	
	while (std::getline(File, line))
	{
		if (line == "#     NODE                   X                   Y                   Z")
			Get_Node_Coordinates(File, N);
		
		if (line == "Elements")
		{
			if((int)E.size() < D.NELEM)
				pos = Get_Elements(File, E, pos, false);
			else
				pos = Get_Elements(File, E, pos, true);
		}
	}

	Print_Progress(pos+1, E.size(), "Loading .post.msh");

	File.close();
}