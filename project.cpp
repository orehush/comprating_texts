/*
 * project.cpp
 * 
 * Program searches all files according to pattern (const FILES_PATTERN).
 * Reads texts from files and compares these texts.
 * 
 * input data: all text from files, whose searched by the pattern
 * 
 * output: output result in console (or file) from comparing of all texts.
 * 
 * requirements: g++ compiler
 * enviroment: Linux Debian / Ubuntu
 * 
 * @authors: Oleksandr Rehush, Vasyl Poshtar
 * @version 1.1 21/11/2015
 * 
 */

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <glob.h>

#define FILES_PATTERN "./*.txt"
#define HUNDRED 100
#define SPACE ' '

using namespace std;

typedef map <string, double> str_double;
typedef pair <string, int> pair_str_int;


int length_of_repeats_elements(int length_text, int length_repeats_elem)
{
	// amount of repeats elements is equals to length of text 
	// minus (n - 1), where n - length of repeats 
	return length_text - (length_repeats_elem - 1);
}


class TextManager
{
private:

	string _text;
	str_double _compared_elements;
	
	int _count_elements_in_text(string elements)
	{
		// the number of similar elements in this->_text
		int count = 0;
		int pos = -1;
		do {
			// if elements not in text, method find returns -1,
			// else positions of begin elements
			pos = this->_text.find(elements, pos+1);
			if (pos == -1)
				break;
			count++;
		} while (true);
			
		return count;
	}
	
	string _to_lower_case(string text)
	{
		// converts string to lower case
		for (int i = 0; i < text.length(); i++)
			text[i] = tolower(text[i]);
		return text;
	}
	
public:

	TextManager (string text)
	{
		this->_text = this->_to_lower_case(text);
	}
	
	string get_text()
	{
		return this->_text;
	}
	
	str_double get_map()
	{
		return this->_compared_elements;
	}
	
	void count_all_repetitions(int n)
	{
		// spliting this->_text on elements and count all repetitions
		// in string by length n
		string text = this->_text;
		for (int i = 0; i < length_of_repeats_elements(text.length(), n); i++)
		{
			// get part of text
			string part_of_text = text.substr(i, n);
			// count repeats parts in all text
			int repeats_of_elements = this->_count_elements_in_text(part_of_text);
			
			pair_str_int pair_of_text_and_repeats = pair_str_int(
				part_of_text,
				repeats_of_elements
			);
			
			// insert result in map
			this->_compared_elements.insert(pair_of_text_and_repeats);
		}
	}

};

class CompareMapsManager
{

private:
	str_double _map1;
	str_double _map2;
	int _length_text1;
	int _length_text2;
	
	void _normalize()
	{
		// normalize map: divides the number of repetitions of elements 
		// on the length of the string
		str_double::iterator i;
		
		for (i = this->_map1.begin(); i != this->_map1.end(); i++)
			i->second /= this->_length_text1; 

		for (i = this->_map2.begin(); i != this->_map2.end(); i++)
			i->second /= this->_length_text2; 
	}

public:
	CompareMapsManager (str_double map1, str_double map2, 
						int length_text1, int length_text2, 
						int length_for_comparing)
	{
		this->_map1 = map1;
		this->_map2 = map2;
		this->_length_text1 = length_of_repeats_elements(
			length_text1, length_for_comparing
		);
		this->_length_text2 = length_of_repeats_elements(
			length_text2, length_for_comparing
		);

		// normalize the length of repetitions
		this->_normalize();
	}
	
	double count_percent_comparing()
	{
		// search similar items in maps 
		// and calculation of percent similarity maps
		double percent = 0;
		
		str_double::iterator i;

		for (i = this->_map1.begin(); i != this->_map1.end(); i++)
		{
			// search in map2 item from map1,
			// if it exists, the percent increases 
			// to the minimum value of the two maps
			percent += this->_map2.find(i->first)->second > 0 ? 
					   min(this->_map2.find(i->first)->second, i->second): 0;
		}
		return percent * HUNDRED;
	}
};


