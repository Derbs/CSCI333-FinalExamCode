#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <sstream>
using std::string;

int main(int argc, char** argv) {
  if(argc == 4) {
    int threshold;
    std::string threshRaw (argv[3]);
    std::stringstream converter (threshRaw);
    if(!(converter >> threshold)) threshold = 0;
    std::cout<<"The threshold is "<<threshold<<std::endl;
    std::ifstream reader (argv[2]);
    std::map<std::string,int> names;
    std::string curName;
    int oldScore;
    while(reader.good()) {
      curName.clear(); 
      std::getline(reader, curName);
      if(names.count(curName)!=0) {
        oldScore = names[curName];
	names[curName] = oldScore + 1;
      }
      else {
	std::pair <string,int> nxt (curName,1);
        names.insert(nxt);
      }
    }
    reader.close();
    std::map<std::string,int>::iterator it;
    std::cout<<"Nice Folk:"<<std::endl;
    for(it = names.begin(); it != names.end(); it++) {
      if(it->second>threshold) {
        std::cout<<it->first<<std::endl;
      }
    }
    std::cout<<std::endl<<"Naughty Individuals:"<<std::endl;
    for(it = names.begin(); it != names.end(); it++) {
      if(it->second<=threshold) {
        std::cout<<it->first<<std::endl;
      }
    }
  }
  return 0;
}
