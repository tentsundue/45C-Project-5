#ifndef __CACHECDN_H__
#define __CACHECDN_H__

/* Add any includes here! */
#include <iostream>
#include <map>

namespace ICS45C {
namespace CDN {

struct Info {
  std::string text;
  unsigned int freshness;
  unsigned int accessed;
};

/* Define your class here! */
class Cache {
 private:
  unsigned int freshnessCount;
  std::map<std::string, Info> files;

 public:
  Cache(unsigned int freshnessCount);
  ~Cache();
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