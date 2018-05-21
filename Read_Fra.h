void Get_Fra_Prop(std::vector<Fracture_Prop> &F, std::ifstream& inFile)
{
	std::string line;
	std::getline(inFile, line);
	int i = 0;

	while (std::getline(inFile, line) && line != "%END")
	{
		std::istringstream iss(line);

		iss >> F[i].Ielem >> F[i].Updiniap >> F[i].Ini_act >> F[i].b0 >> F[i].e0 >> F[i].usecrior >> F[i].strike >> F[i].dip >> F[i].fluidweight >> F[i].fluidvisc;
		i++;
	}
}
void Load_Fra(std::vector<Fracture_Prop> &F, std::string Address)
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

	std::cout << ">>> loading .fra. . .";

	std::string line;

	while (std::getline(File, line))
		if (line == "%INITIAL_FRACTURE_DATA")
			Get_Fra_Prop(F, File);

	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	std::cout << "\r>>> loading .fra\t\tElapsed Time: " << duration << "s\n";

	File.close();
}