/*
void print_map(str_double elements)
{
	str_double::iterator i;
	for (i = elements.begin(); i != elements.end(); i++)
	{
		cout << i->first << " : " << i->second << endl;
	}
}
*/

vector <string> get_all_files(const string& pattern)
{
	// copypaste form stackoverflow
	// http://stackoverflow.com/questions/8401777/simple-glob-in-c-on-unix-system
	
	// search and return names of all files by pattern
    glob_t glob_result;
    glob(pattern.c_str(), GLOB_TILDE, NULL, &glob_result);
    vector<string> files;
    
    for(int i = 0; i < glob_result.gl_pathc; i++)
        files.push_back(string(glob_result.gl_pathv[i]));
    globfree(&glob_result);
    return files;
}


string remove_space_from_str(string str)
{
	// return string without spaces
	string::iterator end_pos = remove(str.begin(), str.end(), SPACE);
	str.erase(end_pos, str.end());
	return str;	
}


vector <string> get_all_texts_in_dir()
{
	/*
	 * Opening all files by FILES_PATTERN.
	 * File valid if opened and no empty.
	 * Return vector of string with all text from files.
	 */
	vector <string> texts;
	vector <string> files = get_all_files(FILES_PATTERN);
	
	// check if any files is exists by FILES_PATTERN
	if (!files.size())
	{
		cout << "Not files for comparing with pattern: " 
			 << FILES_PATTERN << endl;
		return texts;
	}
	
	ifstream input_text;
	
	for (int i = 0; i < files.size(); i++)
	{
		// open file
		input_text.open(files[i].c_str());
		
		// check if opening without error
		if (!input_text)
		{
			cout << "Could not open file " << files[i] << endl;
			continue;
		}
		cout << "Reading file: " << files[i] << endl;
		
		// reads file
		string text = "", row, row_without_space;
		bool file_is_empty = true;
		
		while (!input_text.eof())
		{
			getline(input_text, row, '\n');
			
			row_without_space = remove_space_from_str(row);
			
			if (row_without_space != "")
			{
				text += row;
				file_is_empty = false;
			}
		}
		input_text.close();
		// check file if no empty
		if (file_is_empty)
		{
			cout << "File "<< files[i] << " is empty\n";
			continue;
		}
		cout << "--> text of file: " << text << endl;
		cout << "\n----------------------------------\n"; 
		
		texts.push_back(text);
	}
	return texts;
}

void print_result(ostream& output, int text1, int text2, double percent)
{
	// print result to output stream
	output << "Percent of comparing text " 
		  << text1 << " with text " << text2 << " : "<< percent << endl;
}

int main()
{
	vector <string> texts = get_all_texts_in_dir();
	
	string out_filename;
	ofstream out_file;
	bool out_in_file = false;
	int length_word_for_comparing;

	cout << "Enter a step for comparing: ";
	cin >> length_word_for_comparing;
	
	cout << "Enter a filename for output (or Enter 0 for output in console): ";
	cin >> out_filename;
	if (out_filename != "0")
	{
		out_file.open(out_filename.c_str());
		if (out_file)
			out_in_file = true;
	}

	// each text compares with others
	for (int i = 0; i < texts.size(); i++)
		for (int j = i + 1; j < texts.size(); j++)
		{
			TextManager text_manager1(texts[i]);
			TextManager text_manager2(texts[j]);
			
			text_manager1.count_all_repetitions(length_word_for_comparing);
			text_manager2.count_all_repetitions(length_word_for_comparing);
			
			CompareMapsManager compare_maps_mngr(
				text_manager1.get_map(),
				text_manager2.get_map(),
				text_manager1.get_text().length(),
				text_manager2.get_text().length(),
				length_word_for_comparing
			);
			if (out_in_file)
				print_result(out_file, i, j, 
							 compare_maps_mngr.count_percent_comparing());
			else
				print_result(cout, i, j, 
							 compare_maps_mngr.count_percent_comparing());
		}
	if (out_in_file)
		cout << "Result printed to file: " << out_filename << endl;
	

	return 0;
}
