#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <vector> 
#include <cstdlib>
#include <sstream>
#include <time.h>

using namespace std; 

struct content {
	string line;
};

vector <content> conteudo;

string ct = "<xsd:complexType";
string sq = "<xsd:sequence";
string el = "<xsd:element";

string complexTypeName = "";
string xmlnsString = "";
string xmlnsType = "";
string file = "";

static const char alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
int stringLength = sizeof(alphanum) - 1;

vector <content> jsonElements;
vector <content> jsonChild;

int writeFile() {
	printf("The XML file will be created!\n");

	int i = 0;
	int numElemnts = 0;

	string STRING;
	ifstream infile;
	ofstream xmlFile;

	bool xmlns = false;
	bool complex = false;
	bool sequence = false;
	bool element = false;

	vector <content> elementos;

	std::ostringstream sss;
	int time = clock() % 10;
	sss << time;

	xmlFile.open("xmlFile.xml");
	xmlFile << "<?xml version='1.0' encoding='utf-8'?>" << endl;
	
	//infile.open("xsdFile.xsd");
	infile.open(file);

	while (!infile.eof()){
		
		getline(infile, STRING);
		conteudo.push_back(content());
		conteudo[i].line = STRING;
		size_t pos = conteudo[i].line.find(ct);
		size_t posXmlns = conteudo[i].line.find("xmlns:");
		
		if (xmlns) {
			if (complex) {
				if (sequence) {
					size_t posEL = conteudo[i].line.find(el);

					if (posEL != std::string::npos) {

						string strEL = conteudo[i].line.substr(posEL);

						//Name
						size_t firstLimEL = strEL.find("name=");
						string firstEL = strEL.substr(firstLimEL);

						string firtStrEL = firstEL.erase(0, 6);

						size_t endStrEL = firtStrEL.find("\"");
						string endEL = firtStrEL.erase(endStrEL);

						//Type
						size_t firstType = strEL.find("type=");
						string firstELType = strEL.substr(firstType);

						string firtStrType = firstELType.erase(0, 6);

						size_t endStrType = firtStrType.find("\"");
						string endType = firtStrType.erase(endStrType);


						if (endType == "bit:" + complexTypeName) {
							xmlFile << "<" << xmlnsType << ":" << endEL << " " << xmlnsString << ">" << endl;
							int jsonSize = static_cast <int> (jsonElements.size());
							jsonElements.push_back(content());
							jsonElements[jsonSize].line = "{ \n \"" + xmlnsType + ":"+ endEL + "\": {\n";

							int size = static_cast <int> (elementos.size());

							for (int i = 0; i < size; i++)
							{
								xmlFile << elementos[i].line;

								int jsonSize = static_cast <int> (jsonElements.size());
								jsonElements.push_back(content());

								if (i == size - 1) {
									jsonElements[jsonSize].line = jsonChild[i].line + "\n";

								}
								else
									jsonElements[jsonSize].line = jsonChild[i].line + ",\n";


							}
							elementos.clear();
							jsonChild.clear();
							xmlFile << "</" << xmlnsType << ":" << endEL << ">" << endl;

							int jsonSizeT = static_cast <int> (jsonElements.size());
							jsonElements.push_back(content());
							jsonElements[jsonSizeT].line = "} \n} \n";

							xmlFile.close();
							numElemnts = 0;
						}
						else if (endType == "xsd:string") {
							int size = static_cast <int> (elementos.size());
							elementos.push_back(content());

							string myElement = "<" + endEL + ">" + alphanum[(time) % stringLength] + "</" + endEL + "> \n";
							elementos[size].line = myElement;

							int jsonSizeChild = static_cast <int> (jsonChild.size());
							jsonChild.push_back(content());
							jsonChild[jsonSizeChild].line = "\"" + endEL + "\": \"" + alphanum[(time) % stringLength] + "\"";


						}
						else if (endType == "xsd:int") {
							int size = static_cast <int> (elementos.size());
							elementos.push_back(content());

							string myElement = "<" + endEL + ">" + sss.str() + "</" + endEL + "> \n";
							elementos[size].line = myElement;

							int jsonSizeChild = static_cast <int> (jsonChild.size());
							jsonChild.push_back(content());
							jsonChild[jsonSizeChild].line = "\"" + endEL + "\": \"" + sss.str() + "\"";

						}

					}

				}
				else {
					size_t posSQ = conteudo[i].line.find(sq);
					if (posSQ != std::string::npos) {
						string strSQ = conteudo[i].line.substr(posSQ);
						sequence = true;
					}

				}

			}
			else {
				if (pos != std::string::npos) {
					string str = conteudo[i].line.substr(pos);
					size_t firstLim = str.find("name=");
					string first = str.substr(firstLim);

					string firtStr = first.erase(0, 6);

					size_t endStr = firtStr.find("\"");
					string end = firtStr.erase(endStr);
					complexTypeName = end;

					complex = true;
				}
			}
		}else{
			if (posXmlns != std::string::npos) {
				string strXmlns = conteudo[i].line.substr(posXmlns);
				size_t findXmlns = strXmlns.rfind("xmlns:");
				string found = strXmlns.substr(findXmlns);

				size_t del = found.find("targetNamespace");
				string eliminar = found.erase(del);
				xmlnsString = eliminar;

				size_t delXmlns = eliminar.find("=\"");
				string delXmlns1 = eliminar.erase(delXmlns);
			
				string findType = delXmlns1.erase(0,6);
				xmlnsType = findType;

				xmlns = true;
			}
		
		}
		

		i++;

	}

	infile.close();
	xmlFile.close();
	
	return 0;
}

int jsonFile() {
	printf("The JSON file will be created!\n");

	ofstream jsonFile;
	jsonFile.open("jsonFile.json");

	int jsonSize = static_cast <int> (jsonElements.size());

	for (int i = 0; i < jsonSize; i++) {
		jsonFile << jsonElements[i].line;
	}
	return 0;
}

int main(int argc, char *argv[]){
     
	int input;
	
	do{
		printf("Menu: \n 1 - Create a XML file \n 2 - Export the XML file to JSON \n 0 - Exit \nSelect an option:");

		cin >> input;

		if (argc == 2) {
			printf("The argument supplied is %s\n", argv[1]);
			file = argv[1];
		}
		else if (argc > 2) {
			printf("Too many arguments supplied.\n");
		}
		else {
			printf("At least one argument is expected.\n");
		}


		switch (input)
		{
		case 1:
			writeFile();
			break;
		case 2:
			jsonFile();
			break;
		default:
			break;
		}

	} while (input != 0);
	
	
	return 0;
}
