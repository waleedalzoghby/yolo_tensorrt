#include "dataReader.h" 
#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;

namespace Tn
{
    list<string> readFileList(const string& fileName)
    {
        ifstream file(fileName);  
        if(!file.is_open())
        {
            cout << "read file list error,please check file :" << fileName << endl;
            exit(-1);
        }

        string strLine;  
        list<string> files;
        while( getline(file,strLine) )                               
            files.push_back(strLine);

        file.close();

        return files;
    }

    list<Source> readLabelFileList(const string& fileName)
    {
        ifstream file(fileName);  
        if(!file.is_open())
        {
            cout << "read file list error,please check file :" << fileName << endl;
            exit(-1);
        }

        string strLine;  
        list<Source> result;
        while(!file.eof())
        {
            Source data;
            file >> data.fileName >> data.label;
            result.emplace_back(data);
        } 

        return result;
    }

    vector<string> split(const string& str, char delim)
    {
        stringstream ss(str);
        string token;
        vector<string> container;
        while (getline(ss, token, delim)) {
            container.push_back(token);
        }

        return container;
    }

    // vector<string> split(string str, string pat) 
    // { 
    //     vector<string> bufStr; 
    //     while (true) 
    //     { 
    //         int index = str.find(pat); 
    //         string subStr = str.substr(0, index); 
    //         if (!subStr.empty()) 
    //             bufStr.push_back(subStr); 
    //         str.erase(0, index + pat.size()); 
    //         if (index == -1) 
    //             break; 
    //     } 
    //     return bufStr; 
    // }

    std::tuple<std::list<std::string>, std::list<std::vector<Bbox>>> readObjectLabelNewFileList(const string& fileName, const std::string& datasetPath)
    {
        list<string> fileList;
        list<vector<Bbox>> bBoxes;

        ifstream file(fileName);  
        if(!file.is_open())
        {
            cout << "read file list error,please check file :" << fileName << endl;
            exit(-1);
        }

        string strLine;
        int lines_to_skip = 3;
        int count = 0;
        string splitter = ",\"";
        while( getline(file,strLine) )                               
        { 
            string processed_line = "";
			count++;

            if(count <= lines_to_skip)
			{
				continue;
			}

			std::size_t found = strLine.find(splitter);
			string current_file_name;

            // vector<string> line=split(strLine, '\n');
            // if(line.size() < 1)
            //     continue;
            // vector<string> strs=split(line[0], ' ');  
            if (found!=std::string::npos)
            {
                std::string file_info = strLine.substr (0,found);
				std::string boxes_str = strLine.substr (found+1);
				std::vector<std::string> results;
				boost::split(results, file_info, [](char c){return c == ',';});
                // results = split(file_info, ',');
                for (size_t i = 0; i < results.size(); i++)
				{
					if(i == 0)
					{
						current_file_name = results[i];
					}

					// processed_line+=results[i];
					// processed_line+=",";
					// cout<<results[i]<<endl;
				}

                boost::split(results, boxes_str, boost::is_any_of("]\"[")); // output: class, 1565, 783, 103, 70
                std::vector<std::string> nums;
				std::vector<std::string> boxes;
                vector<Bbox> truthboxes;
                if(results.size()>0) truthboxes.reserve(results.size());
				for (size_t i = 0; i < results.size(); i++)
				{
					boost::split(nums, results[i], [](char c){return c == ',';});
					
					if(nums.size() == 5 && nums[0] != ""&& nums[1] != ""&& nums[2] != ""&& nums[3] != ""&& nums[4] != "")
					{
                        Bbox truthbox;
                        truthbox.classId = stoi(nums[0]);
                        truthbox.left = stof(nums[1]);
                        truthbox.top = stof(nums[2]);
                        truthbox.right = truthbox.left + stof(nums[3]);
                        truthbox.bot = truthbox.top + stof(nums[4]);
                        truthboxes.push_back(truthbox);
					}
				}

                if(results.size()>0)
                {
                    fileList.emplace_back(datasetPath+current_file_name);
                    bBoxes.emplace_back(truthboxes);
                }
            }    

            // int idx = 0;
            // string dataName=strs[idx++];  

            // int trueBoxCount = (strs.size() - 1)/2;
            // vector<Bbox> truthboxes;
            // truthboxes.reserve(trueBoxCount);
            // for (int i = 0 ;i < trueBoxCount ;++i)
            // {
            //     //class
            //     string classId = strs[idx++];
                
            //     //bbox Length
            //     int length = strs[idx].length();
            //     //remove bracket [ ]
            //     string bbox = strs[idx++].substr(1,length-2);

            //     vector<string> strs_txt = split(bbox, ','); 
            //     Bbox truthbox;
            //     truthbox.classId = stoi(classId);
            //     truthbox.left = stof(strs_txt[0]);
            //     truthbox.top = stof(strs_txt[1]);
            //     truthbox.right = truthbox.left + stof(strs_txt[2]);
            //     truthbox.bot = truthbox.top + stof(strs_txt[3]);

            //     truthboxes.push_back(truthbox);
            // }
            
            // fileList.emplace_back(dataName);
            // bBoxes.emplace_back(truthboxes);
        } 

        file.close();

        return make_tuple(move(fileList),move(bBoxes));
    }

    std::tuple<std::list<std::string>, std::list<std::vector<Bbox>>> readObjectLabelFileList(const string& fileName)
    {
        list<string> fileList;
        list<vector<Bbox>> bBoxes;

        ifstream file(fileName);  
        if(!file.is_open())
        {
            cout << "read file list error,please check file :" << fileName << endl;
            exit(-1);
        }

        string strLine;  
        while( getline(file,strLine) )                               
        { 
            vector<string> line=split(strLine, '\n');
            if(line.size() < 1)
                continue;
            vector<string> strs=split(line[0], ' ');            

            int idx = 0;
            string dataName=strs[idx++];  

            int trueBoxCount = (strs.size() - 1)/2;
            vector<Bbox> truthboxes;
            truthboxes.reserve(trueBoxCount);
            for (int i = 0 ;i < trueBoxCount ;++i)
            {
                //class
                string classId = strs[idx++];
                
                //bbox Length
                int length = strs[idx].length();
                //remove bracket [ ]
                string bbox = strs[idx++].substr(1,length-2);

                vector<string> strs_txt = split(bbox, ','); 
                Bbox truthbox;
                truthbox.classId = stoi(classId);
                truthbox.left = stof(strs_txt[0]);
                truthbox.top = stof(strs_txt[1]);
                truthbox.right = truthbox.left + stof(strs_txt[2]);
                truthbox.bot = truthbox.top + stof(strs_txt[3]);

                truthboxes.push_back(truthbox);
            }
            
            fileList.emplace_back(dataName);
            bBoxes.emplace_back(truthboxes);
        } 

        file.close();

        return make_tuple(move(fileList),move(bBoxes));
    }
}