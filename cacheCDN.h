#ifndef __CACHECDN_H__
#define __CACHECDN_H__

/* Add any includes here! */
#include <iostream>
#include <map>

namespace ICS45C {
namespace CDN {

struct info {
  std::string text;
  unsigned int freshness = 0;
};

/* Define your class here! */
template <typename T>
class Cache {
 private:
  unsigned int freshnessCount = 0;
  std::map<std::string, info> files;

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