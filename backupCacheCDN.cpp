#include "cacheCDN.h"

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using std::max_element;
using std::ofstream;

/* Implement any functions and methods here! */
namespace ICS45C {
namespace CDN {

Cache::Cache(unsigned int freshnessCount) : freshnessCount(freshnessCount) {
  totalFiles = 0;
  totalRequests = 0;
  totalReads = 0;
}

Cache::~Cache() {
  // need to look up how to destroy a binary file
  // No need to focus on text files here
}
unsigned int Cache::fresh(std::string filepath) {
  return files[filepath].freshness;
}
std::string Cache::getText(std::string filepath) {
  if (files[filepath].freshness == freshnessCount) {
    files[filepath].freshness = 0;
  }
  if (files.find(filepath) == files.end() || files[filepath].freshness == 0) {
    // first time, not stored in the map yet OR file not fresh
    // Open, read, save contents
    std::ifstream infile;
    std::stringstream streamText;
    std::string text;
    infile.open(filepath);
    while (getline(infile, text)) {
      streamText << text + "\n";
    }
    infile.close();

    text = streamText.str();

    files[filepath].text = text;
    files[filepath].accessed++;
    totalReads++;
  }
  files[filepath].freshness++;
  files[filepath].totalFreshness++;
  totalRequests++;

  // Adding file to vector if it doesn't already exist
  if (freshTracker.find(filepath) == freshTracker.end()) {
    freshTracker[filepath]++;
  }
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
  unsigned int currFreshness = files[filepath].totalFreshness;

  if (currFreshness >= freshnessCount || currFreshness == 0) {
    return 0;
  } else {
    return freshnessCount - files[filepath].freshness;
  }
}

void Cache::printFreshness(std::string filepath) {
  std::cout << files[filepath].freshness << std::endl;
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

  if (size == 0) {
    return "";
  } else {
    for (auto file : files) {
      allFreshness.push_back(file.second.totalFreshness);
    }
    // unsigned int max =
    //     *std::max_element(allFreshness.begin(), allFreshness.end());
    unsigned int max =
        *max_element(std::begin(allFreshness), std::end(allFreshness));
    for (auto file : files) {
      if (max == file.second.totalFreshness) {
        return file.first;
      }
    }
  }
  return "";
}

std::string Cache::getStats() {
  std::stringstream Stats;
  std::string top = topFile();
  for (auto file : freshTracker) {
    totalFiles++;
  }
  float averageRequests = (totalFiles > 0) ? totalRequests / totalFiles : 0.00;
  Stats << "Cache Stats\n";
  Stats << "----------\n";
  Stats << "Total requests: " << (int)totalRequests << "\n";
  Stats << "Total files requested: " << (int)totalFiles << "\n";
  Stats << std::fixed;
  Stats << std::setprecision(2);
  Stats << "Average requests per file: " << averageRequests << "\n";
  Stats << "Top file: " << top << " (" << freshTracker[top] << " requests)\n";
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
