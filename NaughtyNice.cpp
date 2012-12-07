#include <iostream>
#include <fstream>
#include <map>
#include <utility>
#include <sstream>
using std::string;

int main(int argc, char** argv) {
  if(argc == 4) {

    std::cout<<"No sef fault yet"<<std::endl;
    int threshold;
    std::string threshRaw (argv[3]);
    std::cout<<"No sef fault yet"<<std::endl;
    std::stringstream converter (threshRaw);
    if(!(converter >> threshold)) threshold = 0;
    std::cout<<"No sef fault yet"<<std::endl;
    std::ifstream reader (argv[2]);
    std::cout<<"No sef fault yet"<<std::endl;
    std::map<std::string,int> names;
    while(reader.good()) {
      std::string curName ( (char*)reader.get());
      if(names.count(curName)) {
        std::pair <string,int> nxt (curName,names[curName]);
        nxt.second += 1;
	names.insert(nxt);
      }
      else {
	std::pair <string,int> nxt (curName,1);
        names.insert(nxt);
      }
    }
    reader.close();
    
    std::cout<<"No sef fault yet"<<std::endl;
    std::map<std::string,int>::iterator it;
    std::cout<<"Nice Folk:"<<std::endl;
    for(it = names.begin(); it != names.end(); it++) {
      if(it->second>threshold) std::cout<<it->first<<std::endl;
    }
    std::cout<<"Naughty Individuals:"<<std::endl;
    for(it = names.begin(); it != names.end(); it++) {
      if(it->second<=threshold) std::cout<<it->first<<std::endl;
    }
  }
  return 0;
}
