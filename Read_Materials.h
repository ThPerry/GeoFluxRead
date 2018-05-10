void Get_Material(Material &M, std::ifstream& inFile)
{
	int n;

	std::string line;

	std::getline(inFile, line);
	std::getline(inFile, line);

	std::istringstream iss(line);

	iss >> n >> M.Name;

	Skip_inFile_Lines(inFile, 3);

	std::getline(inFile, line);
	std::istringstream iss2(line);
	for (int j = 0; j < 10; j++)
		iss2 >> M.Hydraulic_Prop[j];

	Skip_inFile_Lines(inFile, 3);

	std::getline(inFile, line);
	std::istringstream iss3(line);
	for (int j = 0; j < 10; j++)
		iss3 >> M.Mechanical_Prop[j];

	Skip_inFile_Lines(inFile, 2);

	std::getline(inFile, line);
	std::istringstream iss4(line);
	for (int j = 10; j < 20; j++)
		iss4 >> M.Mechanical_Prop[j];

	Skip_inFile_Lines(inFile, 3);

	std::getline(inFile, line);
	std::istringstream iss5(line);
	for (int j = 0; j < 10; j++)
		iss5 >> M.Thermal_Prop[j];
}
void Load_Materials(std::vector<Material> &M, std::string Address) 
{
	std::ifstream File;
	File.open(Address);

	if (!File)
	{
		printf("Not able to read the file \"%s\"", Address.c_str());
		exit(1);
	}

	std::string line;

	while (std::getline(File, line) && line != "%MATERIALS_DATA(NMATS)");

	for (int i = 0; i < (int)M.size(); i++)
	{
		Get_Material(M[i], File);
		Print_Progress(i, M.size(), "Loading .prp");
	}
	Print_Progress(1, 1, "Loading .prp");
}