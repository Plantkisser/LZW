#include <iostream>
#include "Vocabulary.h"
#include "Vector.h"
#include <fstream>
#include <cstring>
#define CNT 100

void convert (Vector<char>&, const Vector<int>&, int max);
int get_pow (int num);

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		std:: cout << "Wrong argument" << std:: endl;
		return 0;
	}


	std:: ofstream ostrm;
	

	

	for (int i = 1; i < argc; ++i)
	{
		char* name = new char[strlen(argv[i] + 2)];
		strcpy(name, argv[i]);

		name[strlen(argv[i])] = 'Z';
		name[strlen(argv[i]) + 1] = '\0';


		ostrm.open(name, std::ios_base:: trunc);
		if (ostrm.is_open() == false)
			return 0;

		Vocabulary voc;
		Vector<int> code;


		std:: ifstream inp(argv[i]);

		if (inp.is_open() != true)
		{
			std:: cout << "Cannot open file: " << argv[i] << std:: endl; 
			return 0;
		}



		char* buf = new char [CNT + 1];


		int max = 256;
		do
		{
			inp.read(buf, CNT);
			//std:: cout << "*" << std:: endl;

			int cnt = inp.gcount();
			//std:: cout << cnt << std:: endl;
			for(int i = 0; i < cnt; ++i)
			{
				//std:: cout << "*" << std:: endl;			
				int num = voc.insert(buf[i]);
				max = num > max ? num : max;
				if (num >= 0) code.push_back(num);
			}
			//std:: cout << "*" << std:: endl;		

		} while (inp.gcount() == CNT);

		code.push_back(voc.result());
		code.push_back(0);

		inp.close();
	

//=============================================================================//

		Vector<char> final;

		convert(final, code, max);






//================================================================================//
		
		ostrm << get_pow(max);


		for (int j = 0; j < final.size(); ++j)
			ostrm << static_cast <char>(final[j]);

		ostrm.close();
	}



	
	return 0;
}



int get_pow (int num)
{
	int pow = 0;
	int a = 1;
	while (a < num)
	{
		a *= 2;
		pow++;
	}
	return pow;
}



void convert (Vector<char>& dest, const Vector<int>& src, int max)
{
	int k = get_pow(max);



	int byte_ind = 0;

	dest.reserve((k * src.size()) / (sizeof(char) * 8) + 1);
	dest.init(0);

	int size = src.size();
	for (int i = 0; i < size; ++i)
	{
		
		int remain = k;
		int numb = src[i];


		while(remain > 0)
		{

			int rt_offset = sizeof(char) * 8 - byte_ind % (sizeof(char) * 8);
			if (remain <= rt_offset)
			{
				
				numb <<= rt_offset - remain;

				dest[byte_ind / (sizeof(char) * 8)] |= numb;

				byte_ind += remain;

				remain = 0;
			}
			else
			{
				int cpy = numb >> (remain - rt_offset);
				dest[byte_ind / (sizeof(char) * 8)] |= cpy;

				cpy <<= remain - rt_offset;

				numb -= cpy;

				byte_ind += rt_offset;
				remain -=rt_offset;

			}
		}


	}
}