#include "cacheCDN.h"

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

/* Implement any functions and methods here! */
using namespace ICS45C::CDN;
using std::ofstream;

template <typename T>
Cache<T>::Cache(unsigned int freshnessCount)
    : freshnessCount(freshnessCount) files(files) {}

template <typename T>
Cache<T>::~Cache() {
  // Do I just clear the vector?
  files.clear();
}

template <typename T>
std::string Cache<T>::getText(std::string filepath) {
  // How to go about determining fresh copies??
  ifstream infile;
  string text;
  infile.open(filepath);
  while (getline(infile, text)) {
    infile >> text;
  }
  infile.close();
  return infile;
}

template <typename T>
char* Cache<T>::getBinary(std::string filepath) {
  std::streampos size;
  char* memBlock;
  ifstream inBinaryFile(filepath, ios::in | ios::binary | ios::ate);

  if (inBinaryFile.is_open()) {
    size = inBinFile.tellg();
    memblock = new char[size];
    inBinFile.seekg(0, ios::beg);
    inBinFile.read(memblock, size);
    inBinFile.close();

    for (int i = 0; i < size; i++) {
      cout << (short)memblock[i];
    }
  

    delete[] memblock;

  } else {
    cout << "Unable to open file";
  }

  return 0;
}

template <typename T>
bool Cache<T>::isCached(std::string filepath) {}

template <typename T>
unsigned int Cache<T>::getFreshness(std::string filepath) {}

template <typename T>
void Cache<T>::markFileFresh(std::string filepath) {}

template <typename T>
void Cache<T>::purgeCache() {}

template <typename T>
std::string Cache<T>::topFile() {}

template <typename T>
std::string Cache<T>::getStats() {}