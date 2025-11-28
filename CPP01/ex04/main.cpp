/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcotonea <mcotonea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:30:55 by mcotonea          #+#    #+#             */
/*   Updated: 2025/06/18 09:39:32 by mcotonea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "The number of arguments must be 4." << std::endl;
		return (1);
	}

	std::string filename, s1, s2;

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	
	std::ifstream InFile(filename.c_str());
	if (!InFile.is_open()){
		std::cerr << "File " << filename << " could not be opened" << std::endl;
		return 1;
	}

	if (s1.empty()){
		std::cerr << "The string to be replaced cannot be empty." << std::endl;
		return 1;
	}
	
	std::ofstream OutFile((filename + ".replace").c_str());
	if (!OutFile.is_open()){
		std::cerr << "The outfile could not be created." << std::endl;
		InFile.close();
		return 1;
	}
	if (s1 == s2){
		std::string line;
		while (std::getline(InFile, line))
		{
			OutFile << line << std::endl;
		}
		return 0;
	}
	else {
		std::string line;
		while (std::getline(InFile, line)){
			std::size_t pos = 0;
			while ((pos = line.find(s1, pos)) != std::string::npos){
				line.erase(pos, s1.length());
				line.insert(pos, s2);
				pos += s2.length();
			}
			OutFile << line << std::endl;
		}
	}
	InFile.close();
	OutFile.close();
	return 0;
}