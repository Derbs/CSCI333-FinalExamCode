#include <iostream>
#include <ifstream>

int main(int argc, char** argv) {
  if(argc==3) {
    std::string line;

    std::ifstream reader (argv[2]);
    while(reader.good()) {
      getline(reader,line);
      // split function: loop through this for EVERY tweet.  
      std::list<std::string>* words = new std::list<std::string>();
      int pos = 0;
      int spacePos;
      while(line.find_first_of(' ',pos)!=std::string::npos) {
        spacePos = line.find_first_of(' ',pos);
        words->push_back(line.substr(pos,spacePos));
        std::cout<<words.back()<<std::endl;
        pos = spacePos+1;
      }
      //then, add all values to a map of string int pairs, increasing word count as duplicates arise.
    }
  }
}
std::list<std::string>* split(std::string line) {
  std::list<std::string>* words = new std::list<std::string>();
  int pos = 0;
  int spacePos;
  while(line.find_first_of(' ',pos)!=std::string::npos) {
    spacePos = line.find_first_of(' ',pos);
    words->push_back(line.substr(pos,spacePos));
    std::cout<<words.back()<<std::endl;
    pos = spacePos+1;
  }
}
