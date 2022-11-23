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
    : freshnessCount(freshnessCount) {
      std::map<std::string, info> files = files;
    }

template <typename T>
Cache<T>::~Cache() {
  // need to look up how to destroy a binary file
  // No need to focus on text files here
}

template <typename T>
std::string Cache<T>::getText(std::string filepath) {
  // How to go about determining fresh copies??
  if (files.find(filepath) == files.end() ||
      files[filepath].freshness == freshnessCount) {
    // first time, not stored in the map yet OR file not fresh
    // Open, read, save contents
    std::ifstream infile;
    std::stringstream streamText;
    std::string text;
    infile.open(filepath);
    while (getline(infile, text)) {
      streamText << text;
    }
    infile.close();

    text = streamText.str();
    files[filepath].freshness++;
    files[filepath].text = text;

  } else if (files[filepath].freshness < freshnessCount ||
             files[filepath].freshness > freshnessCount) {
    // exists in map, Still fresh OR exceeds freshnessCount
    // return contents saved in files
    files[filepath].freshness++;
  }
  return files[filepath].text;
}

template <typename T>
char* Cache<T>::getBinary(std::string filepath) {
  std::streampos size;
  char* memBlock;
  std::ifstream inBinaryFile(filepath, std::ios::in | std::ios::binary | std::ios::ate);

  if (inBinaryFile.is_open()) {
    size = inBinaryFile.tellg();
    memBlock = new char[size];
    inBinaryFile.seekg(0, std::ios::beg);
    inBinaryFile.read(memBlock, size);
    inBinaryFile.close();

    for (int i = 0; i < size; i++) {
      std::cout << (short)memBlock[i];
    }

    delete[] memBlock;

  } else {
    std::cout << "Unable to open file";
  }

  return 0;
}

template <typename T>
bool Cache<T>::isCached(std::string filepath) {
  return true;
}

template <typename T>
unsigned int Cache<T>::getFreshness(std::string filepath) {
  return 1;
}

template <typename T>
void Cache<T>::markFileFresh(std::string filepath) {
}

template <typename T>
void Cache<T>::purgeCache() {}

template <typename T>
std::string Cache<T>::topFile() {
  return "Placeholder";
}

template <typename T>
std::string Cache<T>::getStats() {
  return "Placeholder";
}

int main() {
  // For compilation checks
  return 0;
}