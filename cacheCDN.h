#ifndef __CACHECDN_H__
#define __CACHECDN_H__

/* Add any includes here! */
#include <iostream>
#include <map>
#include <vector>

namespace ICS45C {
namespace CDN {

struct Info {
  std::string text;
  unsigned int freshness;
  unsigned int accessed;
  unsigned int totalFreshness;
};

/* Define your class here! */
class Cache {
 private:
  unsigned int freshnessCount;
  std::map<std::string, Info> files;
  std::vector<std::string> fileNames;

 public:
  Cache(unsigned int freshnessCount);
  ~Cache();
  unsigned int fresh(std::string filepath);
  void printFreshness(std::string filepath);
  std::string getText(std::string filepath);
  char* getBinary(std::string filepath);
  bool isCached(std::string filepath);
  unsigned int getFreshness(std::string filepath);
  void markFileFresh(std::string filepath);
  void purgeCache();
  std::string topFile();
  std::string getStats();
};

}  // namespace CDN
}  // namespace ICS45C

#endif  // __CACHECDN_H__