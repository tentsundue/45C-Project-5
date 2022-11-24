#include "cacheCDN.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using std::ofstream;

/* Implement any functions and methods here! */
namespace ICS45C {
namespace CDN {

Cache::Cache(unsigned int freshnessCount) : freshnessCount(freshnessCount) {
  std::map<std::string, Info> files = files;
}

Cache::~Cache() {
  // need to look up how to destroy a binary file
  // No need to focus on text files here
}

std::string Cache::getText(std::string filepath) {
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

    files[filepath].text = text;
    files[filepath].accessed++;
  }
  files[filepath].freshness++;
  return files[filepath].text;
}

char* Cache::getBinary(std::string filepath) {
  std::streampos size;
  char* memBlock;
  std::ifstream inBinaryFile(filepath,
                             std::ios::in | std::ios::binary | std::ios::ate);

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

bool Cache::isCached(std::string filepath) {
  for (auto file : files) {
    if (filepath == file.first) {
      return true;
    }
  }
  return false;
}

unsigned int Cache::getFreshness(std::string filepath) {
  unsigned int currFreshness = files[filepath].freshness;
  if (currFreshness >= freshnessCount || currFreshness == 0) {
    return 0;
  } else {
    return freshnessCount - currFreshness;
  }
}

void Cache::markFileFresh(std::string filepath) {
  if (files.find(filepath) != files.end()) {
    // exists
    files[filepath].freshness = 0;
  }
}

void Cache::purgeCache() { files.clear(); }

std::string Cache::topFile() {
  // Info empty = {"None", 0};
  unsigned int size = files.size();
  std::vector<unsigned int> allFreshness;

  for (auto file : files) {
    allFreshness.push_back(file.second.freshness);
  }

  unsigned int max =
      *std::max_element(allFreshness.begin(), allFreshness.end());

  if (size == 0) {
    return "";
  } else {
    for (auto file : files) {
      if (max == file.second.freshness) {
        return file.first;
      }
    }
  }
}

std::string Cache::getStats() {
  std::stringstream Stats;
  unsigned int totalReqs = 0;
  unsigned int totalFiles = 0;
  unsigned int totalReads = 0;
  unsigned int size = files.size();
  std::string top = topFile();

  if (size != 0) {
    for (auto file : files) {
      totalReqs += file.second.freshness;
      totalFiles++;
      totalReads += file.second.accessed;
    }
  }
  unsigned int averageReqs = totalReqs / totalFiles;
  Stats << "Cache Stats\n";
  Stats << "----------\n";
  Stats << "Total requests: " << totalReqs << "\n";
  Stats << "Total Files requested: " << totalFiles << "\n";
  Stats << std::fixed;
  Stats << std::setprecision(2);
  Stats << "Average requests per file: " << averageReqs << "\n";
  Stats << "Top file: " << top << "(" << files[top].freshness << "requests)\n";
  Stats << "Total times read from disk: " << totalReads << "\n";
  Stats << "----------\n";
  return Stats.str();
}

int main() {
  // For compilation checks
  return 0;
}
}  // namespace CDN
}  // namespace ICS45C
