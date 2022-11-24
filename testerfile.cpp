#include <iostream>

#include "cacheCDN.h"

using namespace std;

int main() {
  ICS45C::CDN::Cache myCache(3);

  cout << "p5-text.txt:\n";
  cout << myCache.getText("p5-text.txt") << '\n';

  cout << '\n';

//   cout << "p5-binary.bin:\n";
//   char* bin = myCache.getBinary("p5-binary.bin");
//   while (*bin) {
//     cout << hex << (short)*bin;
//     bin++;
//   }

//   cout << "\n\n";

//   cout << "isCached(\"blah\"): " << myCache.isCached("blah") << '\n';
//   cout << "isCached(\"p5-text.txt\"): " << myCache.isCached("p5-text.txt")
//        << '\n';

//   cout << '\n';

//   cout << "getFreshness(\"p5-text.txt\"): "
//        << myCache.getFreshness("p5-text.txt") << '\n';
//   myCache.getText("p5-text.txt");
//   cout << "getFreshness(\"p5-text.txt\"): "
//        << myCache.getFreshness("p5-text.txt") << '\n';

//   cout << '\n';

//   cout << "Marking 'p5-text.txt' as fresh...\n";
//   myCache.markFileFresh("p5-text.txt");
//   cout << "getFreshness(\"p5-text.txt\"): "
//        << myCache.getFreshness("p5-text.txt") << '\n';

//   cout << '\n';

//   cout << "Purging cache...\n";
//   myCache.purgeCache();
//   cout << "isCached(\"p5-text.txt\"): " << myCache.isCached("p5-text.txt")
//        << '\n';

//   cout << '\n';

//   cout << "Top file: " << myCache.topFile() << '\n';

//   cout << '\n';

//   cout << myCache.getStats();

  return 0;
}