#include <fstream>
#include <iostream>

#include "cacheCDN.h"

using namespace std;

int main() {
  ICS45C::CDN::Cache myCache(2);
  string file = "p5-text.txt";
//   cout << myCache.getFreshness(file) << endl;

  ofstream outFile;
  outFile.open(file);
  outFile << "hello";
  outFile.close();
  myCache.getText(file);
//   cout << myCache.getFreshness(file) << endl;
//   cout << myCache.getFreshness(file) << endl;
  myCache.purgeCache();
//   cout << myCache.getFreshness(file) << endl;
  //   for (int i = 0; i < 23; i++) {
  //     myCache.getText(file);
  //     // cout << "Freshness: " << myCache.fresh(file) << endl;
  //   }
  //   //   cout << myCache.getStats();
  //   myCache.purgeCache();
  //   myCache.getText(file);
  //   //   cout << myCache.getStats();
  //   myCache.purgeCache();
  //   myCache.getText(file);

  //   cout << myCache.getStats();

  //   myCache.markFileFresh(file);
  //     cout << myCache.getFreshness(file) << endl;

  // //   cout << "p5-binary.bin:\n";
  // //   char* bin = myCache.getBinary("p5-binary.bin");
  // //   while (*bin) {
  // //     cout << hex << (short) *bin;
  // //     bin++;
  // //   }

  // //   cout << "\n\n";

  //   cout << "isCached(\"blah\"): " << myCache.isCached("blah") << '\n';
  //   cout << "isCached(\"p5-text.txt\"): " << myCache.isCached("p5-text.txt")
  //   << '\n';

  //   cout << '\n';

  //   cout << "getFreshness(\"p5-text.txt\"): " <<
  //   myCache.getFreshness("p5-text.txt") << '\n';
  //   myCache.getText("p5-text.txt");
  //   cout << "getFreshness(\"p5-text.txt\"): " <<
  //   myCache.getFreshness("p5-text.txt") << '\n';

  //   cout << '\n';

  //   cout << "Marking 'p5-text.txt' as fresh...\n";
  //   myCache.markFileFresh("p5-text.txt");
  //   cout << "getFreshness(\"p5-text.txt\"): " <<
  //   myCache.getFreshness("p5-text.txt") << '\n';

  //   cout << '\n';

  //   cout << "Purging cache...\n";
  //   myCache.purgeCache();
  //   cout << "isCached(\"p5-text.txt\"): " << myCache.isCached("p5-text.txt")
  //   << '\n';

  //   cout << '\n';

  //   cout << "Top file: " << myCache.topFile() << '\n';

  //   cout << '\n';

  //   cout << myCache.getStats();

  return 0;
}