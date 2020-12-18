#include "testlib.h"
using namespace std;
string s[21];
int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);
    int h = inf.readInt();
    int w = inf.readInt();
    inf.readString();
    for (int i = 0; i < h; i++) {
        s[i] = inf.readString();
    }
    string t = ouf.readString();
    int x = 0, y = 0;
    if (t.length() != h + w - 2) quitf(_wa, "length %d does not match h=%d w=%d", t.length(), h, w);
    for (int i = 0; i < h + w - 2; i++) {
        if (t[i] == 'S') {
            x++;
        } else {
            y++;
        }
        if (x >= h) quitf(_wa, "i=%d: x out of bounds %s", i, t.c_str());
        if (y >= w) quitf(_wa,  "i=%d: y out of bounds %s", i, t.c_str());
        if (s[x][y] != '.') quitf(_wa, "i=%d: pos %d %d %s", i, x, y, t.c_str());
    }
    quitf(_ok, "%s", t.c_str());
    return 0;
}
